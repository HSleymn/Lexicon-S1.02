#ifndef LEXICONPP_TALON_H
#define LEXICONPP_TALON_H
#include "carte.h"

struct Pile_Talon {
    int capacite;
    Carte* tab;		
    int indiceSommet;

};

void initialiser(Pile_Talon& pileDuTalon, const unsigned int nombreDeCarteRestant);

bool estVide(const Pile_Talon& pileDuTalon);

void empiler(Pile_Talon& pileDuTalon, const Carte& carte);

void depiler(Pile_Talon& pileDuTalon);

#endif


