/**
 * @file taxe_deluxe.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe TaxeDeLuxe
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#ifndef TAXE_DE_LUXE_HPP
#define TAXE_DE_LUXE_HPP

#include "action.hpp"

class TaxeDeLuxe : public Action {
public:
    TaxeDeLuxe(const string& nom);
    void activation(Joueur& joueur) override; 
};

#endif 
