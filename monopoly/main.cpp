#include <iostream>
#include "chance.hpp"
#include "joueur.hpp"
#include "communauté.hpp"
#include"taxe_de_luxe.hpp"
#include"impots.hpp"
#include "aller_en_prison.hpp"
#include"simple_visite.hpp"

int main() {
    // Création d'un joueur
    Joueur joueur1("lucas",1000); // Nom : Alice, Solde initial : 1000

    // Création d'une case "Chance"
    /*Chance chanceCase("Case Chance");
    Communauté communauté("Case comunauté");
    TaxeDeLuxe taxe_de_luxe("case taxe de luxe");
    Impots impots("case Impots");*/
    AllerEnPrison allezEnPrison("case Allez en prison");
    

    // Affichage de l'état initial du joueur
    
    std::cout << "Nom : 1 Solde : " << joueur1.getSolde() << "€" << std::endl;

    // Appliquer l'effet de la case Chance
    //chanceCase.tirage(joueur1);
    //communauté.tirage(joueur1);
    //taxe_de_luxe.taxe(joueur1);
    //impots.taxe(joueur1);
    allezEnPrison.activation(joueur1);
    // Affichage de l'état final du joueur
    std::cout << "prison : " << joueur1.getEnPrison() << "mono" << std::endl;
    std::cout << "position : " << joueur1.getPosition() << "mono" << std::endl;
    std::cout << "Nom : 1 Solde : " << joueur1.getSolde() << "mono" << std::endl;

    return 0;
}
