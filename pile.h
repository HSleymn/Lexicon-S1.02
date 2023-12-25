//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_PILE_H
#define LEXICONPP_PILE_H

#include "carte.h"

struct Pile{
    int capacite;  // capacité de la pile (c>0)
    Carte* tab;				// tableau des éléments de pile en mémoire dynamique
    int sommet;				// indice de indiceSommet de pile dans tab

};
void initialiser(Pile& pileDeCartes, const unsigned int nombreDeCarteRestant );

bool estVide(const Pile& pileDeCartes);

bool estPlein(const Pile& pileDeCartes);

void empiler(Pile& pileDeCartes, const Carte& carte);

void depiler(Pile& pileDeCartes);


#endif //LEXICONPP_PILE_H
