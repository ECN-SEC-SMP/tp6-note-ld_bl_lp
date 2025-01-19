#ifndef ALLER_EN_PRISON_HPP
#define ALLER_EN_PRISON_HPP

#include "action.hpp"

class AllerEnPrison : public Action {
public:
    AllerEnPrison(const string& nom);
    void gotoprison(Joueur& joueur); 
};

#endif 
