project( taller_raices_gsl CXX )
cmake_minimum_required( VERSION 3.10 )

find_package( GSL )
add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME} GSL::gsl )
