#include "actif.hpp"

Actif::Actif(string nom) : Case(nom,1) {}
Joueur * Actif::getProprio()
{
    return _proprietaire;
}