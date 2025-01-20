#include "actif.hpp"

Actif::Actif(string nom,bool constructible) : Case(nom) {
    _isConstructible = constructible;
}
