#include <iostream>
#include "chance.hpp"
#include "joueur.hpp"
#include "communaute.hpp"
#include"taxe_de_luxe.hpp"
#include"impots.hpp"
#include "aller_en_prison.hpp"
#include"simple_visite.hpp"
#include "gare.hpp"
#include "servPublic.hpp"
#include "terrain.hpp"
#include "couleur.hpp"

int main() {
    // Création d'un joueur
    Joueur* joueur1= new Joueur("lucas",1000); // Nom : Lucas, Solde initial : 1000
    Joueur* joueur2= new Joueur("Louis",1000); // Nom : Louis, Solde initial : 1000
    Joueur* joueur3= new Joueur("Bastien",1000); // Nom : Bastien, Solde initial : 1000


    //Création d'une case Gare
    Gare Montparnasse("Gare Montparnasse");
    //Création d'un SP
    ServPublic Eau("service des eaux");
    //Création d'un terrain
    int loyer[5]={-5,-10,-20,-30,-50};
    Terrain* RueDeLaPaix= new Terrain("rue de la paix", 400, loyer);
    //Création de la couleur BleuFoncé
    Couleur BleuFonce({RueDeLaPaix});

    cout << "\nachat de rue de la paix par Lucas\n";
    cout << "Solde de Lucas :" << joueur1->getSolde() << endl;
    cout << RueDeLaPaix->getProprio() << endl;
    RueDeLaPaix->achat(joueur1);
    cout << RueDeLaPaix->getProprio() << endl;
    cout << "Solde de Lucas :" << joueur1->getSolde() << endl;

    cout << "\nachat Montparnasse par Lucas\n";
    cout << "Solde de Lucas :" << joueur1->getSolde() << endl;
    cout << Montparnasse.getProprio() << endl;
    Montparnasse.achat(joueur1);
    cout << Montparnasse.getProprio() << endl;
    cout << "Solde de Lucas :" << joueur1->getSolde() << endl;

    cout << "\nachat la compagnie des eaux par Lucas\n";
    cout << "Solde de Lucas :" << joueur1->getSolde() << endl;
    cout << Eau.getProprio() << endl;
    Eau.achat(joueur1);
    cout << Eau.getProprio() << endl;
    cout << "Solde de Lucas :" << joueur1->getSolde() << endl;

    cout << "\nSolde de Louis :" << joueur2->getSolde() << endl;
    cout << "Louis tombe sur Montparnasse\n";
    joueur2->setSolde(Montparnasse.tarif(joueur1));
    cout << "Solde de Louis :" << joueur2->getSolde() << endl;

    cout << "\nSolde de Louis :" << joueur2->getSolde() << endl;
    cout << "Louis tombe sur le service des eaux\n";
    joueur2->setSolde(Eau.tarif(joueur1, 5, 8));
    cout << "Solde de Louis :" << joueur2->getSolde() << endl;

    cout << "\nSolde de Louis :" << joueur2->getSolde() << endl;
    cout << "Louis tombent sur rue de la paix\n";
    joueur2->setSolde(RueDeLaPaix->loyer());
    cout << "Solde de Louis :" << joueur2->getSolde() << endl;

    cout << "\nRue de la paix avant mise a jour d'achat\n Constructible ? oui=1 non=0\n";
    cout << RueDeLaPaix->getConstructible() <<endl;
    cout << "Mise a jour : ...\n";
    BleuFonce.miseAJour();
    cout << "Rue de la paix après mise a jour d'achat\n Constructible ? oui=1 non=0\n";
    cout << RueDeLaPaix->getConstructible() <<endl;

    cout << "\nLucas rajoute 4 maison sur rue de la paix\n";
    cout << "Nombre de maison sur rue de la paix : " << RueDeLaPaix->getNbMaison() <<endl;
    RueDeLaPaix->acahtImmo(4);
    cout << "Nombre de maison sur rue de la paix : " << RueDeLaPaix->getNbMaison() <<endl;

    cout << "\nSolde de Louis :" << joueur2->getSolde() << endl;
    cout << "Louis tombent sur rue de la paix avec une maison\n";
    joueur2->setSolde(RueDeLaPaix->loyer());
    cout << "Solde de Louis :" << joueur2->getSolde() << endl;
    


    return 0;
}
