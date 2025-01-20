#include "Maitre.h"

// Constructeur
Maitre::Maitre() : joueur_actif_index(0) {
    
}

// Fonction pour passer au tour suivant
void Maitre::passer_tour() {
    // Changer l'index du joueur actif
    joueur_actif_index = (joueur_actif_index + 1) % joueurs.size();

    test_prison();


    // Appel des autres fonctions nécessaires pour gérer un tour complet
}

int Maitre::test_prison(Joueur &joueur) {
    int nb_tour_prison = Joueur.getEnPrison();
    if(nb_tour_prison)
    {
        Joueur.setEnPrison(nb_tour_prison-1);
    }
    return nb_tour_prison;
}

// Gère le mécanisme d'enchère
void Maitre::enchere(Case &case) {
    int maxEnchere = 0;
    int inputJoueur = 0;
    
    bool pass[nb_Joeurs];
    int pass_total = 0;
    joueur *Gagnant;
    std::cout << "Les enchères commencent pour la case :" << case.getNom() << std::endl;

    for(int i=0; i <this->nb_Joeurs; i++) pass[i] = 0;  //on initialise la variable à false - pour être sûr


    while(pass_total < nb_Joeurs -1)
    {
        for (int i =0; i <this->nb_Joeurs; i++) {
            if(pass[i] = false)
            {
                std::cout << "joueur " << Joueurs[i].getNom() << " à toi d'enchérir!" << std::endl;
                std::cout <<"solde disponible: " << Joueurs[i].getSolde() << std::endl << "enchère actuelle: " << maxEnchere << std::endl;
                std::cout <<"entrez votre enchère (0 pour ne pas participer):" << std::endl;
                std::cin >> inputJoueur;

                if(inputJoueur > Joueurs[i].getSolde())
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
                    Gagnant = &Joueurs[i];
                }
            }
        }
        pass_total = 0;
        for (int i =0; i <this->nb_Joeurs; i++) pass_total += pass[i];

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
