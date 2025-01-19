#include <string>
#include <iostream>



#ifndef CASE_HPP
#define CASE_HPP

using namespace std;
class Case {
    public:
        Case(string nom);
        void setNom(string nom);
        string getNom();

    protected:
        string nom;
};

#endif