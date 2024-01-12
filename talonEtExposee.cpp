//
// Created by PC on 24/12/2023.
//

#include "talonEtExposee.h"


/**
 * @brief remplir le talon et la pile de carte exposées
 * @param[in,out] pileDuTalon : le talon
 * @param[in,out] pileExposee : la pile de cartes exposées
 * @param[in] jeuDeCartes : le jeu de cartes initial
  */
void remplirTalonEtExposee(Pile& pileDuTalon, Pile& pileExposee, jeuDeCarte& jeuDeCartes){
    for (int compteur=0; compteur < pileDuTalon.capacite; compteur++){
        empiler(pileDuTalon, jeuDeCartes.cartes[compteur]);
    }
    detruireJeuDeCarte(jeuDeCartes);
    empiler(pileExposee, pileDuTalon.tab[pileDuTalon.sommet]);
    depiler(pileDuTalon);
}

/**
 * @brief recharger le talon
 * @param[in,out] pileDuTalon : le talon
 * @param[in] pileExposee: la pile de cartes exposées
*/
void rechargementDuTalon(Pile& pileDuTalon, Pile& pileExposee){
    jeuDeCarte jeutmp;
    jeutmp.capacite = pileExposee.capacite;
    jeutmp.cartes = new Carte[pileExposee.capacite];
    for (int compteur = 0; compteur < pileExposee.capacite; compteur++ ){
        jeutmp.cartes[compteur] = pileExposee.tab[pileExposee.sommet];
        depiler(pileExposee);
    }
    melangerJeuDeCarte(jeutmp);
    remplirTalonEtExposee(pileDuTalon, pileExposee, jeutmp);

}