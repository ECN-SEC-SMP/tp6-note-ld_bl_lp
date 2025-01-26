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
    if(joueur_en_prison ==0) // le joueur n'est pas en prison
    {
        std::cout << "Au tour de " << joueur_actif.getNom() << " ! Lance les dés!" <<std::endl;  
        int resultat = lancer_des();
        if(resultat == -1)
        {
            std::cout << "second lancé pour éviter la prison!" << std::endl;
            resultat = lancer_des();
        }
        if(resultat != -1) // le joueur ne part pas en prison
        {
            int tour_complet = joueur_actif.setPosition(resultat);
            if(tour_complet == 1) joueur_actif.setSolde(200); // le joueur à passé la case départ, il est crédité de 200 monos
            Case * case_temp = joueur_actif.getPosition();
            int type_case = case_temp->getType();

            Terrain * case_terrain; //le compilateur ne veut pas de définition dans un case
            Action * case_action;

            switch (type_case)
            { 
                case 0: //case non définie
                    std::cout <<"ERROR! une case à un type non initialisé! (cette case ne fera rien)" << std::endl;
                    break;
                case 1: //case terrain
                    case_terrain = static_cast<Terrain*>(case_temp); //pas de polymorphisme (oups) donc static cast
                    case_terrain_activation(case_terrain);
                    break;
                case 2:
                    case_action = static_cast<Action*>(case_temp); //pas de polymorphisme (oups) donc static cast
                    case_action_activation(case_action);
                    break;
                case 4:
                    std::cout << "Oups! vous êtes tombés sur une case \"aller en prison!\"" << std::endl;
                    set_joueur_en_prison(joueur_actif);
                    break;
                default:
                    std::cout <<"ERROR! une case à un type non connu! (cette case ne fera rien) numéro de type: " << type_case << std::endl;
                    break;
            }
        }else
        {
            set_joueur_en_prison(joueur_actif);
        }
    }
    //demande pour l'achat immobillier sur des terrains possédés 
    achat_immobillier();


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

void Maitre::set_joueur_en_prison(Joueur &joueur)
{   
    std::cout << "Pas de chance! Vous allez en prison." << std::endl;
    while(joueur.getPosition()->getType() != 3) //loop tand que le  joueur n'est pas sur la case prison
    {
        joueur.setPosition(1);
    }
    joueur.setEnPrison(3); // met le joueur en prison pour 3 tours
}

// Gère le mécanisme d'enchère
void Maitre::enchere(Terrain &tile) {
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
        tile.achat(*Gagnant, true);

        std::cout << "Gagnant de l'enchère: " << Gagnant->getNom() << std::endl;
    }else
    {
        std::cout <<"personne n'as enchéri, pas de gagnant!" << std::endl;
    }

}


void Maitre::achat_immobillier()
{
    std::vector<Case*> vecteur_cases_constructibles = liste_case_constructibles();

    if(vecteur_cases_constructibles.empty())
    {
        std::cout << "Vous n'avez aucune case constructible!" << std::endl;
    }else
    {
        int user_input = 0;
        while(user_input != -1)
        {
            std::cout << "Liste de vos cases constructibles:" << std::endl;
            int i=0;
            std::vector<Case*>::iterator index_cases_constructibles = vecteur_cases_constructibles.begin();
            while(index_cases_constructibles != vecteur_cases_constructibles.end())
            {
                Case * case_actuelle = *index_cases_constructibles;
                std::cout << i << " : " << case_actuelle->getNom() << std::endl;
                i++;
                index_cases_constructibles ++;
            }
            std::cout << "Sur quelles cases voulez-vous construire? (-1 pour ne rien faire)" <<std::endl;
            std::cin >>user_input;
            if(user_input >= 0 && user_input+1 < vecteur_cases_constructibles.size())
            {
                Case * case_choisie = vecteur_cases_constructibles[user_input];
                if(case_choisie->getType() != 1)
                {
                    std::cout << "cette case n'est pas constructible!" << std::endl; 
                }else
                {
                    Terrain * case_terrain = static_cast<Terrain*>(case_choisie);
                    int nb_maisons_construites = case_terrain->getNbMaison();
                    if( nb_maisons_construites == 5)
                    {
                        std::cout << "vous avez déjà tout acheté sur cette case!" << std::endl;
                    }else
                    {
                        std::cout << "Voulez vous acheter un nouveau batiment sur " << case_terrain->getNom() << " pour 200 Monos? O/N"  << std::endl;
                        std::cout << "il vous reste " << index_joueur_actif->getSolde() << " monos";
                        char user_input_buy = 'N';
                        std::cin >> user_input_buy;
                        if(user_input_buy=='O')
                        {
                            case_terrain->acahtImmo(1);
                            index_joueur_actif->setSolde(-200);
                        }
                    }
                }
            }           //Amélioration possible: rajouter une ou deux fonctions pour rendre plus propre cet escallier de boucles & if
        }
    }
}
// Gère les actions liées aux cases de type terrain
void Maitre::case_terrain_activation(Terrain* case_terrain) {
    Joueur* proprio = case_terrain->getProprio();
    if(proprio ==nullptr) //la case n'as pas de propriétaure, donc achat / mise au enchères
    {
        std::cout << "voulez vous acheter ce terrain pour " << case_terrain->getPrixAchat() << " monos? O/N" << std::endl;
        std::cout << "Vous avez" << index_joueur_actif->getSolde() << " monos." << std::endl;
        char user_input = 'N';
        std::cin>>user_input;
        if(user_input == 'O')
        {
            case_terrain->achat(*index_joueur_actif,false);
        }else
        {
            enchere(*case_terrain);
        }
    }else if(proprio->getNom() == index_joueur_actif->getNom())
    {
        std::cout << "Vous êtes chez vous sur la case " << proprio->getNom() << std::endl;
    }else
    {
        int loyer = case_terrain->loyer() ;
        std::cout << "vous êtes sur la case de " << proprio->getNom() << "vous payez un loyer de: " << loyer << " monos." << std::endl;
        proprio->setSolde(loyer);
        index_joueur_actif->setSolde(-loyer);
        std::cout << "il vous reste :" << index_joueur_actif->getSolde() << " monos." << std::endl;
    }
}

// Gère les actions liées aux cases d'action
void Maitre::case_action_activation(Action* case_action) {
    case_action->activation(*index_joueur_actif);
}

// Vérifie les informations ou les états d'un joueur
void Maitre::verif_joueur() {
    
}
std::vector<Case*> Maitre::liste_case_constructibles()
{
    std::vector<Case*> vecteur_cases_constructibles ;

    return vecteur_cases_constructibles;
}