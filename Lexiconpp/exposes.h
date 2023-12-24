#ifndef LEXICONPP_EXPOSES_H
#define LEXICONPP_EXPOSES_H
#include "carte.h"


struct Pile_Exposee{
    int capacite;
    Carte* tab;		
    int sommet;

};
void initialiser(Pile_Exposee& pileDesCartesExposees, const unsigned int nombreDeCarteRestant );

bool estVide(const Pile_Exposee& pileDesCartesExposees);

bool estPlein(const Pile_Exposee& pileDesCartesExposees);

void empiler(Pile_Exposee& pileDesCartesExposees, const Carte& carte);

void depiler(Pile_Exposee& pileDesCartesExposees);

#endif