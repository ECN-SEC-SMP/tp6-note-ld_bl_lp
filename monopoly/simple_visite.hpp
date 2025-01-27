/**
 * @file simple_visite.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe SimpleJoueur
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */



#ifndef DEPART_HPP
#define DEPART_HPP

#include "action.hpp"

class SimpleVisite : public Action {
public:
    SimpleVisite(const string& nom);
    SimpleVisite(const string& nom, bool prison);
    void activation(Joueur& joueur);
    
};

#endif 
