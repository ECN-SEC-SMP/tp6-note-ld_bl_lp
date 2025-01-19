#include "joueur.hpp"
#include<iostream>

Joueur::Joueur(string newNom ,int creationSolde){
    nom =newNom;
    solde = creationSolde;
    position = 0 ;
    enPrison = 0 ; 
    carteSortir = 0 ;
}

void Joueur::setSolde(int add){
    solde = solde + add;
}

int Joueur::getSolde(){
    return solde ;
}

void Joueur::setPosition(int newPosition){
    position=newPosition;
}

int Joueur::getPosition(){
    return position;
}

void Joueur::setEnPrison(int tourEnPrison){
    enPrison=tourEnPrison;
}

int Joueur::getEnPrison(){
    return enPrison;
}

void Joueur::setCarteSortir(int newCarteSortir){
    carteSortir = newCarteSortir;
}

int Joueur::getCarteSortir(){
    return carteSortir;
}

string Joueur::getNom(){
    return nom;
}