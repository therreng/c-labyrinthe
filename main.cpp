#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<limits>
#include "Salle.h"
#include "Labyrinthe.h"

using namespace std;

int nombresalles(ifstream & fichier);

int ouvrir(char* chemin);

int main(int argc, char* argv[]){
    if(argc==1){cerr<<"Veuillez spécifier un fichier plan à lire"<<endl;
                return 0;
    }
    char* chemin=argv[1];
    cout<<ouvrir(chemin)<<endl;

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

int ouvrir(char* chemin){
// ouvre le fichier dont le nom est donné par char
    int i=0;
    ifstream fichier(chemin, ios::in);
    //on essaye d'ouvrir le fichier nommé chemin en lecture. fichier est le nom du flux
    if(fichier){
        i=nombresalles(fichier);
        Labyrinthe plateau(i);
        plateau.initialiser(fichier);
        for(int k=0;k<3;k++){
                cout<<"Salle "<<k<<endl;
            plateau[k].afficher();
        }
        fichier.close();
    }
    else{cerr << "Impossible d'ouvrir ce fichier"<<endl;}
    return i;
}
