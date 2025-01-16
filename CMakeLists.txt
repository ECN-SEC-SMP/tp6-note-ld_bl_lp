# Version minimale de CMake requise
cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(monopoly)

# Standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter les fichiers source
set(SOURCES
    main.cpp
    joueur.cpp
)

# Créer l'exécutable
add_executable(monopoly ${SOURCES})

