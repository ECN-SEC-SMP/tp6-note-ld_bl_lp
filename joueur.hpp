#include <string>
#include <iostream>

#ifndef JOUEUR_HPP
#define JOUEUR_HPP

using namespace std;

class Joueur{
    public:
        Joueur(int creationSolde);
        void setSolde(int solde);
        int getSolde();
        void setPosition(int position);
        int getPosition();
        void setEnPrison(int enPrison);
        int getEnPrison();
        void setCarteSortir(int carteSortir);
        int getCarteSortir();


    protected:
        int solde;
        int position;
        int enPrison;
        int carteSortir;

};

#endif