#include "impots.hpp"
#include <iostream>
#include <random>

Impots::Impots(const string& nom) : Action(nom) {}

void Impots::activation(Joueur& joueur) {
    nom = joueur.getNom();
    cout << " Le joueur " +nom +" est sur une case Impots  ! Il doit payer 200 mono" << endl;
    joueur.setSolde(-200);
    cout << " Le joueur " +nom +" a perdu 200 mono" << endl;
}