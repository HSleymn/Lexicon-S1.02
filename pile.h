//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_PILE_H
#define LEXICONPP_PILE_H

#include "joueur.h"
#include <cassert>

/**
 * Type Pile qui contient:
 * sa capacite
 * un tableau alloué dynamiquement
 * et l'indice de son sommet
 */
struct Pile{
    int capacite;  // capacité de la pile (c>0)
    Carte* tab;				// tableau des éléments de pile en mémoire dynamique
    int sommet;				// indice du sommet de pile dans tab

};


/**
 * @brief Initialiser la pile
 * @param[out] pileDeCartes : la pile
 * @param[in] nombreDeCarteRestant : valeur contenant lenombre de cartes restants apres
 *              la distribution aux joueurs
 */
void initialiser(Pile& pileDeCartes, const unsigned int nombreDeCarteRestant );

/**
     * @brief Vérifier si la pile est vide, renvoie un booléen
     * @param[in] pileDeCartes : la pile

     */
bool estVide(const Pile& pileDeCartes);

/**
     * @brief Vérifier si la pile est pleine, renvoie un booléen
     * @param[in] pileDeCartes : la pile.
     */
bool estPlein(const Pile& pileDeCartes);

/**
     * @brief Empile dans al pile l'élément carte
     * @param[in] carte : la carte a empiler
     * @param[out] pileDeCartes : la pile
*/
void empiler(Pile& pileDeCartes, const Carte& carte);

/**
     * @brief dépiler de la pile
     * @param[in] pileDesCartesExposees : la pile.
     */
void depiler(Pile& pileDeCartes);

/**
     * @brief detruit la pile
     * @param[in] pile : la pile.
     */
void detruire(Pile& pile);

#endif //LEXICONPP_PILE_H
