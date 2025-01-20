#ifndef TAXE_DE_LUXE_HPP
#define TAXE_DE_LUXE_HPP

#include "action.hpp"

class TaxeDeLuxe : public Action {
public:
    TaxeDeLuxe(const string& nom);
    void activation(Joueur& joueur) override; 
};

#endif 
