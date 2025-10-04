cmake_minimum_required(VERSION 3.10)
project(matriz_example)

find_package(Eigen3 REQUIRED)
add_executable(matriz main.cpp)
target_link_libraries(matriz Eigen3::Eigen)


add_executable(penrose main1.cpp)
target_link_libraries(penrose Eigen3::Eigen)