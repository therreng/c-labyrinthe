#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include "Salle.h"


class Labyrinthe
{
    public:
        Labyrinthe(int n);
        Labyrinthe(Labyrinthe & L);
        Labyrinthe& operator=(Labyrinthe & L);
        virtual ~Labyrinthe();
        Salle& operator[](int i);
        void initialiser(ifstream& fichier);
    protected:
        int nbsalles;
        Salle* plan;
    private:
        bool is_lettre(char a);
        int chartoint(char c);
};

#endif // LABYRINTHE_H
