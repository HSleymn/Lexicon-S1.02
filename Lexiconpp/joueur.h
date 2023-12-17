//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_JOUEUR_H
#define LEXICONPP_JOUEUR_H
#include "carte.h"
#define nombreDeCarteJoueur 10
struct Joueur{
    unsigned int idJoueur;
    unsigned int nombreDePoints;
    Carte mainDuJoueur[nombreDeCarteJoueur];
};

struct Joueurs{
    Joueur* tabJoueurs;
    unsigned int nbJoueursTotal;
    unsigned int nbJoueursEnLice;
};
void initialiserLaMainDuJoueur(Joueur& joueur, const jeuDeCarte jeuMelange);
void initialiserLesJoueurs(Joueurs& lesJoueurs, const unsigned int nombreDeJoueurs, jeuDeCarte jeuMelange );


#endif //LEXICONPP_JOUEUR_H
