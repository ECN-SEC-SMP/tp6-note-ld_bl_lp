#include "chance.hpp"
#include <iostream>
#include <random>

Chance::Chance(const string& nom) : Action(nom) {}

void Chance::tirage(Joueur& joueur) {
    // Exemple d'effet de tirage : ajout ou retrait d'argent
    nom = joueur.getNom();
    cout << " Le joueur " +nom +" tire une carte chance !" << endl;
    std::random_device rd;                 // Graine aléatoire
    std::mt19937 gen(rd());                // Générateur basé sur la graine
    std::uniform_int_distribution<> dis(0, 99); // Distribution uniforme entre 0 et 99

    // Générer un nombre aléatoire
    int aleatoire = dis(gen);
    
    if (aleatoire < 50){
        joueur.setSolde(200);
        cout << " Le joueur " +nom +" a gagné 200 mono" << endl;
    }else{
        joueur.setSolde(-200);
        cout << " Le joueur " +nom +" a perdu 200 mono" << endl;
    }
    
}
