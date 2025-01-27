#ifndef COMMUNAUTE_HPP
#define COMMUNAUTE_HPP

#include "action.hpp"

class communaute : public Action {
public:
    communaute(const string& nom);
    void activation(Joueur& joueur) override;
};

#endif // Comunauté_HPP
