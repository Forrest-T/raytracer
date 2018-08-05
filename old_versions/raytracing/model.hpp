#ifndef model_hpp_
#define model_hpp_

#include <glm/glm.hpp>
#include <vector>
#include <string>
using glm::vec3;

typedef struct triangle {
public:
    vec3 v0;
    vec3 v1;
    vec3 v2;
    vec3 normal;
    vec3 color;
} Triangle;

static struct triangle data[30] = {
    {{-1.000000, 1.000000, 1.000000},   {1.000000, 1.000000, -1.000000},   {-1.000000, 1.000000, -1.000000}, {0.000000, -1.000000, 0.000000},  {0.150000, 0.750000, 0.150000}},
    {{-1.000000, 1.000000, 1.000000},   {1.000000, 1.000000, 1.000000},    {1.000000, 1.000000, -1.000000},  {0.000000, -1.000000, 0.000000},  {0.150000, 0.750000, 0.150000}},
    {{-1.000000, 1.000000, -1.000000},  {-1.000000, -1.000000, -1.000000}, {-1.000000, 1.000000, 1.000000},  {1.000000, 0.000000, -0.000000},  {0.750000, 0.150000, 0.750000}},
    {{-1.000000, 1.000000, 1.000000},   {-1.000000, -1.000000, -1.000000}, {-1.000000, -1.000000, 1.000000}, {1.000000, 0.000000, 0.000000},   {0.750000, 0.150000, 0.750000}},
    {{1.000000, -1.000000, -1.000000},  {1.000000, 1.000000, -1.000000},   {1.000000, 1.000000, 1.000000},   {-1.000000, 0.000000, 0.000000},  {0.750000, 0.750000, 0.150000}},
    {{1.000000, -1.000000, 1.000000},   {1.000000, -1.000000, -1.000000},  {1.000000, 1.000000, 1.000000},   {-1.000000, 0.000000, 0.000000},  {0.750000, 0.750000, 0.150000}},
    {{-1.000000, -1.000000, -1.000000}, {1.000000, -1.000000, -1.000000},  {-1.000000, -1.000000, 1.000000}, {0.000000, 1.000000, 0.000000},   {0.150000, 0.750000, 0.750000}},
    {{1.000000, -1.000000, -1.000000},  {1.000000, -1.000000, 1.000000},   {-1.000000, -1.000000, 1.000000}, {0.000000, 1.000000, -0.000000},  {0.150000, 0.750000, 0.750000}},
    {{-1.000000, -1.000000, 1.000000},  {1.000000, 1.000000, 1.000000},    {-1.000000, 1.000000, 1.000000},  {0.000000, 0.000000, -1.000000},  {0.750000, 0.750000, 0.750000}},
    {{-1.000000, -1.000000, 1.000000},  {1.000000, -1.000000, 1.000000},   {1.000000, 1.000000, 1.000000},   {0.000000, 0.000000, -1.000000},  {0.750000, 0.750000, 0.750000}},
    {{-0.045045, 0.405405, -0.589189},  {0.531532, 1.000000, -0.765766},   {-0.045045, 1.000000, -0.589189}, {-0.292826, 0.000000, -0.956166}, {0.750000, 0.150000, 0.150000}},
    {{-0.045045, 0.405405, -0.589189},  {0.531532, 0.405405, -0.765766},   {0.531532, 1.000000, -0.765766},  {-0.292826, 0.000000, -0.956166}, {0.750000, 0.150000, 0.150000}},
    {{0.531532, 0.405405, -0.765766},   {0.704504, 1.000000, -0.189189},   {0.531532, 1.000000, -0.765766},  {0.957826, 0.000000, -0.287348},  {0.750000, 0.150000, 0.150000}},
    {{0.531532, 0.405405, -0.765766},   {0.704504, 0.405405, -0.189189},   {0.704504, 1.000000, -0.189189},  {0.957826, 0.000000, -0.287348},  {0.750000, 0.150000, 0.150000}},
    {{0.704504, 0.405405, -0.189189},   {0.135135, 1.000000, -0.019820},   {0.704504, 1.000000, -0.189189},  {0.285121, -0.000000, 0.958492},  {0.750000, 0.150000, 0.150000}},
    {{0.704504, 0.405405, -0.189189},   {0.135135, 0.405405, -0.019820},   {0.135135, 1.000000, -0.019820},  {0.285121, 0.000000, 0.958492},   {0.750000, 0.150000, 0.150000}},
    {{0.135135, 0.405405, -0.019820},   {-0.045045, 0.405405, -0.589189},  {0.135135, 1.000000, -0.019820},  {-0.953400, 0.000000, 0.301709},  {0.750000, 0.150000, 0.150000}},
    {{-0.045045, 0.405405, -0.589189},  {-0.045045, 1.000000, -0.589189},  {0.135135, 1.000000, -0.019820},  {-0.953400, 0.000000, 0.301709},  {0.750000, 0.150000, 0.150000}},
    {{0.135135, 0.405405, -0.019820},   {0.531532, 0.405405, -0.765766},   {-0.045045, 0.405405, -0.589189}, {0.000000, -1.000000, -0.000000}, {0.750000, 0.150000, 0.150000}},
    {{0.135135, 0.405405, -0.019820},   {0.704504, 0.405405, -0.189189},   {0.531532, 0.405405, -0.765766},  {0.000000, -1.000000, 0.000000},  {0.750000, 0.150000, 0.150000}},
    {{-0.524324, -0.189189, -0.109910}, {0.045045, 1.000000, 0.066667},    {-0.524324, 1.000000, -0.109910}, {0.296209, 0.000000, -0.955123},  {0.150000, 0.150000, 0.750000}},
    {{-0.524324, -0.189189, -0.109910}, {0.045045, -0.189189, 0.066667},   {0.045045, 1.000000, 0.066667},   {0.296209, 0.000000, -0.955123},  {0.150000, 0.150000, 0.750000}},
    {{0.045045, -0.189189, 0.066667},   {-0.131532, 1.000000, 0.643243},   {0.045045, 1.000000, 0.066667},   {0.956166, -0.000000, 0.292826},  {0.150000, 0.150000, 0.750000}},
    {{0.045045, -0.189189, 0.066667},   {-0.131532, -0.189189, 0.643243},  {-0.131532, 1.000000, 0.643243},  {0.956166, 0.000000, 0.292826},   {0.150000, 0.150000, 0.750000}},
    {{-0.131532, -0.189189, 0.643243},  {-0.700901, 1.000000, 0.463063},   {-0.131532, 1.000000, 0.643243},  {-0.301709, 0.000000, 0.953400},  {0.150000, 0.150000, 0.750000}},
    {{-0.131532, -0.189189, 0.643243},  {-0.700901, -0.189189, 0.463063},  {-0.700901, 1.000000, 0.463063},  {-0.301709, 0.000000, 0.953400},  {0.150000, 0.150000, 0.750000}},
    {{-0.700901, -0.189189, 0.463063},  {-0.524324, -0.189189, -0.109910}, {-0.700901, 1.000000, 0.463063},  {-0.955649, 0.000000, -0.294508}, {0.150000, 0.150000, 0.750000}},
    {{-0.524324, -0.189189, -0.109910}, {-0.524324, 1.000000, -0.109910},  {-0.700901, 1.000000, 0.463063},  {-0.955649, 0.000000, -0.294508}, {0.150000, 0.150000, 0.750000}},
    {{-0.700901, -0.189189, 0.463063},  {0.045045, -0.189189, 0.066667},   {-0.524324, -0.189189, -0.109910},{ 0.000000, -1.000000, 0.000000}, {0.150000, 0.150000, 0.750000}},
    {{-0.700901, -0.189189, 0.463063},  {-0.131532, -0.189189, 0.643243},  { 0.045045, -0.189189, 0.066667}, { 0.000000, -1.000000, 0.000000}, {0.150000, 0.150000, 0.750000}},
};

void LoadTestModel(std::vector<Triangle>& triangles) {
    triangles = std::vector<Triangle>(30);
    for (int i = 0; i < 30; i++)
        triangles[i] = data[i];
}

vec3 computeNormal(vec3 v0, vec3 v1, vec3 v2) {
    vec3 e1(v1-v0);
    vec3 e2(v2-v0);
    return glm::normalize(glm::cross(e2,e1));
}

void loadModel(std::string filepath, std::vector<Triangle> &triangles) {
    FILE *stream = fopen(filepath.c_str(),"r");
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    vec3 v0, v1, v2, norm, col;
    while ((nread = getline(&line, &len, stream)) != -1) {
        sscanf(line, "%f %f %f %f %f %f %f %f %f %f %f %f",
                &v0.x, &v0.y, &v0.z, &v1.x, &v1.y, &v1.z,
                &v2.x, &v2.y, &v2.z, &col.x, &col.y, &col.z);
        norm = computeNormal(v0, v1, v2);
        triangles.push_back({v0, v1, v2, norm, col});
    }
    free(line);
    fclose(stream);
}
#endif
