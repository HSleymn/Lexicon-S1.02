#include <iostream>
#include "carte.h"
#include "joueur.h"
#include <typeinfo>
#include <cassert>
#include "exposes.h"

void initialiser(Pile_Exposee& pileDesCartesExposees, const unsigned int nombreDeCarteRestant ){
    assert(nombreDeCarteRestant>0);
    pileDesCartesExposees.capacite = nombreDeCarteRestant;
    pileDesCartesExposees.tab = new Carte[nombreDeCarteRestant];
    pileDesCartesExposees.sommet = -1;
}

bool estVide(const Pile_Exposee& pileDesCartesExposees){
    return pileDesCartesExposees.capacite == 0;
}

bool estPlein(const Pile_Exposee& pileDesCartesExposees){
    return pileDesCartesExposees.sommet < pileDesCartesExposees.capacite-1;
}

void empiler(Pile_Exposee& pileDesCartesExposees, const Carte& carte){
    assert(!estPlein(pileDesCartesExposees));
    pileDesCartesExposees.sommet++;
    pileDesCartesExposees.tab[pileDesCartesExposees.sommet] = carte;
}

void depiler(Pile_Exposee& pileDesCartesExposees){
    assert(!estVide(pileDesCartesExposees));
    pileDesCartesExposees.sommet--;
}