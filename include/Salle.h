#ifndef SALLE_H
#define SALLE_H
#include<cstdlib>
#include<string>

using namespace std;

typedef struct {
    int arrivee;
    char direction;
} couloir;

class Salle
{
    public:
        Salle();
        Salle(Salle & S);
        virtual ~Salle();
        void affecter(int i, couloir C);
        void afficher(int j=0);

    private:
        couloir portes[4];
        string objet;
};

#endif // SALLE_H
