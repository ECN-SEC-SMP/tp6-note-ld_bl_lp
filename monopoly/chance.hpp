#ifndef CHANCE_HPP
#define CHANCE_HPP

#include "action.hpp"

class Chance : public Action {
public:
    Chance(const string& nom);
    void activation(Joueur& joueur) override;
};

#endif // CHANCE_HPP
