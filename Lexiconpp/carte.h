//
// Created by PC on 09/12/2023.
//

#ifndef LEXICONPP_CARTE_H
#define LEXICONPP_CARTE_H
#define nombreDeCarte 52

struct Carte{
    unsigned int nb_points;
    char lettre;
};

struct jeuDeCarte{
    Carte* cartes;
};
void initialiserJeuDeCarte(jeuDeCarte& jeu);
void melangerJeuDeCarte(jeuDeCarte& jeu);



#endif //LEXICONPP_CARTE_H
