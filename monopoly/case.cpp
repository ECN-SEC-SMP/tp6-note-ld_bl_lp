#include <string>
#include <iostream>
#include "case.hpp"


Case::Case(string newNom){
    nom=newNom;
}

string Case::getNom() {
    return nom;
}

void Case::setNom( string newNom) {
    nom = newNom;
}