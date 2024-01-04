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
}

int rechercherDansLaMainDuJoueur(const Joueur& joueur, const char& lettre){
    for (int compteur =0; compteur < joueur.nombreDeCartesEnMain; compteur++){
        if (joueur.mainDuJoueur[compteur].lettre == lettre){
            return compteur;
        }
    }
    return -1;
}
bool rechercherIndice(int& indice,int* tableauIndice, int& tailleTableau){
    for(int compteur=0; compteur < tailleTableau; compteur++){
        if(tableauIndice[compteur]==indice){
            return true;
        }
    }
    return false;
}

int rechercherDansLaMainDuJoueurDoublons(const Joueur& joueur, const char& lettre, int* tableauIndice, int& tailleTableau){
    for (int compteur =0; compteur < joueur.nombreDeCartesEnMain; compteur++){
        if (joueur.mainDuJoueur[compteur].lettre == lettre && !rechercherIndice(compteur, tableauIndice, tailleTableau)){
            return compteur;
        }
    }
    return -1;
}


bool verifierDansLesCartesDeLaMainDuJoueur(Joueur& joueur, Mot& mot, int* tableauIndice, int& tailleTableau){
    int pdc;
    int indiceLettre;
    for (int compteurMot=0; compteurMot < mot.taille; compteurMot++){
        indiceLettre = rechercherDansLaMainDuJoueurDoublons(joueur, mot.word[compteurMot], tableauIndice, tailleTableau);
        if(indiceLettre == -1)
            return false;

        tableauIndice[tailleTableau]= indiceLettre;
        tailleTableau++;
    }

    for (int i=0; i<tailleTableau; i++)
    if(mot.taille == tailleTableau)
        return true;
    else
        return false;
}

void retirerDansLesCartesDeLaMainDuJoueur(Joueur& joueur, Mot& mot, int* tableauIndice, int& tailleTableau){
    jeuDeCarte jeutmp;
    jeutmp.cartes = new Carte[joueur.nombreDeCartesEnMain-mot.taille];
    jeutmp.capacite = joueur.nombreDeCartesEnMain-mot.taille;
    int indicetmp =0;
    int verification=0;
    for(int compteurCartesJoueur=0; compteurCartesJoueur < joueur.nombreDeCartesEnMain; compteurCartesJoueur++){
        verification=0;
        for (int compteurTableauIndice=0; compteurTableauIndice < tailleTableau; compteurTableauIndice++)
            if (compteurCartesJoueur == tableauIndice[compteurTableauIndice]){
                verification=1;
            }
        if (verification==0){
    jeutmp.cartes[indicetmp] = joueur.mainDuJoueur[compteurCartesJoueur];
    indicetmp++;}}
    for(int compteur=0; compteur<jeutmp.capacite; compteur++){
        joueur.mainDuJoueur[compteur] = jeutmp.cartes[compteur];
    }
    joueur.nombreDeCartesEnMain = jeutmp.capacite;

}