#include "terrain.hpp"

int Terrain::_loyer[5] = {0,0,0,0,0};

Terrain::Terrain(string nom,int PrixAchat,int loyer[5]): Actif(nom){
    _prixAchat = PrixAchat;
    for (int i = 0; i < 5; i++) {
        _loyer[i] = loyer[i]; // Copie des valeurs une par une
    }
}

void Terrain::achat(Joueur* joueur){
    _proprietaire=joueur;
    joueur->setSolde(-_prixAchat);
}

int Terrain::loyer(){
    return _loyer[_nbMaison];
}

void Terrain::acahtImmo(int nbMaison){
    if(_isConstructible==1){
    _nbMaison += nbMaison;
    }
}

int Terrain::getNbMaison(){
    return _nbMaison;
}