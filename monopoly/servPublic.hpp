#pragma once

#include <iostream>
#include "actif.hpp"
#include "couleur.hpp"

using namespace std;

class ServPublic : public Actif {
public:

    ServPublic(string nom);
    void achat(Joueur& joueur, bool enchere) override;
    int tarif(Joueur &joueur, int de1, int de2);

};