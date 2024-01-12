//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_JOUEUR_H
#define LEXICONPP_JOUEUR_H
#include "mots.h"
#define nombreDeCarteJoueur 10

/**
 * Type joueur contenant:
 * l'id du joueur
 * son nombre de points
 * sa main composé de 10 carte (un tableau de 10 carte)
 * et le nombre de carte qu'il a en main
 */
 struct Joueur{
    unsigned int idJoueur;
    unsigned int nombreDePoints;
    Carte mainDuJoueur[nombreDeCarteJoueur];
    unsigned int nombreDeCartesEnMain;
};

/**
 * Type Joueurs contenant:
 * un tableau tabJoueurs en allocation dynamique contenant les joueurs
 * un tableau tabJoueursElimines en allocation dynamique contenant les joueurs éliminés
 * le nombre de joueurs au total
 * le nombre de joueurs toujours en lice
 * le nombre de joueurs éliminés
*/
struct Joueurs{
    Joueur* tabJoueurs;
    Joueur* tabJoueursElimines;
    unsigned int nbJoueursTotal;
    unsigned int nbJoueursEnLice;
    unsigned int nbJoueurElimines;
};

/**
 * @brief Initialiser la main du joueur
 * @param[in, out] joueur : le joueur dont on veut remplir la main
 * @param[in] jeuMelange : le jeu d'où on va prendre les cartes
 * @param[in] compteur : le compteur pour savoir quel est le joueur auquel on remplit la main
 */
void initialiserLaMainDuJoueur(Joueur& joueur, const jeuDeCarte jeuMelange, const unsigned int& compteur);

/**
 * @brief Initialiser lesJoueurs notamment par :
 * initialiser les variables nbJoueursTotal et nbJoueurElimines
 * pour chaque joueur : initialiser l'idJoueur, le nombre de point et la main
 * @param[out] lesJoueurs : lesJoueurs
 * @param[in] nombreDeJoueurs : explicite.
 * @param[out] jeuMelange : le jeu d'où on va prendre les cartes
 */
void initialiserLesJoueurs(Joueurs& lesJoueurs, const unsigned int nombreDeJoueurs, const jeuDeCarte jeuMelange );

/**
 * @brief rechercher dans la main du joueur la présence d'une lettre,
 * si elle est présente on renvoie l'indice de la première carte
 * rencontrée ayant cette lettre, sinon on renvoie -1
 * @param[in] joueur: le joueur en question
 * @param[in] lettre : la lettre a recherché
 */
int rechercherDansLaMainDuJoueur(const Joueur& joueur, const char& lettre);

/**
 * @brief rechercher indice dans un tableau d'indice
 * @param[in] indice :  l'indice à rechercher
 * @param[in] tableauIndice : tableau d'indice
 * @param[in] tailleTableau : taille du tableau
 */
bool rechercherIndice(const int& indice,const int* tableauIndice, const int& tailleTableau);

/**
 * @brief rechercher dans la main du joueur un lettre excluant les doublons,
 * et renvoyant, selon le contexte, l'indice correct,
 * si elle n'existe pas ou qu'il y en ait plus,  elle renvoie -1
 * @param[in] joueur : joueur en question
 * @param[in] lettre : la lettre qu'on recherche
 * @param[in] tableauIndice : le tableau d'indice remplis d'indice de cartes déjà parcourues
 * @param[in] tailleTableau : taille de ce tableau
 */
int rechercherDansLaMainDuJoueurDoublons(const Joueur& joueur, const char& lettre, int* tableauIndice, int& tailleTableau);

/**
 * @brief Vérifier si toutes les lettres du mot sont présentes dans la main du joueur
 * @param[in] joueur : joueur en question
 * @param[in] mot : le mot qu'on vérifie
 * @param[in] tableauIndice : le tableau d'indice remplis d'indice de cartes déjà parcourues
 * @param[in] tailleTableau : taille de ce tableau
 */
bool verifierDansLesCartesDeLaMainDuJoueur(const Joueur& joueur, const Mot& mot, int* tableauIndice, int& tailleTableau);

/**
 * @brief retirer de la main du joueur les cartes
 * @param[in] joueur : joueur en question
 * @param[in] mot : mot dont on pioche les lettres
 * @param[in] tableauIndice : le tableau d'indice remplis d'indice de cartes déjà parcourues
 * @param[in] tailleTableau : taille de ce tableau
 */
void retirerDansLesCartesDeLaMainDuJoueur(Joueur& joueur, Mot& mot, int* tableauIndice, int& tailleTableau);

/**
 * @brief Vérifier si le joueur a encore des cartes, renvoie true si oui, false si non
 * @param[in] joueur : joueur en question
 */
bool verificationJoueurAEncoreDesCartes(Joueur& joueur);

/**
 * @brief Vérifier si le joueurs est toujours en lice ou non, renvoie false si non, true si oui
 * @param[in] lesJoueurs : accès a la tabJoueursElimines
 * @param[in] joueur : le joueur en question
 */
bool verificationJoueurEnLice(Joueurs& lesJoueurs, Joueur& joueur);
/**
 * @brief Ajouter les points aux joueurs à la fin du tour en fonction des cartes qui leurs restent
 * @param[in] lesJoueurs : accès a la tabJoueurs
 */

void ajoutPointsFinDeTour(Joueurs& lesJoueurs);

/**
 * @brief Fonction qui élimine un joueur en l'ajoutant dans la tabJoueursElimine
 * @param[in] lesJoueurs : accès a tabJoueursElimines
 * @param[in] joueur : le joueur en question
 */
void eliminationJoueur(Joueurs& lesJoueurs, Joueur& joueur);

#endif //LEXICONPP_JOUEUR_H
