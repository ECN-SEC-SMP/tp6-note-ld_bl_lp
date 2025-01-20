#include "couleur.hpp"


Couleur::Couleur(){
}

vector<string> Couleur::listeTerrain(Joueur* joueur){
    vector<string> proprietesAcquises;

    for (const auto& groupe : map) { // Parcourt les groupes (couleurs, gares, services publics)
        for (const auto& propriete : groupe) { // Parcourt les propriétés dans un groupe
            if (propriete.first == joueur) { // Vérifie si le joueur est propriétaire
                proprietesAcquises.push_back(propriete.second);
            }
        }
    }

    return proprietesAcquises;
}

void Couleur::newProprio(Joueur* newProprio,int groupe, int index){

    map[groupe][index].first = newProprio;
}

int Couleur::getNbGare(Joueur* joueur){
    int count = 0;
    const auto& gares = map[8]; // Récupère le groupe des gares

        // Parcourir toutes les gares du groupe
        for (const auto& gare : gares) {
            if (gare.first == joueur) {
                count++; // Si le joueur est propriétaire, incrémente le compteur
            }
        }
    return count;
}

int Couleur::getNbSP(Joueur* joueur){
    int count = 0;
    const auto& gares = map[9]; // Récupère le groupe des gares

        // Parcourir toutes les gares du groupe
        for (const auto& gare : gares) {
            if (gare.first == joueur) {
                count++; // Si le joueur est propriétaire, incrémente le compteur
            }
        }
    return count;
}