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

int Salle::afficher(int j){
    string Dir[4]={"Nord", "Est", "Sud","Ouest"};
    int k=0;//nombre de choix offert au joueur
    for(int i=1;i<5;i++){
        if(portes[(i+j)%4].arrivee!=-1){
                k++;
                cout<<k<<". il y a une porte sur le mur "<<Dir[(i+j)%4]<<endl;
        }
    }
    if(objet!=""){
            k++;
            cout<<k<<". il y a également "<<objet<<endl;
    }
    k++;
    cout<<k<<". Arrêter le jeu."<<endl;
    return k;
}



//void Salle::afficher(int j){
//    for(int i=0;i<4;i++){cout<<portes[i].arrivee<<" "<<portes[i].direction<<endl;}
//}


couloir Salle::getPorte(int i){
    if(i>4){cerr<<"Couloir non valide"<<endl;}
    else{return portes[i];}
}

string Salle::getObjet()const{return objet;}

void Salle::affecter(int i, couloir C){//affecter le couloir C à la porte i
    {portes[i%4]=C;}
}
