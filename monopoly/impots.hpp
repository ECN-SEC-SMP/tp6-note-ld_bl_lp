#ifndef IMPOTS_HPP
#define IMPOTS_HPP

#include "action.hpp"

class Impots : public Action {
public:
    Impots(const string& nom);
    void taxe(Joueur& joueur); 
};

#endif 
