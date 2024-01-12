//
// Created by soule on 04/01/2024.
//

#ifndef LEXICON_S1_02_MAIN_H
#define LEXICON_S1_02_MAIN_H

#include "talonEtExposee.h"
#define TAILLE_TABLEAU 5
#define PAS_EXTENSTION_TABLEAU_MOT 2

/**
 * @brief lire  la commande
 * @param[in] lesJoueurs : les joueurs
 * @param[in] jeuDeCartes : le jeu de cartes
 * @param[in] tabMots : le tableau de mots
 * @param[in] pileDuTalon : la pile du talon
 * @param[in] pileCartesExposees :  la pile de cartes exposées

 */
void initialisationNouveauTour(Joueurs& lesJoueurs, jeuDeCarte& jeuDeCartes, TabMots& tabMots, Pile& pileDuTalon, Pile& pileCartesExposees);

#endif //LEXICON_S1_02_MAIN_H
