//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_PILE_H
#define LEXICONPP_PILE_H

#include "carte.h"

struct Pile {
    unsigned int capacite;  // capacité de la pile (c>0)
    Carte* tab;				// tableau des éléments de pile en mémoire dynamique
    int sommet;				// indice de indiceSommet de pile dans tab

};
void initialiser(Pile& Pile_Exposee, unsigned int c);


#endif //LEXICONPP_PILE_H
