
// program named mainreturn.cpp
#include <iostream>
#include "carte.h"
#include "joueur.h"
#include <typeinfo>
using namespace std;




//    defining main with arguments
int main(int argc, char** argv)
{
        unsigned int nbJoueurs = atoi(argv[1]);
      jeuDeCarte caca;
      initialiserJeuDeCarte(caca);
     Joueurs joueurs;
     initialiserLesJoueurs(joueurs,nbJoueurs, caca);
     cout << endl;
    for (int i=0; i<nbJoueurs; i++){
        for (int j=0; j<nombreDeCarteJoueur; j++)
        cout << joueurs.tabJoueurs[i].mainDuJoueur[j].lettre;
        cout << endl;
    }
    return 0;
}
