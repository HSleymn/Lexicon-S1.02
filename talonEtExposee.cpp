//
// Created by PC on 24/12/2023.
//

#include "talonEtExposee.h"

#include <iostream>



void remplirTalonEtExposee(Pile_Talon& pileDuTalon, Pile_Exposee& pileExposee, jeuDeCarte& jeuDeCartes){

    for (int compteur=0; compteur < pileDuTalon.capacite; compteur ++){
        std::cout << "caca" << std::endl;
        std::cout << pileDuTalon.indiceSommet << std::endl;
        std::cout << "cacaprout" << std::endl;
        empiler(pileDuTalon, jeuDeCartes.cartes[compteur]);
        std::cout << "cacahuete";
    }

    detruireJeuDeCarte(jeuDeCartes);

    empiler(pileExposee, pileDuTalon.tab[pileDuTalon.indiceSommet-1]);
    depiler(pileDuTalon);
}

void rechargementDuTalon(Pile_Talon& pileDuTalon, Pile_Exposee& pileExposee){
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