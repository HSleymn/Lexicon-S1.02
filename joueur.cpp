//
// Created by PC on 09/12/2023.
//

#include "joueur.h"
#include "iostream"
#define nombreDeCarte 51
#define nombreDeCarteJoueur 10

/*
 * @media
 *
 * */
void initialiserLaMainDuJoueur(Joueur& joueur, const jeuDeCarte jeuMelange){
    joueur.nombreDeCartesEnMain = nombreDeCarteJoueur;
    for (int compteur = 0; compteur < nombreDeCarteJoueur; ++compteur){
        joueur.mainDuJoueur[compteur] = jeuMelange.cartes[compteur];
    }
}

void initialiserLesJoueurs(Joueurs& lesJoueurs, const unsigned int nombreDeJoueurs, jeuDeCarte jeuMelange){
    lesJoueurs.nbJoueursTotal = lesJoueurs.nbJoueursEnLice = nombreDeJoueurs;
    lesJoueurs.tabJoueurs = new Joueur[nombreDeJoueurs];
    jeuDeCarte jeutmp;
    for (int compteur=0; compteur < nombreDeJoueurs; ++compteur){
        lesJoueurs.tabJoueurs[compteur].idJoueur = compteur +1;
        lesJoueurs.tabJoueurs[compteur].nombreDePoints =0;
        jeutmp.cartes  = new Carte[nombreDeCarteJoueur];
        unsigned int indiceCarte = compteur*10;
        for (int carteCompteur=0; carteCompteur < nombreDeCarteJoueur; carteCompteur++ ){
            jeutmp.cartes[carteCompteur] = jeuMelange.cartes[indiceCarte];
            ++indiceCarte;
        }
        initialiserLaMainDuJoueur(lesJoueurs.tabJoueurs[compteur], jeutmp);
        detruireJeuDeCarte(jeutmp);

    }
};