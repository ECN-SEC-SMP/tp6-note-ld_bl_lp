/**
 * @file case.cpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe case
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */

#include <string>
#include <iostream>
#include "case.hpp"


/**
 * @brief Constructeur de la classe Case
 * 
 * @param newNom Nom de la case
 * @param newType Type de la case
 */

Case::Case(string newNom, int newType){
    nom=newNom;
    type = newType ;
}

/**
 * @brief  Accesseur du nom la classe Case
 * 
 * @return nom de la case
 */

string Case::getNom() {
    return nom;
}
/**
 * @brief Setter du nom de la case
 * 
 * @param newNom Nouveau nom de la case
 */
void Case::setNom( string newNom) {
    nom = newNom;
}