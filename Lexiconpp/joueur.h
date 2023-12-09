//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_JOUEUR_H
#define LEXICONPP_JOUEUR_H

#include "carte.h"
struct Joueur{
    unsigned int idJoueur;
    unsigned int nombreDePoints;
    Carte jeuDeCarte[];
};

struct Joueurs{
    Joueur* tabJoueurs;
    unsigned int nbJoueursTotal;
    unsigned int nbJoueursEnLice;
};


#endif //LEXICONPP_JOUEUR_H
