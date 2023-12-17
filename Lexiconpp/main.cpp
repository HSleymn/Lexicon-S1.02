
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
        nbJoueurs = 3;
      jeuDeCarte caca;
      initialiserJeuDeCarte(caca);
     Joueurs joueurs;
     initialiserLesJoueurs(joueurs,nbJoueurs, caca);
    cout <<"CACA AU MAX " ;
    return 0;
}
