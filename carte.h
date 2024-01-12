//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_CARTE_H
#define LEXICONPP_CARTE_H
#define nombreDeCarte 51
#include <iostream>
#include "ctime"


struct Carte{
    unsigned int nb_points;
    char lettre;
};

struct jeuDeCarte{
    Carte* cartes;
    unsigned int capacite;
};
void initialiserJeuDeCarte(jeuDeCarte& jeu);
void melangerJeuDeCarte(jeuDeCarte& jeu);
void detruireJeuDeCarte(jeuDeCarte& jeu);
void recupererJeuDeCarteRestant(jeuDeCarte& jeu, unsigned int nombreDeJoeursEnLice);
void ajouterPointsPourCartes(Carte& carte);


#endif //LEXICONPP_CARTE_H
