//
// Created by PC on 09/12/2023.
//

#include "carte.h"




/**
 * @brief Initialiser le jeu de carte de base et le remplir avec des éléments de type Carte
 * le jeu de carte est allouée en mémoire dynamique
 * @see detruireJeuDeCarte, il est désalloué en fin d'utilisation
 * @param[out] jeu : le jeu à initialiser et qui se remplit
 */
void initialiserJeuDeCarte(jeuDeCarte& jeu) {
    char tableauDeLettres[51]= {  'A', 'A',
                                  'B', 'B',
                                  'C','C',
                                  'D','D',
                                  'E','E','E','E','E',
                                  'F',
                                  'G','G',
                                  'H','H',
                                  'I','I','I','I',
                                  'J',
                                  'K',
                                  'L','L',
                                  'M',
                                  'N','N','N',
                                  'O','O',
                                  'P',
                                  'Q',
                                  'R','R','R',
                                  'S','S','S',
                                  'T','T','T',
                                  'U','U','U',
                                  'V',
                                  'W',
                                  'X',
                                  'Y',
                                  'Z',
    };

    jeu.cartes = new Carte[nombreDeCarte];
    jeu.capacite = nombreDeCarte;
    for (int compteur = 0; compteur < nombreDeCarte; ++compteur) {
        jeu.cartes[compteur].lettre = tableauDeLettres[compteur];
        ajouterPointsPourCartes(jeu.cartes[compteur]);
    }
    melangerJeuDeCarte(jeu);
}

/**
 * @brief Mélanger le jeu de carte
 * @param[in,out] jeu : le jeu à mélanger
 */
void melangerJeuDeCarte(jeuDeCarte& jeu) {
    Carte carteIntermediaire;
    unsigned int nombreDeCarteAMelanger = jeu.capacite-1;

    do {
        srand(time(0));
        int nombreAleatoire = rand() % nombreDeCarteAMelanger;
        carteIntermediaire = jeu.cartes[nombreAleatoire];
        jeu.cartes[nombreAleatoire] = jeu.cartes[nombreDeCarteAMelanger];
        jeu.cartes[nombreDeCarteAMelanger] = carteIntermediaire;
        --nombreDeCarteAMelanger;
    }while( nombreDeCarteAMelanger > 0);
}

/**
 * @brief Détruire le jeu de carte
 * @see initialiserJeuDeCarte, le jeu à été au prélable initialiser
 * @param[out] jeu : le jeu à à détruide
 */
void detruireJeuDeCarte(jeuDeCarte& jeu){
    delete [] jeu.cartes;
}
/**
 * @brief Récupérer le jeu de carte restant après la distribution aux joueurs
 * @param[out] jeu : le jeu dans lequel on veut récupérer
 * @param[in] nombreDeJoeursEnLice : le nombre de joueur toujours en Lice
 */
void recupererJeuDeCarteRestant(jeuDeCarte& jeu, unsigned int nombreDeJoeursEnLice){
    jeuDeCarte jeutmp;
    unsigned int indiceDebutDuJeuInitial = nombreDeJoeursEnLice*10; //recherche de l'indice du début
    unsigned int nombreDeCartesRestant = nombreDeCarte - indiceDebutDuJeuInitial;
    jeutmp.cartes = new Carte[nombreDeCartesRestant];
    jeutmp.capacite = nombreDeCartesRestant;
    for (int compteur=0; indiceDebutDuJeuInitial < nombreDeCarte; compteur++){
        jeutmp.cartes[compteur] = jeu.cartes[indiceDebutDuJeuInitial]; //on récupère les cartes qu'on stock dans un jeutmp
        indiceDebutDuJeuInitial++;
    }
    detruireJeuDeCarte(jeu);
    jeu.cartes = new Carte[nombreDeCartesRestant];
    for (int compteur = 0; compteur < nombreDeCartesRestant; compteur++){
        jeu.cartes[compteur] = jeutmp.cartes[compteur]; //on recopie les valeurs du jeutmp dans le tableau fraichement alloué à la taille adéquate
    }
    jeu.capacite = jeutmp.capacite;
}
/**
 * @brief Ajouter en fonction de la lettre le nombre de points adéquat
 * @param[in,out] cartes : la carte dans laquelle on lit la lettre et on ajoute le nombre de points adéquat
 */
void ajouterPointsPourCartes(Carte& cartes){
    if (cartes.lettre == 'A' || cartes.lettre == 'E' || cartes.lettre == 'I') {
            cartes.nb_points = 10;
        } else if (cartes.lettre == 'C' || cartes.lettre == 'H' ||
                   cartes.lettre == 'K' || cartes.lettre == 'M' ||
                   cartes.lettre == 'L' || cartes.lettre == 'P' ||
                   cartes.lettre == 'N' || cartes.lettre == 'T' ||
                   cartes.lettre == 'O' || cartes.lettre == 'W' ||
                   cartes.lettre == 'R' || cartes.lettre == 'S' ||
                   cartes.lettre == 'U' || cartes.lettre == 'V'  ) {
            cartes.nb_points = 8;
        } else if (cartes.lettre == 'D' || cartes.lettre == 'J') {
            cartes.nb_points = 6;
        } else if (cartes.lettre == 'G' || cartes.lettre == 'Q' ||
                   cartes.lettre == 'Y') {
            cartes.nb_points = 4;
        } else if (cartes.lettre == 'B' || cartes.lettre == 'F' ||
                   cartes.lettre == 'X' || cartes.lettre == 'Z') {
            cartes.nb_points = 2;
        }       }