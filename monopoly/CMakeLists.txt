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
    case.cpp
    action.cpp
    chance.cpp
    communauté.cpp
    taxe_de_luxe.cpp
    impots.cpp
    aller_en_prison.cpp
    simple_visite.cpp
    maitre.cpp
    terrain.cpp
    actif.cpp
    gare.cpp
    servPublic.cpp 
)

# Créer l'exécutable
add_executable(monopoly ${SOURCES})

