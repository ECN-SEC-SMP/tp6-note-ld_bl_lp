/**
 * @file aller_en_prison.cpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe aller_en_prison
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#include "aller_en_prison.hpp"
#include <iostream>
#include <random>

/**
 * @brief Constructeur de la classe AllerEnPrison
 * 
 * @param nom Nom de la case
 */
AllerEnPrison::AllerEnPrison(const string& nom) : Action(nom) {}

/**
 * @brief positionne le joueur en prison 
 * 
 * @param joueur joueur qui joue
 */

void AllerEnPrison::activation(Joueur& joueur) {
    string nom = joueur.getNom();
    cout << " Le joueur " +nom +" est sur une case allez en prison ! Il va en prison" << endl;
    joueur.setPosition(1);  // A Définir
    joueur.setEnPrison(3);
    cout << " Le joueur " +nom +" est en prison" << endl;
}