#include "maitre.h"

// Constructeur
Maitre::Maitre() : joueur_actif_index(0) {
    
}

// Fonction pour passer au tour suivant
void Maitre::passer_tour() {
    // Changer l'index du joueur actif
    joueur_actif_index = (joueur_actif_index + 1) % joueurs.size();

    //test_prison();


    // Appel des autres fonctions nécessaires pour gérer un tour complet
}

int Maitre::test_prison(Joueur &joueur) {
    int nb_tour_prison = joueur.getEnPrison();
    if(nb_tour_prison)
    {
        joueur.setEnPrison(nb_tour_prison-1);
    }
    return nb_tour_prison;
}

// Gère le mécanisme d'enchère
void Maitre::enchere(Case &tile) {
    int maxEnchere = 0;
    int inputJoueur = 0;
    
    bool pass[nb_Joeurs];
    int pass_total = 0;
    Joueur *Gagnant;
    std::cout << "Les enchères commencent pour la case :" << tile.getNom() << std::endl;

    for(int i=0; i <this->nb_Joeurs; i++) pass[i] = 0;  //on initialise la variable à false - pour être sûr


    while(pass_total < nb_Joeurs -1)    //tant qu'il y à plus d'un joueur qui participe à l'enchère
    {
        for (int i =0; i <this->nb_Joeurs; i++) {   //boucle entre tout les joeurs
            if(pass[i] == false)                    //vérifie que le joueur n'as pas déjà passé son tour
            {
                std::cout << "joueur " << joueurs[i].getNom() << " à toi d'enchérir!" << std::endl;
                std::cout <<"solde disponible: " << joueurs[i].getSolde() << std::endl << "enchère actuelle: " << maxEnchere << std::endl;
                std::cout <<"entrez votre enchère (0 pour ne pas participer):" << std::endl;
                std::cin >> inputJoueur;

                if(inputJoueur > joueurs[i].getSolde())
                {
                    std::cout << "Solde pas assez élevé! pas de chance!" << std::endl;
                    pass[i] = true;
                }else if(inputJoueur <=maxEnchere)
                {
                    std::cout << "enchère trop basse! pas de chance!" << std::endl;
                    pass[i] = true;
                }else
                {
                    maxEnchere = inputJoueur;
                    Gagnant = &joueurs[i];
                }
            }
        }
        pass_total = 0;
        for (int i =0; i <this->nb_Joeurs; i++) pass_total += pass[i];  //compte le nombre de joueurs ayant passé leur tour

    }
    if(Gagnant != nullptr)
    {
        Gagnant->setSolde(-maxEnchere);
        //case.setProprio(Gagnant);   //TODO: update with actual function

        std::cout << "Gagnant de l'enchère: " << Gagnant->getNom() << std::endl;
    }else
    {
        std::cout <<"personne n'as enchéri, pas de gagnant!" << std::endl;
    }

}

// Gère les actions liées aux cases de type terrain
void Maitre::case_terrain() {

}

// Gère les actions liées aux cases d'action
void Maitre::case_action() {
    
}

// Vérifie les informations ou les états d'un joueur
void Maitre::verif_joueur() {
    
}
