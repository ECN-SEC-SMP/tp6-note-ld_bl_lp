/**
 * @file aller_en_prison.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe AllerEnPrison de la classe action
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#ifndef ALLER_EN_PRISON_HPP
#define ALLER_EN_PRISON_HPP

#include "action.hpp"

class AllerEnPrison : public Action {
public:
    AllerEnPrison(const string& nom);
    void activation(Joueur& joueur) override;
};

#endif 
