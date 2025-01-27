#include "servPublic.hpp"

ServPublic::ServPublic(string nom): Actif(nom){}

int ServPublic::tarif(Joueur* joueur, int de1, int de2){
    int resultatDes = de1 + de2; // Somme des dés
    int nbSP = joueur->getNbSP();
    int multiplicateur = (nbSP==2) ? 10 : 4;
    return -(resultatDes * multiplicateur);
}


void ServPublic::achat(Joueur* joueur){
    _proprietaire=joueur;
    joueur->setSolde(-150);
    _proprietaire->addSP();
}