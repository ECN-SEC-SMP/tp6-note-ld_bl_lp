#include "maitre.h"

// Constructeur
Maitre::Maitre(int nb_J) {

    creation_plateau();

    if(nb_J < 2)
    {
        std::cout << "ERROR! pas assez de joueurs! nombre forcé à 2" << std::endl;
        nb_J = 2;
    }
    nb_Joeurs = nb_J;

    creation_joueurs(nb_J);
    index_joueur_actif = joueurs.begin();
    
}

// Fonction pour passer au tour suivant
void Maitre::passer_tour() {
    Joueur joueur_actif = *index_joueur_actif;


    int joueur_en_prison = test_prison(joueur_actif);
    if(joueur_en_prison ==0)
    {
        std::cout << "Au tour de " << joueur_actif.getNom() << " ! Lance les dés!" <<std::endl;  
        int resultat = lancer_des();

        Case * case_temp = joueur_actif.getPosition();
        int type_case = case_temp->getType();

        Terrain * case_terrain; //le compilateur ne veut pas de définition dans un case
        Action * case_action;

        switch (type_case)
        { 
            case 0:
                std::cout <<"ERROR! une case à un type non initialisé! (cette case ne fera rien)" << std::endl;
                break;
            case 1:
                case_terrain = static_cast<Terrain*>(case_temp); //pas de polymorphisme (oups) donc static cast
                case_terrain_activation(case_terrain);
                break;
            case 2:
                case_action = static_cast<Action*>(case_temp); //pas de polymorphisme (oups) donc static cast
                case_action_activation(case_action);
                break;
            default:
                std::cout <<"ERROR! une case à un type non connu! (cette case ne fera rien) numéro de type: " << type_case << std::endl;
                break;
        }
    }
    // Appel des autres fonctions nécessaires pour gérer un tour complet
}

void Maitre::creation_plateau()
{

}

void Maitre::creation_joueurs(int nb_J)
{
    std::string nomJoueur[nb_J];
    for(int i=0; i< nb_J; i++)
    {
        std::cout << "nom du joueur " << i+1 << " : " << std::endl;
        std::cin >> nomJoueur[i];
    }
    for(int i=0; i<nb_J;i++)  joueurs.push_back(Joueur(nomJoueur[i], mono_base, &plateau_jeu));
}

int Maitre::lancer_des()
{
    int resultat1 = 0;
    int resultat2 = 0;
    srand(static_cast<unsigned int>(time(0))); // update la seed à chaque lancé, pas sûr que celà ait un impact négatif
    resultat1 = rand() % 6 + 1;
    resultat2 = rand() % 6 + 1;
    if(resultat1 == resultat2)
    {
        std::cout << "vous avez fait un double de " << resultat1 << " ! "<< std::endl;
        return -1;
    }
    else 
    {
        int total_result = resultat1 + resultat2;
        std::cout << "vous avez fait " << total_result << " (" << resultat1 << " + " << resultat2 << " )" << std::endl;
        return total_result;
    }
}

int Maitre::test_prison(Joueur &joueur) {
    int nb_tour_prison = joueur.getEnPrison();
    
    if(nb_tour_prison)
    {
        std::cout << "Vous lancez les dés pour tenter de sortir!" << std::endl;
        if(lancer_des() == -1)
        {
        joueur.setEnPrison(nb_tour_prison-1);
        std::cout << "Bravo! vous sortez de prison sans payer!" << std::endl;
        }else
        {
            std::cout << "pas de chance! Voulez vous payer pour votre sortie ? (50 mono) (O/N)" << std::endl;
            char reponse ='N'; 
            std::cin >> reponse;
            if(reponse == 'O')
            {
                Action * case_prison = static_cast<Action*>(joueur.getPosition()); //pas génial, mais on à oublier de mettre la fonction case en polymorphique donc static cast obligatoire (oups)
                case_action_activation(case_prison);
                joueur.setEnPrison(0);
            }
        }
    }
    if(nb_tour_prison ==0)
    {
        std::cout << "vous sortez de prison!" <<std::endl;
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
void Maitre::case_terrain_activation(Terrain* case_terrain) {

}

// Gère les actions liées aux cases d'action
void Maitre::case_action_activation(Action* case_action) {
    
}

// Vérifie les informations ou les états d'un joueur
void Maitre::verif_joueur() {
    
}
