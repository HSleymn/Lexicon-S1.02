//
// Created by PC on 24/12/2023.
//

#include "talonEtExposee.h"
#include <iostream>



void remplirTalonEtExposee(Pile& pileDuTalon, Pile& pileExposee, jeuDeCarte& jeuDeCartes){
    for (int compteur=0; compteur < pileDuTalon.capacite; compteur++){
        empiler(pileDuTalon, jeuDeCartes.cartes[compteur]);
    }
    detruireJeuDeCarte(jeuDeCartes);
    empiler(pileExposee, pileDuTalon.tab[pileDuTalon.sommet]);
    depiler(pileDuTalon);
}

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