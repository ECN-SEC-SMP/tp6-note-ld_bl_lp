#pragma once

#include <iostream>
#include "actif.hpp"
#include "couleur.hpp"

using namespace std;

class Gare : public Actif {
protected:

    static const int _loyer[5];
    
public:

    Gare(string nom);
    void achat(Joueur& joueur) override;
    int tarif(Joueur &joueur);

};