#include <iostream>
#include "carte.h"
#include "talon.h"
#include <cassert>


void initialiser(Pile_Talon& pileDuTalon, const unsigned int nombreDeCarteRestant ){
    assert(nombreDeCarteRestant>0);
    pileDuTalon.capacite = nombreDeCarteRestant;
    pileDuTalon.tab = new Carte[nombreDeCarteRestant];
    pileDuTalon.indiceSommet = -1;
}

bool estVide(const Pile_Talon& pileDuTalon){
    return pileDuTalon.indiceSommet == -1;
}

bool estPlein(const Pile_Talon& pileDuTalon){
    return pileDuTalon.indiceSommet == pileDuTalon.capacite;
}

void empiler(Pile_Talon& pileDuTalon, const Carte& carte){
    std::cout << "coconut";
    assert(!estPlein(pileDuTalon));
    pileDuTalon.indiceSommet++;
    pileDuTalon.tab[pileDuTalon.indiceSommet] = carte;
}

void depiler(Pile_Talon& pileDuTalon){
        assert(!estVide(pileDuTalon));
        pileDuTalon.indiceSommet--;
}