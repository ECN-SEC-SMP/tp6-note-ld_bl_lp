#pragma once

#include <iostream>
#include "actif.hpp"

using namespace std;

class Terrain : public Actif {
protected:
    int _prixAchat=0;
    int _nbMaison=0;
    static int _loyer[5];

public:

    Terrain(string nom,int PrixAchat,int loyer[5]);
    void achat(Joueur* joueur) override;
    int  loyer();
    void acahtImmo(int nbMaison);
    int getNbMaison();

};