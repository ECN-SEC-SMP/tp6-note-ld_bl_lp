#ifndef MAITRE_H
#define MAITRE_H

#include <vector>
#include <string>
#include <random>
#include <ctime>
#include "joueur.hpp"
#include "case.hpp"
#include "terrain.hpp"
#include "action.hpp"
#include "couleur.hpp"
//#include "GestionnaireCouleur.h" 
#include <iostream>

class Maitre {
public:
	// Constructeur
	Maitre(int nb_J);

	// Fonction pour passer au tour suivant
	void passer_tour();

private:
	const int mono_base =200;
	void creation_plateau();
	void creation_joueurs(int nb_J);
	int lancer_des(); //renvoie le résultat des deux dés ou -1 pour un double
	// Vérifie si un joueur est en prison
	int test_prison(Joueur &joueur);
	void set_joueur_en_prison(Joueur &joueur);
	// Gère le mécanisme d'enchère
	void enchere(Case &tile);

	void achat_immobillier();
	// Gère les actions liées aux cases de type terrain
	void case_terrain_activation(Terrain* case_terrain);

	// Gère les actions liées aux cases d'action
	void case_action_activation(Action* case_action);

	// Vérifie les informations ou les états d'un joueur 
	void verif_joueur();

	std::vector<Case*> liste_case_constructibles();
	void test_proprio_couleurs();
	
	// Liste des joueurs
	std::vector<Joueur> joueurs;
	std::vector<Case*> plateau_jeu;
	std::vector<Couleur> liste_couleurs;
	// Index du joueur actif
	std::vector<Joueur>::iterator index_joueur_actif;
	int nb_Joeurs;

	// Gestionnaire des couleurs
	//GestionnaireCouleur gestionnaire_couleur;
};

#endif // MAITRE_H