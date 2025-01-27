#include "terrain.hpp"

Terrain::Terrain(string nom,int PrixAchat,std::vector<int> loyer): Actif(nom,1){
    _prixAchat = PrixAchat;
    for (int i = 0; i < 5; i++) {
        _loyer[i] = loyer[i]; // Copie des valeurs une par une
    }
}

void Terrain::achat(Joueur &joueur, bool enchere){
    _proprietaire=&joueur;
    if(!enchere) joueur.setSolde(-_prixAchat);
}
int Terrain::getPrixAchat()
{
    return _prixAchat;
}

int Terrain::loyer(){
    return _loyer[_nbMaison];
}

void Terrain::acahtImmo(int nbMaison){
    _nbMaison += nbMaison;
}

int Terrain::getNbMaison(){
    return _nbMaison;
}