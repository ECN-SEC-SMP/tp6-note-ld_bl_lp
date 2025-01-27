/**
 * @file simple_visite.cpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe SimpleVisite
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */



#include "simple_visite.hpp"
#include <iostream>
#include <random>

SimpleVisite::SimpleVisite(const string& nom) : Action(nom,2) {}
SimpleVisite::SimpleVisite(const string& nom, bool prison) : Action(nom,3) {}
void SimpleVisite::activation(Joueur& joueur)
{
    int nothing = 0;
}