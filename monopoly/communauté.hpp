#ifndef COMMUNAUTE_HPP
#define COMMUNAUTE_HPP

#include "action.hpp"

class Communauté : public Action {
public:
    Communauté(const string& nom);
    void tirage(Joueur& joueur); // Implémentation de l'effet de tirage
};

#endif // Comunauté_HPP
