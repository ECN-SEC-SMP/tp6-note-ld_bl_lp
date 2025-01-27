#include "couleur.hpp"


Couleur::Couleur(vector<Case*> rue){
    _rue = rue ;
}

vector<Case*> Couleur::listeConstructible(Joueur* joueur){
    if(joueur == _joueur)
    {
        return _rue;
    }
    else
    {
        vector<Case*> rien;
        return rien;
    }
}

void Couleur::miseAJour(){
    for(auto it=_rue.begin(); it!=_rue.end(); it++){
        
    }
}

