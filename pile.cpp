//
// Created by PC on 09/12/2023.
//
#include "pile.h"


    /**
     * @brief Initialiser la pile
     * @param[out] pileDeCartes : la pile
     * @param[in] nombreDeCarteRestant : valeur contenant lenombre de cartes restants apres
     *              la distribution aux joueurs
     */
void initialiser(Pile& pileDeCartes, const unsigned int nombreDeCarteRestant ){
    assert(nombreDeCarteRestant>0);
    pileDeCartes.capacite = nombreDeCarteRestant;
    pileDeCartes.tab = new Carte[nombreDeCarteRestant];
    pileDeCartes.sommet = -1;
}

/**
     * @brief Vérifier si la pile est vide, renvoie un booléen
     * @param[in] pileDeCartes : la pile

     */
bool estVide(const Pile& pileDeCartes){
    return pileDeCartes.sommet == -1;
}

/**
     * @brief Vérifier si la pile est pleine, renvoie un booléen
     * @param[in] pileDeCartes : la pile.
     */
bool estPlein(const Pile& pileDeCartes){
    return pileDeCartes.sommet >= pileDeCartes.capacite;
}

/**
     * @brief Empile dans al pile l'élément carte
     * @param[in] carte : la carte a empiler
     * @param[out] pileDeCartes : la pile
*/
void empiler(Pile& pileDeCartes, const Carte& carte){
    assert(!estPlein(pileDeCartes));
    pileDeCartes.sommet++;
    pileDeCartes.tab[pileDeCartes.sommet] = carte;
}

/**
     * @brief dépiler de la pile
     * @param[in] pileDesCartesExposees : la pile.
     */
void depiler(Pile& pileDesCartesExposees){
    assert(!estVide(pileDesCartesExposees));
    pileDesCartesExposees.sommet--;
}

/**
     * @brief detruit la pile
     * @param[in] pile : la pile.
     */
void detruire(Pile& pile){
    delete [] pile.tab;
}