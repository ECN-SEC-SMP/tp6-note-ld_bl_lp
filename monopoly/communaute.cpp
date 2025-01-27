/**
 * @file communauté.cpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe Communauté de la classe Action
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */



#include "communauté.hpp"
#include <iostream>
#include <random>

/**
 * @brief Constructeur de la classe Communauté
 * 
 * @param nom Nom de la case
 */

Communauté::Communauté(const string& nom) : Action(nom) {}


/**
 * @brief le joueur pioche une carte communauté
 * 
 * @param joueur joueur qui joue
 */

void Communauté::activation(Joueur& joueur) {
    // Exemple d'effet de tirage : ajout ou retrait d'argent
    nom = joueur.getNom();
    cout << " Le joueur " +nom +" tire une communaute chance !" << endl;
    std::random_device rd;                 // Graine aléatoire
    std::mt19937 gen(rd());                // Générateur basé sur la graine
    std::uniform_int_distribution<> dis(0, 99); // Distribution uniforme entre 0 et 99

    // Générer un nombre aléatoire
    int aleatoire = dis(gen);
    
    if (aleatoire < 50){
        joueur.setSolde(250);
        cout << " Le joueur " +nom +" a gagné 250 mono" << endl;
    }else{
        joueur.setSolde(-250);
        cout << " Le joueur " +nom +" a perdu 250 mono" << endl;
    }
    
}
