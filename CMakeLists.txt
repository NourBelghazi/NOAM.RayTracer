cmake_minimum_required(VERSION 4.1)
project(NOAM_RayTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(NOAM_RayTracer
        src/main.cpp
        include/Vec3.h
        include/Color.h
)

target_include_directories(NOAM_RayTracer PUBLIC include)


