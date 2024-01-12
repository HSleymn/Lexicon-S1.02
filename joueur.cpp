//
// Created by PC on 09/12/2023.
//

#include "joueur.h"


/**
 * @brief Initialiser la main du joueur
 * @param[in, out] joueur : le joueur dont on veut remplir la main
 * @param[in] jeuMelange : le jeu d'où on va prendre les cartes
 * @param[in] compteur : le compteur pour savoir quel est le joueur auquel on remplit la main
 */
void initialiserLaMainDuJoueur(Joueur& joueur, const jeuDeCarte jeuMelange, const unsigned int& compteur) {
    joueur.nombreDeCartesEnMain = nombreDeCarteJoueur;
    unsigned int indiceCarte = compteur * 10;
    for (int compteurCartes = 0; compteurCartes < nombreDeCarteJoueur; ++compteurCartes) {
        joueur.mainDuJoueur[compteurCartes] = jeuMelange.cartes[indiceCarte];
        indiceCarte++;
    }
}

/**
 * @brief Initialiser lesJoueurs notamment par :
 * initialiser les variables nbJoueursTotal et nbJoueurElimines
 * pour chaque joueur : initialiser l'idJoueur, le nombre de point et la main
 * @param[out] lesJoueurs : lesJoueurs
 * @param[in] nombreDeJoueurs : explicite.
 * @param[out] jeuMelange : le jeu d'où on va prendre les cartes
 */
void initialiserLesJoueurs(Joueurs& lesJoueurs, const unsigned int nombreDeJoueurs, const jeuDeCarte jeuMelange){
    lesJoueurs.nbJoueursTotal = lesJoueurs.nbJoueursEnLice = nombreDeJoueurs;
    lesJoueurs.tabJoueurs = new Joueur[nombreDeJoueurs];
    lesJoueurs.tabJoueursElimines = new Joueur[nombreDeJoueurs-1];
    lesJoueurs.nbJoueurElimines = 0;
    for (unsigned int compteur=0; compteur < nombreDeJoueurs; ++compteur){
        lesJoueurs.tabJoueurs[compteur].idJoueur = compteur +1;
        lesJoueurs.tabJoueurs[compteur].nombreDePoints =0;
        initialiserLaMainDuJoueur(lesJoueurs.tabJoueurs[compteur], jeuMelange, compteur);
    }
}

/**
 * @brief rechercher dans la main du joueur la présence d'une lettre,
 * si elle est présente on renvoie l'indice de la première carte
 * rencontrée ayant cette lettre, sinon on renvoie -1
 * @param[in] joueur: le joueur en question
 * @param[in] lettre : la lettre a recherché
 */
int rechercherDansLaMainDuJoueur(const Joueur& joueur, const char& lettre){
    for (int compteur =0; compteur < joueur.nombreDeCartesEnMain; compteur++){
        if (joueur.mainDuJoueur[compteur].lettre == lettre){
            return compteur;
        }
    }
    return -1;
}

/**
 * @brief rechercher indice dans un tableau d'indice
 * @param[in] indice :  l'indice à rechercher
 * @param[in] tableauIndice : tableau d'indice
 * @param[in] tailleTableau : taille du tableau
 */
bool rechercherIndice(const int& indice,const int* tableauIndice, const int& tailleTableau){
    for(int compteur=0; compteur < tailleTableau; compteur++){
        if(tableauIndice[compteur]==indice){
            return true;
        }
    }
    return false;
}

/**
 * @brief rechercher dans la main du joueur un lettre excluant les doublons,
 * et renvoyant, selon le contexte, l'indice correct,
 * si elle n'existe pas ou qu'il y en ait plus,  elle renvoie -1
 * @param[in] joueur : joueur en question
 * @param[in] lettre : la lettre qu'on recherche
 * @param[in] tableauIndice : le tableau d'indice remplis d'indice de cartes déjà parcourues
 * @param[in] tailleTableau : taille de ce tableau
 */
int rechercherDansLaMainDuJoueurDoublons(const Joueur& joueur, const char& lettre, int* tableauIndice, int& tailleTableau){
    for (int compteur =0; compteur < joueur.nombreDeCartesEnMain; compteur++){
        if (joueur.mainDuJoueur[compteur].lettre == lettre && !rechercherIndice(compteur, tableauIndice, tailleTableau)){
            return compteur;
        }
    }
    return -1;
}

/**
 * @brief Vérifier si toutes les lettres du mot sont présentes dans la main du joueur
 * @param[in] joueur : joueur en question
 * @param[in] mot : le mot qu'on vérifie
 * @param[in] tableauIndice : le tableau d'indice remplis d'indice de cartes déjà parcourues
 * @param[in] tailleTableau : taille de ce tableau
 */
bool verifierDansLesCartesDeLaMainDuJoueur(const Joueur& joueur, const Mot& mot,  int* tableauIndice,  int& tailleTableau){
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

/**
 * @brief retirer de la main du joueur les cartes
 * @param[in] joueur : joueur en question
 * @param[in] mot : mot dont on pioche les lettres
 * @param[in] tableauIndice : le tableau d'indice remplis d'indice de cartes déjà parcourues
 * @param[in] tailleTableau : taille de ce tableau
 */
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

/**
 * @brief Vérifier si le joueur a encore des cartes, renvoie true si oui, false si non
 * @param[in] joueur : joueur en question
 */
bool verificationJoueurAEncoreDesCartes(Joueur& joueur){
    if(joueur.nombreDeCartesEnMain == 0)
        return false;

    else
        return true;
}

/**
 * @brief Vérifier si le joueurs est toujours en lice ou non, renvoie false si non, true si oui
 * @param[in] lesJoueurs : accès a la tabJoueursElimines
 * @param[in] joueur : le joueur en question
 */
bool verificationJoueurEnLice(Joueurs& lesJoueurs, Joueur& joueur){
    for(int compteur=0; compteur < lesJoueurs.nbJoueurElimines; compteur++){
        if(lesJoueurs.tabJoueursElimines[compteur].idJoueur == joueur.idJoueur)
            return false;
    }
    return true;
}

/**
 * @brief Ajouter les points aux joueurs à la fin du tour en fonction des cartes qui leurs restent
 * @param[in] lesJoueurs : accès a la tabJoueurs
 */
void ajoutPointsFinDeTour(Joueurs& lesJoueurs){
    for(int compteurJoueur=0; compteurJoueur < lesJoueurs.nbJoueursTotal; compteurJoueur++){
        if(verificationJoueurEnLice(lesJoueurs, lesJoueurs.tabJoueurs[compteurJoueur])){
            for(int compteurCartes = 0; compteurCartes < lesJoueurs.tabJoueurs[compteurJoueur].nombreDeCartesEnMain; compteurCartes++){
                lesJoueurs.tabJoueurs[compteurJoueur].nombreDePoints += lesJoueurs.tabJoueurs[compteurJoueur].mainDuJoueur[compteurCartes].nb_points;
            }
        }
    }
}

/**
 * @brief Fonction qui élimine un joueur en l'ajoutant dans la tabJoueursElimine
 * @param[in] lesJoueurs : accès a tabJoueursElimines
 * @param[in] joueur : le joueur en question
 */
void eliminationJoueur(Joueurs& lesJoueurs, Joueur& joueur){
    if(verificationJoueurEnLice(lesJoueurs, joueur)) {
        lesJoueurs.nbJoueursEnLice--;
        lesJoueurs.tabJoueursElimines[lesJoueurs.nbJoueurElimines] = joueur;
        lesJoueurs.nbJoueurElimines++;
    }

}