//
// Created by PC on 26/12/2023.
//

#ifndef LEXICON_S1_02_MOTS_H
#define LEXICON_S1_02_MOTS_H
#include "iostream"
#include <sstream>
#include <iostream>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cstring>
#include <cassert>
struct Mot{
    char* word;
    int taille;
    int pasExtension;
    int idMot;
};

struct TabMots{
    Mot* tableauDeMots;
    int taille;
    int indiceDernierMot;
    int pasExtension;
};

void initialiser(Mot& leMot, int taille, int pasDExtension);
void detruire(char* mot);
int ecrire(Mot& leMot, std::istringstream& stream);
bool rechercheMotDansLeDictionnaire(Mot& mot);
void initialiserTableauDeMot(TabMots& tabMots, int taille, int pasExtension);
void ajouterMot(TabMots& tabMots, Mot& mot);
void afficherTableauMot(TabMots& tabMots);
bool comparerLettres(char& premiereLettre, char& deuxiemeLettre);
void miseAJourMots(TabMots tabMots, Mot& mot, int indice);
bool verificationValiditeMotPourCompleter(Mot& premierMot, Mot& deuxiemeMot);

#endif //LEXICON_S1_02_MOTS_H
