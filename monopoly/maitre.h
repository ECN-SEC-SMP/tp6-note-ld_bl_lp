#ifndef MAITRE_H
#define MAITRE_H

#include <vector>
#include "Joueur.h"
#include "GestionnaireCouleur.h" 
#include <iostream>

class Maitre {
public:
	// Constructeur
	Maitre();

	// Fonction pour passer au tour suivant
	void passer_tour();

private:
	// Vérifie si un joueur est en prison
	int test_prison(&joueur);

	// Gère le mécanisme d'enchère
	void enchere();

	// Gère les actions liées aux cases de type terrain
	void case_terrain();

	// Gère les actions liées aux cases d'action
	void case_action();

	// Vérifie les informations ou les états d'un joueur 
	void verif_joueur();

	// Liste des joueurs
	std::vector<Joueur> joueurs;

	// Index du joueur actif
	int joueur_actif_index;

	// Gestionnaire des couleurs
	GestionnaireCouleur gestionnaire_couleur;
};

#endif // MAITRE_H