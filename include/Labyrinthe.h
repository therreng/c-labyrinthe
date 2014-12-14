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
        static int chartoint(char c);
    protected:
        int nbsalles;
        Salle* plan;
    private:
        bool is_lettre(char a);

};

#endif // LABYRINTHE_H
