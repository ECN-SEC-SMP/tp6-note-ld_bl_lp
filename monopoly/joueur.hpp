/**
 * @file joueur.hpp
 * @author PEAN Louis, DARGERE Lucas, LAVAUX Bastien
 * @brief Définition de la classe Joueur
 * @version 0.1
 * @date 2025-01-20
 * 
 * @copyright Copyright (c) 2025
 */


#include <string>
#include <iostream>

#ifndef JOUEUR_HPP
#define JOUEUR_HPP

using namespace std;

class Joueur{
    public:
        Joueur(string nom, int creationSolde);
        void setSolde(int solde);
        int getSolde();
        void setPosition(int position);
        int getPosition();
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
        int position;
        int enPrison;
        int carteSortir;
        int nbGare;
        int nbSP;

};

#endif