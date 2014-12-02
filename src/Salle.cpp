#include "Salle.h"
#include<string>
#include<cstdlib>
#include<iostream>

using namespace std;

Salle::Salle()
{
    for(int i=0;i<4;i++){
            portes[i].arrivee=-1;
    }
    objet="";
}


Salle::Salle(Salle& S)//constructeur de copie
{
    for(int i=0;i<4;i++){
        portes[i]=S.portes[i];
    }
    objet=S.objet;
}
Salle::~Salle()
{
}

void Salle::afficher(int j){
    string Dir[4]={"Nord", "Est", "Sud","Ouest"};
    for(int i=0;i<4;i++){
        if(portes[(i+j)%4].arrivee!=-1){cout<<"il y a une porte sur le mur "<<Dir[(i+j)%4]<<endl;}
    }
    if(objet!=""){cout<<"il y a également "<<objet<<endl;}
}



//void Salle::afficher(int j){
//    for(int i=0;i<4;i++){cout<<portes[i].arrivee<<" "<<portes[i].direction<<endl;}
//}


void Salle::affecter(int i, couloir C){//affecter le couloir C à la porte i
    {portes[i%4]=C;}
}
