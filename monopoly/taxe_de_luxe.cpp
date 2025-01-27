/**
 * @file taxe_de_luxe.cpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe TaxeDeLuxe
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */

#include "taxe_de_luxe.hpp"
#include <iostream>
#include <random>

/**
 * @brief Constructeur de la classe TaxeDeLuxe
 * 
 * @param nom Nom de la case
 */

TaxeDeLuxe::TaxeDeLuxe(const string& nom) : Action(nom,2) {}


/**
 * @brief le joueur doit payer une Taxe de luxe
 * 
 * @param joueur joueur qui joue
 */

void TaxeDeLuxe::activation(Joueur& joueur) {
    nom = joueur.getNom();
    cout << " Le joueur " +nom +" est sur une case taxe de luxe ! Il doit payer 200 mono" << endl;
    joueur.setSolde(-200);
    cout << " Le joueur " +nom +" a perdu 200 mono" << endl;
}