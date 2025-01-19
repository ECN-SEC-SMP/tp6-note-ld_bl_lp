#include "aller_en_prison.hpp"
#include <iostream>
#include <random>

AllerEnPrison::AllerEnPrison(const string& nom) : Action(nom) {}

void AllerEnPrison::gotoprison(Joueur& joueur) {
    string nom = joueur.getNom();
    cout << " Le joueur " +nom +" est sur une case allez en prison ! Il va en prison" << endl;
    joueur.setPosition(1);
    joueur.setEnPrison(5);
    cout << " Le joueur " +nom +" est en prison" << endl;
}