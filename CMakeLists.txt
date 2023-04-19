cmake_minimum_required(VERSION 3.22)
project(Filme)

set(CMAKE_CXX_STANDARD 23)

add_executable(Filme main.cpp filme.cpp filme.h ui.cpp ui.h filme_repo.cpp filme_repo.h filme_service.cpp filme_service.h validare.cpp validare.h teste.cpp teste.h generic_Vector.cpp generic_vector.h vector.h)
