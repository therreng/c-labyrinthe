#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Salle.h"
#include "Labyrinthe.h"

class Personnage
{
    public:
        Personnage(int s=0,int dir=2, int nbobj=0);
        ~Personnage();
        int& getSalle();
        int getDirection();
        void progression(Labyrinthe&, int choix);

    private:
        int salle; //salle où se trouve le personnage
        int direction; //La direction est plus facile à stocker sous forme d'un entier 0=Nord et sens des aiguilles d'une montre
        int nbobjets;
        string objets[2];

};

#endif // PERSONNAGE_H
