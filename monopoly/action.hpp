#ifndef ACTION_HPP
#define ACTION_HPP

#include "case.hpp"
#include "joueur.hpp" // Assurez-vous d'avoir cette classe définie dans joueur.hpp

class Action : public Case {
public:
    Action(const string& nom);

};

#endif // ACTION_HPP