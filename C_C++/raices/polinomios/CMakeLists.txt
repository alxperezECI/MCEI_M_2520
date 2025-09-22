cmake_minimum_required( VERSION 3.10)
project( poly )
find_package (Eigen3 3.4 REQUIRED NO_MODULE)

add_executable ( ${PROJECT_NAME} poly.cpp)
target_link_libraries ( ${PROJECT_NAME} Eigen3::Eigen)
