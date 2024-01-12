//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_JOUEUR_H
#define LEXICONPP_JOUEUR_H
#include "mots.h"
#define nombreDeCarteJoueur 10
struct Joueur{
    unsigned int idJoueur;
    unsigned int nombreDePoints;
    Carte mainDuJoueur[nombreDeCarteJoueur];
    unsigned int nombreDeCartesEnMain;
};

struct Joueurs{
    Joueur* tabJoueurs;
    Joueur* tabJoueursElimines;
    unsigned int nbJoueursTotal;
    unsigned int nbJoueursEnLice;
    unsigned int nbJoueurElimines;
};
void initialiserLaMainDuJoueur(Joueur& joueur, const jeuDeCarte jeuMelange, unsigned int& compteur);
void initialiserLesJoueurs(Joueurs& lesJoueurs, const unsigned int nombreDeJoueurs, jeuDeCarte jeuMelange );
int rechercherDansLaMainDuJoueur(const Joueur& joueur, const char& lettre);
bool verifierDansLesCartesDeLaMainDuJoueur(Joueur& joueur, Mot& mot, int* tableauIndice, int& tailleTableau);
void retirerDansLesCartesDeLaMainDuJoueur(Joueur& joueur, Mot& mot, int* tableauIndice, int& tailleTableau);
int rechercherDansLaMainDuJoueurDoublons(const Joueur& joueur, const char& lettre, int* tableauIndice, int& tailleTableau);
bool rechercherIndice(int& indice,int* tableauIndice, int& tailleTableau);
bool verificationJoueurAEncoreDesCartes(Joueur& joueur);
bool verificationJoueurEnLice(Joueurs& lesJoueurs, Joueur& joueur);
void ajoutPointsFinDeTour(Joueurs& lesJoueurs);
void eliminationJoueur(Joueurs& lesJoueurs, Joueur& joueur);

#endif //LEXICONPP_JOUEUR_H
