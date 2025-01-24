#pragma once

#include <map>
#include <vector>
#include "joueur.hpp"
#include "terrain.hpp"

using namespace std;

class Couleur{
protected:

    //0 -> Violet 1 -> Bleu clair, 2 -> Rose, 3 -> Orange, 4 -> Rouge, 5 -> Jaune, 6 -> Vert clair, 7 -> Bleu foncé, 8 -> gare, 9 -> SP
    /*vector<vector<pair<Joueur*,string>>> map1 = {
    {{nullptr,"Boulevard de Belleville"},{nullptr,"Rue Lecourbe"}},
    {{nullptr,"Rue de Vaugirard"},{nullptr,"Avenue de la République"},{nullptr,"Rue de Courcelles"}},
    {{nullptr,"Boulevard de la Villette"},{nullptr,"Avenue de Neuilly"},{nullptr,"Rue de Paradis"}},
    {{nullptr,"Avenue de Mozart"},{nullptr,"Boulevard Saint-Michel"},{nullptr,"Place Pigalle"}},
    {{nullptr,"Avenue Matignon"},{nullptr,"Boulevard Malesherbes"},{nullptr,"Avenue Henri-Martin"}},
    {{nullptr,"Faubourg Saint-Honoré"},{nullptr,"Place de la Bourse"},{nullptr,"Rue La Fayette"}},
    {{nullptr,"Avenue de Breteuil"},{nullptr,"Avenue Foch"},{nullptr,"Boulevard des Capucines"}},
    {{nullptr,"Champs-Élysées"},{nullptr,"Rue de la Paix"}},
    {{nullptr, "Gare Montparnasse"},{nullptr, "Gare de Lyon"},{nullptr, "Gare Saint-Lazare"},{nullptr, "Gare du Nord"}},
    {{nullptr, "Compagnie des Eaux"},{nullptr, "Compagnie de l'Électricité"}}
};*/

    vector<Case*> _rue;
    Joueur* _joueur;

public:
    Couleur(vector<Case*> rue);
    vector<Case*> listeConstructible(Joueur* joueur);
    void miseAJour();
    
};

