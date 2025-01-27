#include "communaute.hpp"
#include <iostream>
#include <random>

communaute::communaute(const string& nom) : Action(nom) {}

void communaute::activation(Joueur& joueur) {
    // Exemple d'effet de tirage : ajout ou retrait d'argent
    nom = joueur.getNom();
    cout << " Le joueur " +nom +" tire une communaute chance !" << endl;
    std::random_device rd;                 // Graine aléatoire
    std::mt19937 gen(rd());                // Générateur basé sur la graine
    std::uniform_int_distribution<> dis(0, 99); // Distribution uniforme entre 0 et 99

    // Générer un nombre aléatoire
    int aleatoire = dis(gen);
    
    if (aleatoire < 50){
        joueur.setSolde(250);
        cout << " Le joueur " +nom +" a gagné 250 mono" << endl;
    }else{
        joueur.setSolde(-250);
        cout << " Le joueur " +nom +" a perdu 250 mono" << endl;
    }
    
}
