
/**
 * @file joueur.cpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Description de la classe Joueur
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */



#include "joueur.hpp"
#include<iostream>


/**
 * @brief Constructeur de la classe Joueur
 * 
 * @param newNom Nom du joueur
 * @param creationSolde Solde du juoeur a la création 
 */
Joueur::Joueur(string newNom ,int creationSolde){
    nom =newNom;
    solde = creationSolde;
    position = 0 ;
    enPrison = 0 ; 
    carteSortir = 0 ;
}

/**
 * @brief Setter du solde du joueur
 * 
 * @param add solde a ajouter ou enlever
 */
void Joueur::setSolde(int add){
    solde = solde + add;
}

/**
 * @brief  Accesseur du solde du joueur
 * 
 * @return solde du joueur
 */

int Joueur::getSolde(){
    return solde ;
}

/**
 * @brief Setter de la position du joueur
 * 
 * @param newPosition nouvelle position du joueur
 */
void Joueur::setPosition(int newPosition){
    position=newPosition;
}

/**
 * @brief  Accesseur de la position du joueur
 * 
 * @return position du joueur
 */

int Joueur::getPosition(){
    return position;
}


/**
 * @brief Setter du nombre de tour en prison du joueur
 * 
 * @param tour en prison nombre de tour en prison
 */
void Joueur::setEnPrison(int tourEnPrison){
    enPrison=tourEnPrison;
}

/**
 * @brief  Accesseur du nombre de tour en prison du joueur
 * 
 * @return  nombre de tour en prison du joueur
 */

int Joueur::getEnPrison(){
    return enPrison;
}

/**
 * @brief Setter de la carte de sortie prison du joueur
 * 
 * @param newCarteSortir Nombre de carte Sortir de prison
 */
void Joueur::setCarteSortir(int newCarteSortir){
    carteSortir = newCarteSortir;
}

/**
 * @brief  Accesseur du nombre de carte sortir de prison du joueur
 * 
 * @return  nombre de carte sortir de prison du joueur
 */

int Joueur::getCarteSortir(){
    return carteSortir;
}

/**
 * @brief  Accesseur du nom du joueur
 * 
 * @return  nombre du joueur
 */
string Joueur::getNom(){
    return nom;
}

/**
 * @brief ajout d'une gare au joueur 
 */
void Joueur::addGare(){
    nbGare = nbGare + 1;
}

/**
 * @brief  Accesseur du nombre de gare du joueur
 * 
 * @return  nombre de gare du joueur
 */

int Joueur::getNbGare(){
    return nbGare;
}

/**
 * @brief ajout d'un service public au joueur 
 */
void Joueur::addSP(){
    nbSP = nbSP + 1 ;
}

/**
 * @brief  Accesseur du nombre de Service Public du joueur
 * 
 * @return  nombre de Service Public du joueur
 */
int Joueur::getNbSP(){
    return nbSP;
}
