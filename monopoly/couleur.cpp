#include "couleur.hpp"


Couleur::Couleur(vector<Actif*> rue){
    _rue = rue ;
}

vector<Actif*> Couleur::listeConstructible(Joueur* joueur){
    if(joueur == _joueur)
    {
        return _rue;
    }
    else
    {
        return vector<Actif*>{nullptr};
    }
}

void Couleur::miseAJour(){
    if (_rue.empty()) {
        cout << "Aucune case dans la rue." << endl;
        return;
    }

    // Obtenir le propriétaire de la première case
    Joueur* premierProprietaire = _rue.front()->getProprio(); // Remplacez `proprietaire` par le champ réel

    // Vérifier si tous les propriétaires sont les mêmes
    bool tousIdentiques = true;
    for (Actif* c : _rue) {
        if (c->getProprio() != premierProprietaire) { // Comparaison avec le premier propriétaire
            tousIdentiques = false;
            break;
        }
    }

    if (tousIdentiques) {
        for (Actif* c : _rue) {
            c->setConstructible(1);
        }
    } 
}

