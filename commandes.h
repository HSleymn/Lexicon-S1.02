//
// Created by PC on 25/12/2023.
//

#ifndef LEXICON_S1_02_COMMANDES_H
#define LEXICON_S1_02_COMMANDES_H
#include <cstdint>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>

#include "pile.h"

#define ETAT_DE_BASE 1
#define ENTREE_VALIDE 0
#define ENTREE_INVALIDE -1
#define MOT_INVALIDE -2

struct Commande
{
    char nomDeLaCommande;
    char lettreDeLaCarte;
    char mot[26];
    int designationMot;
};

int detectionDeLaCommande(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots);
int LectureCommande(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istream& is, TabMots& tabMots);
int detectionDeLaCommandeTE(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is);
void commandeTE(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande);
int detectionDeLaCommandeP(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is);
int commandeP(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is,TabMots& tabMots);
int detectionDeLaCommandeR(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is);
int commandeR(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots);
int detectionDeLaCommandeC(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is);
int commandeC(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots);

#endif //LEXICON_S1_02_COMMANDES_H
