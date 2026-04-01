cmake_minimum_required(VERSION 4.1)
project(NOAM_RayTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(main
        src/main.cpp
        include/Vec3.h
        include/Color.h
        src/Ray.cpp
        include/Ray.h
)

target_include_directories(main PUBLIC include)


