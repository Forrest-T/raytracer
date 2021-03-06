cmake_minimum_required (VERSION 2.6)
project (raytracer)

add_executable(main
               src/main.cpp
               src/BBox.cpp
               src/Kdtree.cpp
               src/KdArray.cpp
               src/Triangle.cpp
               src/cl_manager.cpp
               src/scene_manager.cpp)

find_package (SDL)
if (NOT SDL_FOUND)
    message (FATAL_ERROR "SDL not found!")
endif (NOT SDL_FOUND)
if (SDL_FOUND)
    include_directories(${SDL_INCLUDE_DIR})
    target_link_libraries(main ${SDL_LIBRARY})
endif (SDL_FOUND)

find_package (OpenCL)
if (NOT OpenCL_FOUND)
    message (FATAL_ERROR "OpenCL not found!")
endif (NOT OpenCL_FOUND)
if (OpenCL_FOUND)
    include_directories(${OpenCL_INCLUDE_DIR})
    target_link_libraries(main ${OpenCL_LIBRARY})
endif (OpenCL_FOUND)
