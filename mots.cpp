//
// Created by PC on 26/12/2023.
//

#include "mots.h"

/**
 * @brief Initialiser du Mot avec les bons paramètres
 * @param[in] taille : taille du mot
 * @param[in] pasDExtension : son pasExtension
 * @param[out] leMot : la carte dans laquelle on lit la lettre et on ajoute le nombre de points adéquat
 */
void initialiser(Mot& leMot, int taille ,int pasDExtension){
    leMot.taille = taille;
    leMot.pasExtension = pasDExtension;
    leMot.word = new char[taille+1]; // "+1" pour compter le \0
}
/**
 * @brief Detruire le mot
 * @param[out] mot : la carte dans laquelle on lit la lettre et on ajoute le nombre de points adéquat
 */
void detruire(char* mot){
    delete [] mot;

}
/**
 * @brief Ecrire dans leMot à partir d'un istringstream
 * @param[in] stream : taille du mot
 * @param[out] leMot : la carte dans laquelle on lit la lettre et on ajoute le nombre de points adéquat
 */
int ecrire(Mot& leMot, std::istringstream& stream){
    char lettre;
    int compteur = 0;
    if(stream >> lettre && stream.peek() != ' ' ){ //on vérifie si le stream n'est pas vide et qu'il n'est pas fini
        do{
            if(compteur >= leMot.taille){ //si la capacité n'est pas suffisante, on étend le tableau
                char* mottmp;
                int nouvelleTaille = leMot.taille+leMot.pasExtension;
                mottmp = new char[nouvelleTaille];
                for(int i=0; i<leMot.taille; i++){
                    mottmp[i]= leMot.word[i];
                }
                detruire(leMot.word);
                leMot.word = new char[nouvelleTaille];
                for(int i=0; i<leMot.taille; i++){
                    leMot.word[i] = mottmp[i];
                }
                leMot.taille= nouvelleTaille;
                detruire(mottmp);
            }

            leMot.word[compteur] = lettre;
            ++compteur;
        }while (stream.peek() != ' ' && stream >> lettre);
    }

    if(compteur == ZERO){ //si stream vide
        return ZERO;
    }
    else if (compteur == UN){ //si le mot est a pour taille 1
        return UN;
    }
    else{ //tout fonctionne
        leMot.word[leMot.taille] = '\0';
        return DEUX;
    }
}

/**
 * @brief Rechercher dans le dictionnaire le mot passé en paramètre et renvoie un booléen
 * @param[in] mot : le mot
 */
bool rechercheMotDansLeDictionnaire(Mot& mot){
    std::ifstream in("ods4.txt"); // on ouvre le fichier
    if (!in) {
        std::cout << "le dictionnaire n'a pu etre ouvert" << std::endl;
        return DEUX;
    }

    const int MAX = 26;
    char s[MAX];
    in >> std::setw(MAX) >> s; // on essaye de lire le premier mot
    while (in) {

        if(strcmp(mot.word, s) == 0){
            in.close();
            return true;
        }
        in >> std::setw(MAX) >> s; // on essaye de lire le mot suivant
    }
    in.close(); // on ferme le fichier
    return false;
}

/**
 * @brief Initialisation du tableau de mot
 * @param[in] taille: taille du tableau
 * @param[in] pasExtension : pas d'extension du tableau
 * @param[out] tabMots : le tableau de mot a initialisé
 */
void initialiserTableauDeMot(TabMots& tabMots, int taille, int pasExtension){
    assert(taille > ZERO);
    tabMots.taille = taille;
    tabMots.tableauDeMots = new Mot[taille];
    tabMots.indiceDernierMot = -1;
    tabMots.pasExtension = pasExtension;
}

/**
 * @brief Ajouter mot dans le tableau de mot
 * @param[in] mot: le mot a ajouté
 * @param[out] tabMots : le tableau de mot dans lequel on insère le mot
 */
void ajouterMot(TabMots& tabMots, Mot& mot){
    tabMots.indiceDernierMot++; //incrémentation de l'indice du dernier mot
    if(tabMots.indiceDernierMot >= tabMots.taille){ //si le tableau est plein, on l'étend
        Mot* tabtmp;
        int nouvelleTaille = tabMots.taille*tabMots.pasExtension; //calcul de la nouvelle taille
        tabtmp = new Mot[nouvelleTaille]; //on alloue un tableau tabtmp dynamiquement
        for(int i=ZERO; i<tabMots.indiceDernierMot; i++){
            tabtmp[i]= tabMots.tableauDeMots[i]; //on copie le tableau
        }
        delete [] tabMots.tableauDeMots; //on le delete
        tabMots.tableauDeMots = new Mot[nouvelleTaille]; //on le recrée mais plus grand
        for(int i=ZERO; i<tabMots.indiceDernierMot; i++){
            tabMots.tableauDeMots[i] = tabtmp[i]; // et on remet les mots de base
        }
        tabMots.taille= nouvelleTaille;//sa nouvelle taille
        delete [] tabtmp; //on désalloue le tabtmp
    }
    mot.idMot = tabMots.indiceDernierMot+1;  //on attribue au mot son id
    tabMots.tableauDeMots[tabMots.indiceDernierMot] = mot; //on insère le mot

}

/**
 * @brief Afficher le tableau de mots
 * @param[in] tabMots: la tableau a afficher
 */
void afficherTableauMot(TabMots& tabMots){
    for (int compteur=ZERO; compteur <= tabMots.indiceDernierMot; compteur++){
        std::cout << tabMots.tableauDeMots[compteur].idMot << " - " << tabMots.tableauDeMots[compteur].word << std::endl;
    }
}

/**
 * @brief Comparer deux lettres, renvoie True si les lettres sont les memes, False sinon
 * @param[in] premiereLettre: la premiere lettre à comparer
 * @param[in] deuxiemeLettre: la deuxieme lettre à comparer
 */
bool comparerLettres(char& premiereLettre, char& deuxiemeLettre){
    if(premiereLettre == deuxiemeLettre)
        return true;
    else
        return false;
}

/**
 * @brief Fonction de mise à jour du tableau
 * @param[out] tabMots: la premiere lettre à comparer
 * @param[in] mot: la deuxieme lettre à comparer
 * @param[in] indice : l'indice du mot qu'il faut mettre à jour dans le tableau
 */
void miseAJourMots(TabMots tabMots, Mot& mot, int indice){
        mot.idMot = tabMots.tableauDeMots[indice].idMot;
        tabMots.tableauDeMots[indice]= mot;
}


/**
 * @brief Fonction de vérification avant de compléter (commande C), renvoie un booléen
 * on vérifie si les lettres sont les memes, et si oui on incrémente une variable
 * l'objectif est que la variable soit égale a la taille-1 du mot initial
 * @param[in] motInitial: mot qui figure dans le tableau
 * @param[in] motDuJoueur : mot proposé par le joueur
 */
bool verificationValiditeMotPourCompleter(Mot& motInitial, Mot& motDuJoueur){
    int indiceMotInitial=ZERO;
    for(int compteurLettreMotDuJoueur=ZERO; compteurLettreMotDuJoueur < motDuJoueur.taille; compteurLettreMotDuJoueur++){
        if(motDuJoueur.word[compteurLettreMotDuJoueur] == motInitial.word[indiceMotInitial]){ //si la lettre est la meme on incrémente
            indiceMotInitial++;
        }
        if (indiceMotInitial == motInitial.taille-UN){
            return true;
        }

    }
    return false;
}