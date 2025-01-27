/**
 * @file gare.cpp
 * @brief Implémentation des méthodes de la classe Gare
 * @version 0.1
 * @date 2025-01-26
 * 
 * @author PEAN Louis
 * @author DARGERE Lucas
 * @author LAVAUX Bastien
 * @copyright Copyright (c) 2025
 */

#include "gare.hpp"

/**
 * @brief Tableau statique définissant le loyer en fonction du nombre de gares possédées.
 * 
 * Indices :
 * - [0] : Aucun loyer (0 gare possédée)
 * - [1] : Loyer pour 1 gare (-25)
 * - [2] : Loyer pour 2 gares (-50)
 * - [3] : Loyer pour 3 gares (-100)
 * - [4] : Loyer pour 4 gares (-200)
 */
const int Gare::_loyer[5] = {0, -25, -50, -100, -200};

/**
 * @brief Constructeur de la classe Gare
 * 
 * Initialise une gare avec son nom.
 * 
 * @param nom Nom de la gare.
 */
Gare::Gare(string nom) : Actif(nom) {}

/**
 * @brief Calcule le tarif de location pour un joueur.
 * 
 * Le tarif est basé sur le nombre de gares possédées par le propriétaire de cette gare.
 * 
 * @param joueur Pointeur vers le joueur pour lequel le tarif est calculé.
 * @return int Montant du loyer dû par le joueur.
 */
int Gare::tarif(Joueur* joueur) {
    int nbGare = _proprietaire->getNbGare(); // Nombre de gares possédées par le propriétaire
    return _loyer[nbGare];
}

/**
 * @brief Gère l'achat d'une gare par un joueur.
 * 
 * Associe le joueur comme propriétaire de la gare, retire 200 unités de son solde
 * et met à jour le nombre de gares possédées par ce joueur.
 * 
 * @param joueur Pointeur vers le joueur effectuant l'achat.
 */
void Gare::achat(Joueur* joueur) {
    _proprietaire = joueur;           // Attribuer le joueur comme propriétaire
    joueur->setSolde(-200);           // Réduire le solde du joueur de 200 unités
    _proprietaire->addGare();         // Incrémenter le nombre de gares possédées par le joueur
}