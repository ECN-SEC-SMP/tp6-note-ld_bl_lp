/**
 * @file joueur.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe Joueur
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */

#include "case.hpp"
#include <string>
#include <iostream>
#include <vector>

#ifndef JOUEUR_HPP
#define JOUEUR_HPP

using namespace std;

class Joueur{
    public:
        Joueur(string nom, int creationSolde, std::vector<Case*>* creation_plateau);
        void setSolde(int solde);
        int getSolde();
        int setPosition(int position);
        Case* getPosition();
        void setEnPrison(int enPrison);
        int getEnPrison();
        void setCarteSortir(int carteSortir);
        int getCarteSortir();
        string getNom();
        void addGare();
        int getNbGare();
        void addSP();
        int getNbSP();


    protected:
        string nom;
        int solde;
        int enPrison;
        int carteSortir;
        int nbGare;
        int nbSP;
        std::vector<Case*>* plateau;
        std::vector<Case*>::iterator position;

};

#endif