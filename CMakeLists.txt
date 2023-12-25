cmake_minimum_required(VERSION 3.26)
project(Lexicon_S1_02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lexicon_S1_02
        carte.cpp
        joueur.cpp
        main.cpp
        pile.cpp
        talonEtExposee.cpp)
