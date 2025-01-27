/**
 * @file servPublic.cpp
 * @brief Implémentation des méthodes de la classe ServPublic
 * @version 0.1
 * @date 2025-01-26
 * 
 * @author PEAN Louis
 * @author DARGERE Lucas
 * @author LAVAUX Bastien
 * @copyright Copyright (c) 2025
 */

#include "servPublic.hpp"

/**
 * @brief Constructeur de la classe ServPublic
 * 
 * Initialise un service public avec son nom.
 * 
 * @param nom Nom du service public.
 */
ServPublic::ServPublic(string nom) : Actif(nom) {}

/**
 * @brief Calcule le tarif de location pour un joueur en fonction du résultat des dés.
 * 
 * Le tarif est calculé selon la formule :
 * - Si le propriétaire possède 1 service public : tarif = -4 * (somme des dés)
 * - Si le propriétaire possède 2 services publics : tarif = -10 * (somme des dés)
 * 
 * @param joueur Pointeur vers le joueur qui doit payer le tarif.
 * @param de1 Valeur du premier dé lancé.
 * @param de2 Valeur du second dé lancé.
 * @return int Montant du loyer à payer (négatif).
 */
int ServPublic::tarif(Joueur* joueur, int de1, int de2) {
    int resultatDes = de1 + de2; // Somme des dés
    int nbSP = joueur->getNbSP(); // Nombre de services publics possédés par le joueur
    int multiplicateur = (nbSP == 2) ? 10 : 4;
    return -(resultatDes * multiplicateur);
}

/**
 * @brief Gère l'achat d'un service public par un joueur.
 * 
 * Associe le joueur comme propriétaire du service public, réduit son solde de 150 unités, 
 * et met à jour le nombre de services publics possédés par ce joueur.
 * 
 * @param joueur Pointeur vers le joueur effectuant l'achat.
 */
void ServPublic::achat(Joueur* joueur) {
    _proprietaire = joueur;           // Attribuer le joueur comme propriétaire
    joueur->setSolde(-150);           // Réduire le solde du joueur de 150 unités
    _proprietaire->addSP();           // Incrémenter le nombre de services publics possédés
}