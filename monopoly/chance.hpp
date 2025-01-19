#ifndef CHANCE_HPP
#define CHANCE_HPP

#include "action.hpp"

class Chance : public Action {
public:
    Chance(const string& nom);
    void tirage(Joueur& joueur); // Implémentation de l'effet de tirage
};

#endif // CHANCE_HPP
