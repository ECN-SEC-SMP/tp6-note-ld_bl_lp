#pragma once

#include <iostream>
#include "case.hpp"
#include "joueur.hpp"

using namespace std;

class Actif : public Case {
protected:
    Joueur *_proprietaire = nullptr;
    bool    _isConstructible;

public:
    Actif(string nom, bool constructible);
    virtual void achat(Joueur& joueur) =0; 
    ~Actif(){ delete _proprietaire;};
};

