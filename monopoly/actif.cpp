#include "actif.hpp"

Actif::Actif(string nom) : Case(nom,1) {}
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