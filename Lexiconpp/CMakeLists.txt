cmake_minimum_required(VERSION 3.26)
project(Lexiconpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lexiconpp
        pile.cpp
        pile.h
        carte.cpp
        carte.h
        joueur.cpp
        joueur.h
        main.cpp
        lettres.h)
