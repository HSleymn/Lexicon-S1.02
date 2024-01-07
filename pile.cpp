//
// Created by PC on 09/12/2023.
//
#include "pile.h"

#include <iostream>
#include <cassert>

void initialiser(Pile& pileDeCartes, const unsigned int nombreDeCarteRestant ){
    assert(nombreDeCarteRestant>0);
    pileDeCartes.capacite = nombreDeCarteRestant;
    pileDeCartes.tab = new Carte[nombreDeCarteRestant];
    pileDeCartes.sommet = -1;
}

bool estVide(const Pile& pileDeCartes){
    return pileDeCartes.sommet == -1;
}

bool estPlein(const Pile& pileDeCartes){
    return pileDeCartes.sommet >= pileDeCartes.capacite;
}

void empiler(Pile& pileDeCartes, const Carte& carte){
    assert(!estPlein(pileDeCartes));
    pileDeCartes.sommet++;
    pileDeCartes.tab[pileDeCartes.sommet] = carte;
}

void depiler(Pile& pileDesCartesExposees){
    assert(!estVide(pileDesCartesExposees));
    pileDesCartesExposees.sommet--;
}
void detruire(Pile& pile){
    delete [] pile.tab;
}