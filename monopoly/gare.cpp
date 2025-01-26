#include "gare.hpp"

const int Gare::_loyer[5] = {0, 25, 50, 100, 200};

Gare::Gare(string nom): Actif(nom){}

int Gare::tarif(Joueur& joueur){
    int nbGare = joueur.getNbGare();
    return _loyer[nbGare];
}


void Gare::achat(Joueur &joueur, bool enchere){
    _proprietaire=&joueur;
    if(!enchere) joueur.setSolde(-200);
}