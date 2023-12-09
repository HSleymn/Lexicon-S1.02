cmake_minimum_required(VERSION 3.26)
project(Lexiconpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lexiconpp main.cpp
        pile.cpp
        pile.h
        carte.cpp
        carte.h
        item.h
        joueur.cpp
        joueur.h)
