/**
 * @file couleur.cpp
 * @brief Implémentation des méthodes de la classe Couleur
 * @version 0.1
 * @date 2025-01-26
 * 
 * @author PEAN Louis
 * @author DARGERE Lucas
 * @author LAVAUX Bastien
 * @copyright Copyright (c) 2025
 */

#include "couleur.hpp"

/**
 * @brief Constructeur de la classe Couleur
 * 
 * Initialise un objet Couleur avec un vecteur de cases (Actif).
 * 
 * @param rue Vecteur de pointeurs vers les cases associées à cette couleur.
 */
Couleur::Couleur(vector<Actif*> rue) {
    _rue = rue;
}

/**
 * @brief Retourne la liste des cases constructibles pour un joueur donné.
 * 
 * Si le joueur passé en paramètre est le propriétaire de toutes les cases
 * de cette couleur, retourne la liste complète des cases. Sinon, retourne 
 * un vecteur contenant `nullptr`.
 * 
 * @param joueur Pointeur vers le joueur dont les droits sont vérifiés.
 * @return vector<Actif*> Liste des cases constructibles ou un vecteur contenant `nullptr` si non valide.
 */
vector<Actif*> Couleur::listeConstructible(Joueur* joueur) {
    if (joueur == _joueur) {
        return _rue;
    } else {
        return vector<Actif*>{nullptr};
    }
}

/**
 * @brief Met à jour l'état des cases de cette couleur.
 * 
 * Vérifie si toutes les cases de la couleur ont le même propriétaire. 
 * Si c'est le cas, elles deviennent constructibles. Sinon, elles restent non constructibles.
 */
void Couleur::miseAJour() {
    if (_rue.empty()) {
        cout << "Aucune case dans la rue." << endl;
        return;
    }

    // Obtenir le propriétaire de la première case
    Joueur* premierProprietaire = _rue.front()->getProprio();

    // Vérifier si tous les propriétaires sont les mêmes
    bool tousIdentiques = true;
    for (Actif* c : _rue) {
        if (c->getProprio() != premierProprietaire) {
            tousIdentiques = false;
            break;
        }
    }

    // Mettre à jour l'état constructible si tous les propriétaires sont identiques
    if (tousIdentiques) {
        for (Actif* c : _rue) {
            c->setConstructible(1);
            _joueur == c->getProprio();
        }
    } 
}