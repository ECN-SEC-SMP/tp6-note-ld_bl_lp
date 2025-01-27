#include "actif.hpp"

Actif::Actif(string nom) : Case(nom,1) {}

Joueur* Actif::getProprio(){
    return _proprietaire;
}

bool Actif::getConstructible(){
    return _isConstructible;
}

void Actif::setConstructible(bool construc){
    _isConstructible = construc;
}