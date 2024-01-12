//
// Created by PC on 26/12/2023.
//

#include "mots.h"

void initialiser(Mot& leMot, int taille ,int pasDExtension){
    leMot.taille = taille;
    leMot.pasExtension = pasDExtension;
    leMot.word = new char[taille+1];
}

void detruire(char* mot){
    delete [] mot;
}

int ecrire(Mot& leMot, std::istringstream& stream){
    char lettre;
    int compteur = 0;
if(stream >> lettre && stream.peek() != ' ' ){
    do{
        if(compteur >= leMot.taille){
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


    }while (stream.peek() != ' ' && stream >> lettre);}
    if(compteur == 0){
        return 0;
    }

    else if (compteur == 1){
        return 1;
    }
    else{
        leMot.word[leMot.taille] = '\0';
        return 2;}
}

bool rechercheMotDansLeDictionnaire(Mot& mot){
    std::ifstream in("ods4.txt"); // on ouvre le fichier
    if (!in) {
        std::cout << "le dictionnaire n'a pu etre ouvert" << std::endl;
        return 2;
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

void initialiserTableauDeMot(TabMots& tabMots, int taille, int pasExtension){
    assert(taille > 0);
    tabMots.taille = taille;
    tabMots.tableauDeMots = new Mot[taille];
    tabMots.indiceDernierMot = -1;
    tabMots.pasExtension = pasExtension;
}


void ajouterMot(TabMots& tabMots, Mot& mot){
    tabMots.indiceDernierMot++;
    if(tabMots.indiceDernierMot >= tabMots.taille){
        Mot* tabtmp;
        int nouvelleTaille = tabMots.taille*tabMots.pasExtension;
        tabtmp = new Mot[nouvelleTaille];
        for(int i=0; i<tabMots.indiceDernierMot; i++){
            tabtmp[i]= tabMots.tableauDeMots[i];
        }
        delete [] tabMots.tableauDeMots;
        tabMots.tableauDeMots = new Mot[nouvelleTaille];
        for(int i=0; i<tabMots.indiceDernierMot; i++){
            tabMots.tableauDeMots[i] = tabtmp[i];
        }
        tabMots.taille= nouvelleTaille;
        delete [] tabtmp;
    }
    mot.idMot = tabMots.indiceDernierMot+1;
    tabMots.tableauDeMots[tabMots.indiceDernierMot] = mot;

}

void afficherTableauMot(TabMots& tabMots){
    for (int compteur=0; compteur <= tabMots.indiceDernierMot; compteur++){
        std::cout << tabMots.tableauDeMots[compteur].idMot << " - " << tabMots.tableauDeMots[compteur].word << std::endl;
    }
}

bool comparerLettres(char& premiereLettre, char& deuxiemeLettre){
    if(premiereLettre == deuxiemeLettre)
        return true;
    else
        return false;
}

void miseAJourMots(TabMots tabMots, Mot& mot, int indice){

        mot.idMot = tabMots.tableauDeMots[indice].idMot;
        tabMots.tableauDeMots[indice]= mot;


}

bool verificationValiditeMotPourCompleter(Mot& motInitial, Mot& motDuJoueur){
    int indiceMotInitial=0;
    for(int compteurLettreMotDuJoueur=0; compteurLettreMotDuJoueur < motDuJoueur.taille; compteurLettreMotDuJoueur++){
        if(motDuJoueur.word[compteurLettreMotDuJoueur] == motInitial.word[indiceMotInitial]){
            indiceMotInitial++;
        }
        if (indiceMotInitial == motInitial.taille-1){
            return true;
        }

    }
    return false;
}