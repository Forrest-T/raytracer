#include "OpenCL.hpp"

#include "stdlib.h"
#include "stdio.h"

#include "scene_manager.hpp"
#include "cl_manager.hpp"
#include "SDL_helper.hpp"
#include "main.hpp"

using namespace Raytracer;
using glm::vec3;

int main() {
    screen = InitializeSDL(SCREEN_WIDTH, SCREEN_HEIGHT, false);

    Scene_Manager scene;
    scene.log_level = VERBOSE;
    //scene.loadBox();
    scene.loadModel("../../models/out");

    CL_Manager manager;
    manager.log_level = VERBOSE;
    manager.device_type = GPU;
    //manager.platform_choice = 1;
    //manager.device_type = ANY;
    manager.initialize();

    // TODO raytracing kernel
    cl_program program = manager.createProgram({
            "structs.cl",
            "math.cl",
            "raytrace.cl"});
    cl_kernel kernel = manager.createKernel(program, "tracePixel");

    cl_mem triangleBuf = clCreateBuffer(manager.context, CL_MEM_READ_ONLY, sizeof(Triangle)*SCREEN_WIDTH*SCREEN_HEIGHT, NULL, NULL);
    cl_mem outBuf = clCreateBuffer(manager.context, CL_MEM_WRITE_ONLY, sizeof(cl_float4)*SCREEN_WIDTH*SCREEN_HEIGHT, NULL, NULL);

    t = SDL_GetTicks();
    SDL_WarpMouse(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    //while (NoQuitMessageSDL()) {
    //    update();
    //    draw(manager, scene, kernel, triangleBuf, outBuf);
    //}
    update();
    draw(manager, scene, kernel, triangleBuf, outBuf);
    update();

    SDL_SaveBMP(screen, "screenshot.bmp");
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    return EXIT_SUCCESS;
}

void Raytracer::update() {
    int t2 = SDL_GetTicks();
    float dt = float(t2-t);
    t = t2;
    printf("Render time: %f ms\n",dt);

    int x, y;
    SDL_GetMouseState(&x, &y);
    x -= SCREEN_WIDTH/2;
    y -= SCREEN_HEIGHT/2;
    yaw += yaw_speed*x;
    R = {{1.f,0.f,0.f,0.f,0.f,1.f,0.f,0.f,0.f,0.f,1.f,0.f,0.f,0.f,0.f,1.f}};
    R.s[0] = R.s[10] = cos(yaw);
    R.s[2] = -(R.s[8] = sin(yaw));
    // TODO: pitch
    SDL_WarpMouse(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    // camera movement
    Uint8 *keystate = SDL_GetKeyState(0);
    if (keystate[SDLK_UP])
        light_pos.s[2] += light_speed*dt;
    if (keystate[SDLK_DOWN])
        light_pos.s[2] -= light_speed*dt;
    if (keystate[SDLK_LEFT])
        light_pos.s[0] -= light_speed*dt;
    if (keystate[SDLK_RIGHT])
        light_pos.s[0] += light_speed*dt;
    if (keystate[SDLK_w])
        camera.s[2] += camera_speed*dt;
    if (keystate[SDLK_a])
        camera.s[0] -= camera_speed*dt;
    if (keystate[SDLK_s])
        camera.s[2] -= camera_speed*dt;
    if (keystate[SDLK_d])
        camera.s[0] += camera_speed*dt;
    if (keystate[SDLK_SPACE])
        camera.s[1] -= camera_speed*dt;
    if (keystate[SDLK_LSHIFT])
        camera.s[1] += camera_speed*dt;
}

void Raytracer::draw(CL_Manager &manager, Scene_Manager &scene, cl_kernel &kernel, cl_mem &triangleBuf, cl_mem &outBuf) {
    scene.log_level = VERBOSE;
    cl_int error = CL_SUCCESS;
    cl_int width = SCREEN_WIDTH;
    cl_int height = SCREEN_HEIGHT;
    cl_float4 output[width*height];

    /* kernel parameters */
    manager.checkError(
            clEnqueueWriteBuffer(
                manager.queue, triangleBuf, CL_TRUE, 0,
                sizeof(Triangle)*width*height, &scene.triangles[0], 0, NULL, NULL),
            "failed to write to buffer\n");
    cl_int num_triangles = scene.triangles.size();
    Light light = {light_pos, light_col, light_glb};
    // camera already defined
    cl_int clfocal = focal;
    // R already defined
    // width already defined

    error  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &triangleBuf);
    error |= clSetKernelArg(kernel, 1, sizeof(cl_int), &num_triangles);
    error |= clSetKernelArg(kernel, 2, sizeof(Light), &light);
    error |= clSetKernelArg(kernel, 3, sizeof(cl_float4), &camera);
    error |= clSetKernelArg(kernel, 4, sizeof(cl_int), &clfocal);
    error |= clSetKernelArg(kernel, 5, sizeof(cl_float16), &R);
    error |= clSetKernelArg(kernel, 6, sizeof(cl_int), &width);
    error |= clSetKernelArg(kernel, 7, sizeof(cl_mem), &outBuf);
    manager.checkError(error, "failed to set kernel arguments\n");
    size_t global_size = width*height;

    manager.checkError(
            clEnqueueNDRangeKernel(
                manager.queue, kernel, 1, NULL, &global_size,
                NULL, 0, NULL, NULL),
            "failed to enqueue kernel");
    manager.checkError(
            clEnqueueReadBuffer(
                manager.queue, outBuf, CL_TRUE, 0, 
                sizeof(cl_float4)*width*height, output, 0, NULL, NULL),
            "failed to read buffer\n");

    if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
    for (int x = 0; x < SCREEN_WIDTH; x++)
        for (int y = 0; y < SCREEN_HEIGHT; y++)
            PutPixelSDL(screen, x, y, float4_to_vec3(output[x+y*SCREEN_WIDTH]));
    if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
    SDL_UpdateRect(screen, 0, 0, 0, 0);
}
