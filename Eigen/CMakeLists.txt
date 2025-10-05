cmake_minimum_required(VERSION 3.10)
project(EigenExamples)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Eigen3
find_package(Eigen3 REQUIRED)

# If Eigen3 is not found, you can use FetchContent to download it
if(NOT Eigen3_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        Eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.4.0
    )
    FetchContent_MakeAvailable(Eigen)
endif()

# Add executable targets
add_executable(ejercicio_matriz ejercicio_matriz.cpp)
add_executable(ejercicio_matriz2 ejercicio_matriz2.cpp)
add_executable(ejercicio_pseudo ejercicio_pseudo.cpp)

# Link Eigen3
target_link_libraries(ejercicio_matriz Eigen3::Eigen)
target_link_libraries(ejercicio_matriz2 Eigen3::Eigen)
target_link_libraries(ejercicio_pseudo Eigen3::Eigen)

# Set build flags for better performance
target_compile_options(ejercicio_matriz PRIVATE -O3)
target_compile_options(ejercicio_matriz2 PRIVATE -O3)
target_compile_options(ejercicio_pseudo PRIVATE -O3)