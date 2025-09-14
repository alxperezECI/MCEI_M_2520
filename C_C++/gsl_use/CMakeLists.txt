project( raices_gsl CXX )
cmake_minimum_required( VERSION 3.10 )

find_package( GSL )
add_executable( ${PROJECT_NAME} demo_fn.h demo_fn.c main.cpp )
target_link_libraries( ${PROJECT_NAME} GSL::gsl )
