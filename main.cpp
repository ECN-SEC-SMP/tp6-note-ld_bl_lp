#include <iostream>
#include"joueur.hpp"

using namespace std;

int main() {
    cout << "Hello1, CMake!" << endl;

    Joueur joueur1 = Joueur(200);
    
    cout << joueur1.getEnPrison()<< endl;
    joueur1.setEnPrison(10);
    cout << joueur1.getEnPrison()<< endl;

    return 0;

}

