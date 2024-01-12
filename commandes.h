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

/**
 * Type commande qui contient tout ce qui est en rapport au flux d'entrées:
 * le no de la commande
 * la lettre
 * le mot
 * la designaton du mot (dans le tabMots)
 */

struct Commande
{
    char nomDeLaCommande;
    char lettreDeLaCarte;
    char mot[26];
    int designationMot;
};

/**
 * @brief detecter quelle est la commande entrée
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream
 * @param[in] tabMots : le tableau de mots

 */
int detectionDeLaCommande(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots);

/**
 * @brief lire  la commande
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le flux d entrée
 * @param[in] tabMots : le tableau de mots

 */
int LectureCommande(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istream& is, TabMots& tabMots);

/**
 * @brief detecter la commande T et E
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream

 */
int detectionDeLaCommandeTE(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is);

/**
 * @brief faire les commandes T et E
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande


 */
void commandeTE(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande);

/**
 * @brief detecter la commande P
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream

 */
int detectionDeLaCommandeP(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is);

/**
 * @brief faire la commande P
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream
 * @param[in] tabMots : le tableau de mots

 */
int commandeP(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is,TabMots& tabMots);

/**
 * @brief detecter la commande R
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream

 */
int detectionDeLaCommandeR(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is);

/**
 * @brief faire la commande R
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream
 * @param[in] tabMots : le tableau de mots

 */
int commandeR(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots);

/**
 * @brief detecter la commande C
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream

 */
int detectionDeLaCommandeC(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is);

/**
 * @brief faire la commande C
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream
 * @param[in] tabMots : le tableau de mots

 */
int commandeC(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots);


#endif //LEXICON_S1_02_COMMANDES_H
