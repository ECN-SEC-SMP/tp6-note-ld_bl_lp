#ifndef COMMUNAUTE_HPP
#define COMMUNAUTE_HPP

#include "action.hpp"

class Communauté : public Action {
public:
    Communauté(const string& nom);
    void activation(Joueur& joueur) override;
};

#endif // Comunauté_HPP
