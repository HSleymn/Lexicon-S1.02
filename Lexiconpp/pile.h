//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_PILE_H
#define LEXICONPP_PILE_H

#include "carte.h"

struct Pile {
    unsigned int capacite;  // capacité de la pile (c>0)
    Carte* tab;				// tableau des éléments de pile en mémoire dynamique
    int sommet;				// indice de sommet de pile dans tab

};

#endif //LEXICONPP_PILE_H
