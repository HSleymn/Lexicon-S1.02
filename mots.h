//
// Created by PC on 26/12/2023.
//

#ifndef LEXICON_S1_02_MOTS_H
#define LEXICON_S1_02_MOTS_H
#include "iostream"
#include <sstream>
#include <iostream>
#include <fstream> // pour ifstream
#include <iomanip> // pour setw
#include <cstring>
#include <cassert>
#include "carte.h"
//déclaration de constante en define pour éviter les nombres magiques
#define ZERO 0
#define UN 1
#define DEUX 2


/**
 * Type Mot contenant :
 * un tableau de char en allocation dynamique
 * la taille de ce tableau, la taille est exprimée en unité humaine, donc le mot "TOTO" aura pour taille 4
 * le pasExtension pour étendre le tableau lors de la complétion de ce dernier
 * et l'identifiant du mot
 */
struct Mot{
    char* word;
    int taille;
    int pasExtension;
    int idMot;
};

/**
 * Type TabMots contenant :
 * un tableau de Mot en allocation dynamique
 * la taille de ce dernier
 * l'indice du dernier mot enregistré
 * et le pasExtension pour étendre le tableau
 */
struct TabMots{
    Mot* tableauDeMots;
    int taille;
    int indiceDernierMot;
    int pasExtension;
};

/**
 * @brief Initialiser du Mot avec les bons paramètres
 * @param[in] taille : taille du mot
 * @param[in] pasDExtension : son pasExtension
 * @param[out] leMot : la carte dans laquelle on lit la lettre et on ajoute le nombre de points adéquat
 */
void initialiser(Mot& leMot, int taille, int pasDExtension);


/**
 * @brief Detruire le mot
 * @param[out] mot : la carte dans laquelle on lit la lettre et on ajoute le nombre de points adéquat
 */
void detruire(char* mot);


/**
 * @brief Ecrire dans leMot à partir d'un istringstream
 * @param[in] stream : taille du mot
 * @param[out] leMot : la carte dans laquelle on lit la lettre et on ajoute le nombre de points adéquat
 */
int ecrire(Mot& leMot, std::istringstream& stream);


/**
 * @brief Rechercher dans le dictionnaire le mot passé en paramètre et renvoie un booléen
 * @param[in] mot : le mot
 */
bool rechercheMotDansLeDictionnaire(Mot& mot);


/**
 * @brief Initialisation du tableau de mot
 * @param[in] taille: taille du tableau
 * @param[in] pasExtension : pas d'extension du tableau
 * @param[out] tabMots : le tableau de mot a initialisé
 */
void initialiserTableauDeMot(TabMots& tabMots, int taille, int pasExtension);


/**
 * @brief Ajouter mot dans le tableau de mot
 * @param[in] mot: le mot a ajouté
 * @param[out] tabMots : le tableau de mot dans lequel on insère le mot
 */
void ajouterMot(TabMots& tabMots, Mot& mot);


/**
 * @brief Afficher le tableau de mots
 * @param[in] tabMots: la tableau a afficher
 */
void afficherTableauMot(TabMots& tabMots);


/**
 * @brief Comparer deux lettres, renvoie True si les lettres sont les memes, False sinon
 * @param[in] premiereLettre: la premiere lettre à comparer
 * @param[in] deuxiemeLettre: la deuxieme lettre à comparer
 */
bool comparerLettres(char& premiereLettre, char& deuxiemeLettre);


/**
 * @brief Fonction de mise à jour du tableau
 * @param[out] tabMots: la premiere lettre à comparer
 * @param[in] mot: la deuxieme lettre à comparer
 * @param[in] indice : l'indice du mot qu'il faut mettre à jour dans le tableau
 */
void miseAJourMots(TabMots tabMots, Mot& mot, int indice);


/**
 * @brief Fonction de vérification avant de compléter (commande C), renvoie un booléen
 * on vérifie si les lettres sont les memes, et si oui on incrémente une variable
 * l'objectif est que la variable soit égale a la taille-1 du mot initial
 * @param[in] motInitial: mot qui figure dans le tableau
 * @param[in] motDuJoueur : mot proposé par le joueur
 */
bool verificationValiditeMotPourCompleter(Mot& premierMot, Mot& deuxiemeMot);

#endif //LEXICON_S1_02_MOTS_H
