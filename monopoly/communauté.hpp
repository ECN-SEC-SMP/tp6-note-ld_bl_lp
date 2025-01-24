/**
 * @file communauté.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe Communauté
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#ifndef COMMUNAUTE_HPP
#define COMMUNAUTE_HPP

#include "action.hpp"

class Communauté : public Action {
public:
    Communauté(const string& nom);
    void activation(Joueur& joueur) override;
};

#endif // Comunauté_HPP
