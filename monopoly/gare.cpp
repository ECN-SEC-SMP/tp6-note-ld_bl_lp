#include "gare.hpp"

const int Gare::_loyer[5] = {0, -25, -50, -100, -200};

Gare::Gare(string nom): Actif(nom){}

int Gare::tarif(Joueur* joueur){
    int nbGare = _proprietaire->getNbGare();
    return _loyer[nbGare];
}


void Gare::achat(Joueur* joueur){
    _proprietaire=joueur;
    joueur->setSolde(-200);
    _proprietaire->addGare();
}
