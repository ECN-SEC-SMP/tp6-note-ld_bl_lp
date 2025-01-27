#include "actif.hpp"

Actif::Actif(string nom,int numType) : Case(nom,numType) {}
Joueur * Actif::getProprio()
{
    return _proprietaire;
}

void Actif::perte_joueur(Joueur *joueur)
{
    if( joueur == _proprietaire)
    {
        _proprietaire = nullptr;
    }
}