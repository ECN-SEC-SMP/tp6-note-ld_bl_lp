#ifndef MAITRE_H
#define MAITRE_H

#include <vector>
#include "joueur.hpp"
#include "case.hpp"
//#include "GestionnaireCouleur.h" 
#include <iostream>

class Maitre {
public:
	// Constructeur
	Maitre();

	// Fonction pour passer au tour suivant
	void passer_tour();

private:
	// Vérifie si un joueur est en prison
	int test_prison(Joueur &joueur);

	// Gère le mécanisme d'enchère
	void enchere(Case &tile);

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
	int nb_Joeurs;
	int nb_Cases;

	// Gestionnaire des couleurs
	//GestionnaireCouleur gestionnaire_couleur;
};

#endif // MAITRE_H