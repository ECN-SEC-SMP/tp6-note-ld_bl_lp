#include <string>
#include <iostream>



#ifndef CASE_HPP
#define CASE_HPP

using namespace std;
class Case {
    public:
        Case(string nom, int type);
        void setNom(string nom);
        string getNom();
        int getType();

    protected:
        string nom;
        int type;
};

#endif