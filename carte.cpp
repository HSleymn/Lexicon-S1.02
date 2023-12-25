//
// Created by PC on 09/12/2023.
//
#include <iostream>
#include "ctime"
#include <cstring>
#include "carte.h"
#include "lettres.h"


#define nombreDeCarte 51

void melangerJeuDeCarte(jeuDeCarte& jeu) {
    Carte carteIntermediaire;
    unsigned int nombreDeCarteAMelanger = jeu.capacite-1;

    do {
        srand(time(0));
        int nombreAleatoire = rand() % nombreDeCarteAMelanger;
        carteIntermediaire = jeu.cartes[nombreAleatoire];
        jeu.cartes[nombreAleatoire] = jeu.cartes[nombreDeCarteAMelanger];
        jeu.cartes[nombreDeCarteAMelanger] = carteIntermediaire;
        --nombreDeCarteAMelanger;
    }while( nombreDeCarteAMelanger > 0);
}

void initialiserJeuDeCarte(jeuDeCarte& jeu) {

    jeu.cartes = new Carte[nombreDeCarte];
    jeu.capacite = nombreDeCarte;
    for (int compteur = 0; compteur < nombreDeCarte; ++compteur) {
        jeu.cartes[compteur].lettre = tableauDeLettres[compteur];
        if (jeu.cartes[compteur].lettre == 'A' || jeu.cartes[compteur].lettre == 'E' ||
            jeu.cartes[compteur].lettre == 'I') {
            jeu.cartes[compteur].nb_points = 10;
        } else if (jeu.cartes[compteur].lettre == 'C' || jeu.cartes[compteur].lettre == 'H' ||
                   jeu.cartes[compteur].lettre == 'K' || jeu.cartes[compteur].lettre == 'M' ||
                   jeu.cartes[compteur].lettre == 'L' || jeu.cartes[compteur].lettre == 'P' ||
                   jeu.cartes[compteur].lettre == 'N' || jeu.cartes[compteur].lettre == 'T' ||
                   jeu.cartes[compteur].lettre == 'O' || jeu.cartes[compteur].lettre == 'W' ||
                   jeu.cartes[compteur].lettre == 'R' || jeu.cartes[compteur].lettre == 'S' ||
                   jeu.cartes[compteur].lettre == 'U' || jeu.cartes[compteur].lettre == 'V'  ) {
            jeu.cartes[compteur].nb_points = 8;
        } else if (jeu.cartes[compteur].lettre == 'D' || jeu.cartes[compteur].lettre == 'J') {
            jeu.cartes[compteur].nb_points = 6;
        } else if (jeu.cartes[compteur].lettre == 'G' || jeu.cartes[compteur].lettre == 'Q' ||
                   jeu.cartes[compteur].lettre == 'Y') {
            jeu.cartes[compteur].nb_points = 4;
        } else if (jeu.cartes[compteur].lettre == 'B' || jeu.cartes[compteur].lettre == 'F' ||
                   jeu.cartes[compteur].lettre == 'X' || jeu.cartes[compteur].lettre == 'Z') {
            jeu.cartes[compteur].nb_points = 2;
        }       }
    melangerJeuDeCarte(jeu);
    int i = 0;
    for (; i < nombreDeCarte; ++i)
        std::cout << "La carte avec comme lettre " << jeu.cartes[i].lettre << " vaut " << jeu.cartes[i].nb_points
                  << std::endl << std::endl;

    std::cout << i;
}

void detruireJeuDeCarte(jeuDeCarte& jeu){
    delete [] jeu.cartes;
}

void recupererJeuDeCarteRestant(jeuDeCarte& jeu, unsigned int nombreDeJoeursEnLice){
    jeuDeCarte jeutmp;
    unsigned int indiceDebutDuJeuInitial = nombreDeJoeursEnLice*10;
    unsigned int nombreDeCartesRestant = nombreDeCarte - indiceDebutDuJeuInitial;
    jeutmp.cartes = new Carte[nombreDeCartesRestant];
    jeutmp.capacite = nombreDeCartesRestant;
    for (int compteur=0; indiceDebutDuJeuInitial < nombreDeCarte; compteur++){
        jeutmp.cartes[compteur] = jeu.cartes[indiceDebutDuJeuInitial];
        indiceDebutDuJeuInitial++;
    }
    detruireJeuDeCarte(jeu);
    jeu.cartes = new Carte[nombreDeCartesRestant];
    for (int compteur = 0; compteur < nombreDeCartesRestant; compteur++){
        jeu.cartes[compteur] = jeutmp.cartes[compteur];
    }
    jeu.capacite = jeutmp.capacite;
}