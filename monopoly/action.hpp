/**
 * @file action.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe action
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */



#ifndef ACTION_HPP
#define ACTION_HPP

#include "case.hpp"
#include "joueur.hpp" 

class Action : public Case {
public:
    Action(const string& nom,int numType);
    virtual void activation(Joueur& joueur) =0; 

};

#endif // ACTION_HPP