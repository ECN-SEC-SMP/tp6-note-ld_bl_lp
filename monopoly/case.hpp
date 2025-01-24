/**
 * @file case.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe Case
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#include <string>
#include <iostream>

#ifndef CASE_HPP
#define CASE_HPP

using namespace std;
class Case {
    public:
        Case(string nom , int type);
        void setNom(string nom);
        string getNom();
        int getType();

    protected:
        string nom;
        int type;
};

#endif