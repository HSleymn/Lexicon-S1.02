//
// Created by PC on 09/12/2023.
//

#include "joueur.h"
#define nombreDeCarte 52
#define nombreDeCarteJoueur 10

void initialiserLaMainDuJoueur(Joueur& joueur, const jeuDeCarte jeuMelange){
    for (int compteur = 0; compteur < nombreDeCarteJoueur; ++compteur){
        joueur.mainDuJoueur[compteur] = jeuMelange.cartes[compteur];
    }
}