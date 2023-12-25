
// program named mainreturn.cpp
#include <iostream>
#include "carte.h"
#include "joueur.h"
#include "talonEtExposee.h"

#include <typeinfo>




//    defining main with arguments
int main(int argc, char** argv)
{
    unsigned int nbJoueurs = atoi(argv[1]);
    jeuDeCarte jeuDeCartes;
    initialiserJeuDeCarte(jeuDeCartes);
    Joueurs joueurs;
    initialiserLesJoueurs(joueurs, nbJoueurs, jeuDeCartes);
    std::cout << std::endl;
    for (int i=0; i<nbJoueurs; i++){
        for (int j=0; j<nombreDeCarteJoueur; j++)
        std::cout << joueurs.tabJoueurs[i].mainDuJoueur[j].lettre;
        std::cout << std::endl;
    }

    recupererJeuDeCarteRestant(jeuDeCartes, joueurs.nbJoueursEnLice);

    Pile pileDuTalon;
    initialiser(pileDuTalon, jeuDeCartes.capacite);

    Pile pileCartesExposee;
    initialiser(pileCartesExposee, jeuDeCartes.capacite);

    remplirTalonEtExposee(pileDuTalon, pileCartesExposee, jeuDeCartes);

    for (int compteur=0; compteur < pileDuTalon.capacite; compteur++){
        std::cout << pileDuTalon.tab[compteur].lettre;
    }
    std::cout << std::endl << pileCartesExposee.tab[pileCartesExposee.sommet].lettre;
    //affichage

    while(joueurs.nbJoueursEnLice > 1){

        for (int tourDuJoueur = 0; tourDuJoueur < joueurs.nbJoueursEnLice; tourDuJoueur++) {

            std::cout << "* Joueur" << joueurs.tabJoueurs[tourDuJoueur].idJoueur << "(" << pileCartesExposee.tab[pileCartesExposee.sommet].lettre << ") ";
        for (int compteur =0; compteur < joueurs.tabJoueurs[tourDuJoueur].nombreDeCartesEnMain; compteur ++){
            std::cout << joueurs.tabJoueurs[tourDuJoueur].mainDuJoueur[compteur].lettre;
        }
        std::cout << std::endl << "> ";
        std::cout << std::endl;
    }
        std::cout << std::endl;
        empiler(pileCartesExposee, pileDuTalon.tab[pileDuTalon.sommet]);

        depiler(pileDuTalon);
        if (estVide(pileDuTalon)){
            rechargementDuTalon(pileDuTalon, pileCartesExposee);
        }

    }
    }


