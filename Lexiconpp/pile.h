//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_PILE_H
#define LEXICONPP_PILE_H

#include "item.h"

struct Pile {
    unsigned int capacite;  // capacité de la pile (c>0)
    Item* tab;				// tableau des éléments de pile en mémoire dynamique
    int sommet;				// indice de sommet de pile dans tab
    unsigned int pasExtension; // pas d'extension du conteneur (>0)

};

#endif //LEXICONPP_PILE_H
