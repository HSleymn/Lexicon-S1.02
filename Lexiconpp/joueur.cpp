//
// Created by PC on 09/12/2023.
//

#include "joueur.h"
#include "iostream"
#define nombreDeCarte 52
#define nombreDeCarteJoueur 10

/*
 * @media
 *
 * */
void initialiserLaMainDuJoueur(Joueur& joueur, const jeuDeCarte jeuMelange){
    for (int compteur = 0; compteur < nombreDeCarteJoueur; ++compteur){
        joueur.mainDuJoueur[compteur] = jeuMelange.cartes[compteur];
    }
}

void initialiserLesJoueurs(Joueurs& lesJoueurs, const unsigned int nombreDeJoueurs, jeuDeCarte jeuMelange){
    lesJoueurs.nbJoueursTotal = lesJoueurs.nbJoueursEnLice = nombreDeJoueurs;
    lesJoueurs.tabJoueurs = new Joueur[nombreDeJoueurs];
    jeuDeCarte jeutmp;
    for (int compteur=0; compteur < nombreDeJoueurs; ++compteur){
        std::cout << "cacaaaa" << std::endl;
        std::cout << "le joueur " << compteur << " a pour cartes"<< std::endl;
        jeutmp.cartes  = new Carte[nombreDeCarteJoueur];
        unsigned int indiceCarte = compteur*10;
        for (int carteCompteur=0; carteCompteur < nombreDeCarteJoueur; carteCompteur++ ){
            jeutmp.cartes[indiceCarte] = jeuMelange.cartes[indiceCarte];
            std::cout << jeutmp.cartes[indiceCarte].lettre << std::endl;
            ++indiceCarte;
        }

        delete[] jeutmp.cartes;
        std::cout << "caca" << std::endl;

    }
};