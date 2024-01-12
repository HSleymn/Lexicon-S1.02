//
// Created by PC on 24/12/2023.
//

#ifndef LEXICONPP_TALONETEXPOSEE_H
#define LEXICONPP_TALONETEXPOSEE_H
#include "commandes.h"

/**
 * @brief remplir le talon et la pile de carte exposées
 * @param[in,out] pileDuTalon : le talon
 * @param[in,out] pileExposee : la pile de cartes exposées
 * @param[in] jeuDeCartes : le jeu de cartes initial
  */
void remplirTalonEtExposee(Pile& pileDuTalon, Pile& pileExposee, jeuDeCarte& jeuDeCartes);

/**
 * @brief recharger le talon
 * @param[in,out] pileDuTalon : le talon
 * @param[in] pileExposee: la pile de cartes exposées
*/
void rechargementDuTalon(Pile& pileDuTalon, Pile& pileExposee);
#endif //LEXICONPP_TALONETEXPOSEE_H
