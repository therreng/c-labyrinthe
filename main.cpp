#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<limits>
#include "Salle.h"
#include "Labyrinthe.h"
#include "Personnage.h"

// coucou Thomas



using namespace std;



int nombresalles(ifstream & fichier);


int main(int argc, char* argv[]){
    if(argc==1){cerr<<"Veuillez spécifier un fichier plan à lire"<<endl;
                return 0;
    }
    char* chemin=argv[1];
    int NbSalles;
    ifstream fichier(chemin, ios::in);
    //on essaye d'ouvrir le fichier nommé chemin en lecture. fichier est le nom du flux
    if(!fichier){cerr << "Impossible d'ouvrir ce fichier"<<endl;return 0;}

    NbSalles=nombresalles(fichier);
    Labyrinthe plateau(NbSalles);
    plateau.initialiser(fichier);
    fichier.close();

    Personnage hero(0); // numéro de la salle où se trouve le personnage
    do{
            int s=hero.getSalle();
             if(s==NbSalles-1){
                cout<<"Bravo! Vous avez gagné"<<endl;
                return 0;
            }

        int n;
        int choix;
        cout<<"Salle "<<s<<endl;
        n=plateau[s].afficher(hero.getDirection());
        cout<<"Votre choix : ";
        if(cin>> choix){
            if(choix>n || choix<=0){cout<<"Choix invalide"<<endl;}
            //par défaut le dernier choix est toujours d'arrêter le jeu
            if(choix==n){cout<<"Merci d'avoir joué. A bientôt"<<endl;
                        return 0;}
            else{hero.progression(plateau, choix);}
        }
         else{cerr<<"Choix invalide"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        //si erreur -> vider le cin
        }
    }
    while(1);
    return 0;
}


bool is_lettre(char a){return (a>='a'&&a<='z')||(a>='A'&&a<='Z');}//teste si un caractère est une lettre

int nombresalles(ifstream & fichier){
    int n=0;//On compte le nombre de salles
    string ligne; //déclaration d'une chaine qui contient la ligne lue
    getline(fichier,ligne);//La première ligne n'est pas intéressante
    getline(fichier,ligne);
    while(ligne!="finPlan"){
        if(ligne.size()!=0 && is_lettre(ligne[0])){
        int esp=ligne.find(" ");//emplacement du caractère espace : fin du nom
        int point1=ligne.find(".");//emplacemen du premier point
        int point2=ligne.substr(point1+3).find(".");//emplacement du point après le tiret
        int salle1=atoi(ligne.substr(esp+1,point1-esp-1).c_str());//numéro de la première salle concernée
        int salle2=atoi(ligne.substr(point1+3,point2).c_str());//numéro de la seconde ligne concernée
        if(salle1>n){n=salle1;}
        if(salle2>n){n=salle2;}
        }
        getline(fichier,ligne);
    }
    return n+1; //Les salles sont numérotées de 0 à n
}

