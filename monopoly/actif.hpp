#pragma once

#include <iostream>
#include "case.hpp"
#include "joueur.hpp"

using namespace std;

class Actif : public Case {
protected:
    Joueur *_proprietaire = nullptr;
    bool    _isConstructible=0;

public:
    Actif(string nom);
    virtual void achat(Joueur& joueur, bool enchere) =0; 
    Joueur *getProprio();
    void perte_joueur(Joueur *joueur);
    ~Actif(){ delete _proprietaire;};
};

