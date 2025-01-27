/**
 * @file actif.cpp
 * @author PEAN Louis
 * @author DARGERE Lucas
 * @author LAVAUX Bastien
 * @brief Définition des méthodes et du constructeur de la classe Actif
 * @version 0.1
 * @date 2025-01-26
 * 
 * @copyright Copyright (c) 2025
 */

#include "actif.hpp"

/**
 * @brief Constructeur de la classe Actif
 * 
 * Initialise une case active avec un nom donné.
 * 
 * @param nom Nom de la case
 */
Actif::Actif(string nom) : Case(nom, 1) {}

/**
 * @brief Récupère le propriétaire de la case.
 * 
 * @return Joueur* Pointeur vers le propriétaire de la case.
 */
Joueur* Actif::getProprio() {
    return _proprietaire;
}

/**
 * @brief Indique si la case est constructible.
 * 
 * @return true Si la case est constructible.
 * @return false Si la case n'est pas constructible.
 */
bool Actif::getConstructible() {
    return _isConstructible;
}

/**
 * @brief Définit si la case est constructible ou non.
 * 
 * @param construc Booléen indiquant l'état constructible de la case.
 */
void Actif::setConstructible(bool construc) {
    _isConstructible = construc;
}