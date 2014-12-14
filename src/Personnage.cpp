#include<iostream>

#include "Personnage.h"

Personnage::Personnage(int s, int dir, int nbobj)
{
    salle=s;
    direction=dir;
    nbobjets=nbobj;
}

Personnage::~Personnage(){}

int& Personnage::getSalle(){
    return salle;
}

int Personnage::getDirection(){
    return direction;
}

void Personnage::progression(Labyrinthe& plateau, int choix){
    int k=0;

    for(int i=1;i<5;i++){
        if(plateau[salle].getPorte((i+direction)%4).arrivee!=-1){k++;
                if(k==choix){
                    couloir coul=plateau[salle].getPorte((i+direction)%4);
                    salle=coul.arrivee;
                    direction=Labyrinthe::chartoint(coul.direction);
                        }
                    }
            }

            //Si le choix ne correspond pas à une porte, c'est que l'utilisateur a pris l'objet de la salle.
            if(k<choix){
                    string objetSalle=plateau[salle].getObjet();
                    objets[nbobjets]=objetSalle;
                    if(nbobjets<2){nbobjets=2;}
                    cout<<"Vous avez pris l'objet "<<objetSalle;
            }
}


