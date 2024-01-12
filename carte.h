//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_CARTE_H
#define LEXICONPP_CARTE_H
#define nombreDeCarte 51
#include <iostream>
#include "ctime"

/**
 * Type carte contenant la lettre et le nombre de points
 */
struct Carte{
    unsigned int nb_points; //nombre de points de la lettre
    char lettre; //la lettre en question
};

/**
 * Type jeuDeCarte contenant un tableau alloué en allocation dynamique et la capacité de ce dernier
 */
struct jeuDeCarte{
    Carte* cartes; //tableau d'éléments de type Carte alloué dynamiquement
    unsigned int capacite; //capacité du tableau
};



/**
 * @brief Initialiser le jeu de carte de base et le remplir avec des éléments de type Carte
 * le jeu de carte est allouée en mémoire dynamique
 * @see detruireJeuDeCarte, il est désalloué en fin d'utilisation
 * @param[out] jeu : le jeu à initialiser et qui se remplit
 */
void initialiserJeuDeCarte(jeuDeCarte& jeu);

/**
 * @brief Mélanger le jeu de carte
 * @param[in,out] jeu : le jeu à mélanger
 */
void melangerJeuDeCarte(jeuDeCarte& jeu);

/**
 * @brief Détruire le jeu de carte
 * @see initialiserJeuDeCarte, le jeu à été au prélable initialiser
 * @param[out] jeu : le jeu à à détruide
 */
void detruireJeuDeCarte(jeuDeCarte& jeu);

/**
 * @brief Récupérer le jeu de carte restant après la distribution aux joueurs
 * @param[out] jeu : le jeu dans lequel on veut récupérer
 * @param[in] nombreDeJoeursEnLice : le nombre de joueur toujours en Lice
 */
void recupererJeuDeCarteRestant(jeuDeCarte& jeu, unsigned int nombreDeJoeursEnLice);

/**
 * @brief Ajouter en fonction de la lettre le nombre de points adéquat
 * @param[in,out] cartes : la carte dans laquelle on lit la lettre et on ajoute le nombre de points adéquat
 */
void ajouterPointsPourCartes(Carte& carte);


#endif //LEXICONPP_CARTE_H
