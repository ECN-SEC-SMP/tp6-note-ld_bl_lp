/**
 * @file impots.cpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe impots de la classe Action
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#include "impots.hpp"
#include <iostream>
#include <random>


/**
 * @brief Constructeur de la classe Impots
 * 
 * @param nom Nom de la case
 */

Impots::Impots(const string& nom) : Action(nom) {}


/**
 * @brief le joueur doit payer des Impots
 * 
 * @param joueur joueur qui joue
 */
void Impots::activation(Joueur& joueur) {
    nom = joueur.getNom();
    cout << " Le joueur " +nom +" est sur une case Impots  ! Il doit payer 200 mono" << endl;
    joueur.setSolde(-200);
    cout << " Le joueur " +nom +" a perdu 200 mono" << endl;
}