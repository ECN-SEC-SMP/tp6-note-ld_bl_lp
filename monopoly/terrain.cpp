/**
 * @file terrain.cpp
 * @brief Implémentation des méthodes de la classe Terrain
 * @version 0.1
 * @date 2025-01-26
 * 
 * @author PEAN Louis
 * @author DARGERE Lucas
 * @author LAVAUX Bastien
 * @copyright Copyright (c) 2025
 */

#include "terrain.hpp"

/**
 * @brief Tableau statique définissant le loyer pour chaque nombre de maisons sur le terrain.
 * 
 * Le tableau contient les loyers pour 0, 1, 2, 3 et 4 maisons. Chaque indice représente
 * un nombre de maisons et le loyer correspondant. 
 */
int Terrain::_loyer[5] = {0, 0, 0, 0, 0};

/**
 * @brief Constructeur de la classe Terrain
 * 
 * Initialise un terrain avec un nom, un prix d'achat et un tableau de loyers.
 * 
 * @param nom Nom du terrain.
 * @param PrixAchat Prix d'achat du terrain.
 * @param loyer Tableau de loyers pour les 5 niveaux de maisons (de 0 à 4).
 */
Terrain::Terrain(string nom, int PrixAchat, int loyer[5]) : Actif(nom) {
    _prixAchat = PrixAchat;
    // Copie des valeurs du tableau de loyers
    for (int i = 0; i < 5; i++) {
        _loyer[i] = loyer[i];
    }
}

/**
 * @brief Gère l'achat du terrain par un joueur.
 * 
 * Le joueur devient propriétaire du terrain et son solde est réduit du prix d'achat.
 * 
 * @param joueur Pointeur vers le joueur effectuant l'achat.
 */
void Terrain::achat(Joueur* joueur) {
    _proprietaire = joueur;         // Attribuer le joueur comme propriétaire
    joueur->setSolde(-_prixAchat);  // Réduire le solde du joueur du prix d'achat
}

/**
 * @brief Récupère le loyer actuel du terrain.
 * 
 * Le loyer est calculé en fonction du nombre de maisons sur le terrain.
 * 
 * @return int Loyer actuel à payer pour ce terrain.
 */
int Terrain::loyer() {
    return _loyer[_nbMaison];  // Retourne le loyer en fonction du nombre de maisons
}

/**
 * @brief Achète des maisons sur le terrain.
 * 
 * Cette méthode permet au joueur d'acheter un nombre donné de maisons, 
 * à condition que la construction soit autorisée. Le nombre de maisons 
 * ne peut pas excéder 4.
 * 
 * @param nbMaison Nombre de maisons à ajouter.
 */
void Terrain::acahtImmo(int nbMaison) {
    if (_isConstructible == 1) {  // Vérifie si le terrain est constructible
        _nbMaison += nbMaison;
        if (_nbMaison > 4) {  // Limite à 4 maisons
            _nbMaison = 4;
        }
    }
}

/**
 * @brief Récupère le nombre actuel de maisons sur le terrain.
 * 
 * @return int Le nombre de maisons actuellement construites sur ce terrain.
 */
int Terrain::getNbMaison() {
    return _nbMaison;
}