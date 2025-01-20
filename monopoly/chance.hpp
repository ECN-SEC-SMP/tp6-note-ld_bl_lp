/**
 * @file communauté.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe Communauté
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#ifndef CHANCE_HPP
#define CHANCE_HPP

#include "action.hpp"

class Chance : public Action {
public:
    Chance(const string& nom);
    void activation(Joueur& joueur) override;
};

#endif // CHANCE_HPP
