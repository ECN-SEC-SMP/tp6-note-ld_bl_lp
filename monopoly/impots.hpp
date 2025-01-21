/**
 * @file impots.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe Impots
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#ifndef IMPOTS_HPP
#define IMPOTS_HPP

#include "action.hpp"

class Impots : public Action {
public:
    Impots(const string& nom);
    void activation(Joueur& joueur) override;
};

#endif 
