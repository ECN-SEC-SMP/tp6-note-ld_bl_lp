#include "taxe_de_luxe.hpp"
#include <iostream>
#include <random>

TaxeDeLuxe::TaxeDeLuxe(const string& nom) : Action(nom) {}

void TaxeDeLuxe::taxe(Joueur& joueur) {
    nom = joueur.getNom();
    cout << " Le joueur " +nom +" est sur une case taxe de luxe ! Il doit payer 200 mono" << endl;
    joueur.setSolde(-200);
    cout << " Le joueur " +nom +" a perdu 200 mono" << endl;
}