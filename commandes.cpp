//
// Created by PC on 25/12/2023.
//


#include "commandes.h"


int detectionDeLaCommande(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots){
    if (detectionDeLaCommandeTE(joueur, pileduTalon, pileDeCartesExposees, commande, is) == ENTREE_VALIDE){
        commandeTE(joueur, pileduTalon, pileDeCartesExposees, commande);
        return ENTREE_VALIDE;
    }

    else if(detectionDeLaCommandeP(joueur, pileduTalon, pileDeCartesExposees, commande, is)==ENTREE_VALIDE){
        const int answerP = commandeP(joueur, pileduTalon, pileDeCartesExposees, commande, is, tabMots);
        if(answerP == MOT_INVALIDE)
            return MOT_INVALIDE;
        else if(answerP == ENTREE_INVALIDE)
            return ENTREE_INVALIDE;
        else
        return ENTREE_VALIDE;
    }
    else if(detectionDeLaCommandeR(joueur, pileduTalon, pileDeCartesExposees, commande, is)==ENTREE_VALIDE){
        const int answerR = commandeR(joueur, pileduTalon, pileDeCartesExposees, commande, is, tabMots);
        if(answerR == MOT_INVALIDE)
            return MOT_INVALIDE;
        else if(answerR == ENTREE_INVALIDE)
            return ENTREE_INVALIDE;
        else
            return ENTREE_VALIDE;
    }
    else if(detectionDeLaCommandeC(joueur, pileduTalon, pileDeCartesExposees, commande, is)==ENTREE_VALIDE){
        const int answerR = commandeC(joueur, pileduTalon, pileDeCartesExposees, commande, is, tabMots);
        if(answerR == MOT_INVALIDE)
            return MOT_INVALIDE;
        else if(answerR == ENTREE_INVALIDE)
            return ENTREE_INVALIDE;
        else
            return ENTREE_VALIDE;
    }

    return ENTREE_INVALIDE;
}
int LectureCommande(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istream& is, TabMots& tabMots)
{
    char input[64];
    is >> std::ws;
    is.getline(input, 64);
    std::istringstream stream(input);
    char c;
    stream >> commande.nomDeLaCommande;
    if (stream.peek() != ' ') {
        return ENTREE_INVALIDE;
    }
    else{
        int answerCommande = detectionDeLaCommande(joueur,pileduTalon, pileDeCartesExposees, commande, stream, tabMots);
        if(answerCommande == ENTREE_VALIDE)
            return ENTREE_VALIDE;
        else if(answerCommande == ENTREE_INVALIDE)
            return ENTREE_INVALIDE;
        else if(answerCommande == MOT_INVALIDE)
            return MOT_INVALIDE;
    }


}

int detectionDeLaCommandeTE(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is){
    if (commande.nomDeLaCommande != 'T' && commande.nomDeLaCommande != 'E'){
        return ENTREE_INVALIDE;
    }
    else {

        is >> commande.lettreDeLaCarte;
    if ((is >> commande.mot) || commande.lettreDeLaCarte== ' ') {
        return ENTREE_INVALIDE;
    }

        int indiceCarteJoueur = rechercherDansLaMainDuJoueur(joueur, commande.lettreDeLaCarte);
        if (indiceCarteJoueur == -1){
            return ENTREE_INVALIDE;
        }
    return ENTREE_VALIDE;
    }
}

void commandeTE(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande){
    int indiceCarteJoueur = rechercherDansLaMainDuJoueur(joueur, commande.lettreDeLaCarte);
    if(commande.nomDeLaCommande == 'E'){
        Carte cartetmp;
        cartetmp = pileDeCartesExposees.tab[pileDeCartesExposees.sommet];
        depiler(pileDeCartesExposees);
        empiler(pileDeCartesExposees, joueur.mainDuJoueur[indiceCarteJoueur]);
        joueur.mainDuJoueur[indiceCarteJoueur]= cartetmp;
    }
    else if(commande.nomDeLaCommande == 'T'){
        Carte cartetmp;
        cartetmp = pileduTalon.tab[pileduTalon.sommet];
        depiler(pileduTalon);
        empiler(pileDeCartesExposees, joueur.mainDuJoueur[indiceCarteJoueur]);
        joueur.mainDuJoueur[indiceCarteJoueur]= cartetmp;
    }
}

int detectionDeLaCommandeP(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is){
    if (commande.nomDeLaCommande != 'P'){
        return ENTREE_INVALIDE;
    }
    else {
        return ENTREE_VALIDE;

    }}

int commandeP(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots){
    Mot mots;
    initialiser(mots, 1, 1);


    if(!ecrire(mots, is)){
        return MOT_INVALIDE ;
    }
    int tableauIndice[mots.taille];
    int tailleTableau=0;
    if(!verifierDansLesCartesDeLaMainDuJoueur(joueur, mots, tableauIndice, tailleTableau)){
        return ENTREE_INVALIDE;
    }
    else if(!rechercheMotDansLeDictionnaire(mots)){
        return MOT_INVALIDE ;
    }

    retirerDansLesCartesDeLaMainDuJoueur(joueur, mots, tableauIndice, tailleTableau);
    ajouterMot(tabMots,mots);
    return ENTREE_VALIDE;
}

int detectionDeLaCommandeR(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is){
    if (commande.nomDeLaCommande != 'R'){
        return ENTREE_INVALIDE;
    }
    else {
        return ENTREE_VALIDE;

    }}

int commandeR(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots){
    Mot mots;
    initialiser(mots, 1, 1);

    is>>commande.designationMot;

    std::cout << commande.designationMot;
    std::cout << tabMots.indiceDernierMot << std::endl;
    if(commande.designationMot-1 > tabMots.indiceDernierMot){
        return ENTREE_INVALIDE;
    }

    if(!ecrire(mots, is)){
        return ENTREE_INVALIDE ;
    }
    Mot mottmp;
    mottmp.word = new char[mots.taille+1];


    Mot motDesigne = tabMots.tableauDeMots[commande.designationMot-1];
    if(mots.taille != motDesigne.taille){
        return ENTREE_INVALIDE;
    }
    int tableauIndice[mots.taille];
    int tailleTableau=0;
    for (int compteurTailleMot=0; compteurTailleMot<mots.taille; compteurTailleMot++){
        if(!comparerLettres(mots.word[compteurTailleMot], motDesigne.word[compteurTailleMot])){
            int answerRecherche=rechercherDansLaMainDuJoueurDoublons(joueur, mots.word[compteurTailleMot], tableauIndice, tailleTableau);
            if( answerRecherche == -1){
                return ENTREE_INVALIDE;
            }
            else{
                mottmp.word[tailleTableau] = mots.word[compteurTailleMot];
                tableauIndice[tailleTableau] = answerRecherche;
                tailleTableau++;
            }
        }
    }
    mottmp.taille = tailleTableau;
    if(tailleTableau==0){
        return ENTREE_INVALIDE;
    }

    if(!rechercheMotDansLeDictionnaire(mots)){
        return MOT_INVALIDE ;
    }

    retirerDansLesCartesDeLaMainDuJoueur(joueur, mottmp, tableauIndice, tailleTableau);
    delete [] mottmp.word;
    miseAJourMots(tabMots, mots, commande.designationMot-1);
    return ENTREE_VALIDE;
}

int detectionDeLaCommandeC(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is){
    if (commande.nomDeLaCommande != 'C'){
        return ENTREE_INVALIDE;
    }
    else {
        return ENTREE_VALIDE;

    }}

int commandeC(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots){
    Mot mots;
    initialiser(mots, 1, 1);

    is>>commande.designationMot;

    std::cout << commande.designationMot;
    std::cout << tabMots.indiceDernierMot << std::endl;
    if(commande.designationMot-1 > tabMots.indiceDernierMot){
        return ENTREE_INVALIDE;
    }

    if(!ecrire(mots, is)){
        return ENTREE_INVALIDE ;
    }
    Mot mottmp;
    mottmp.word = new char[mots.taille+1];


    Mot motDesigne = tabMots.tableauDeMots[commande.designationMot-1];

    if(!verificationValiditeMotPourCompleter(motDesigne, mots)){
        return ENTREE_INVALIDE;
    }

    int tableauIndice[mots.taille];
    int tailleTableau=0;
    int compteurMotInitial=0;
    for (int compteurMotDuJoueur=0; compteurMotDuJoueur < mots.taille; compteurMotDuJoueur++){
        if(!comparerLettres(mots.word[compteurMotDuJoueur], motDesigne.word[compteurMotInitial])){
            //mettre deux compteurs
            int answerRecherche=rechercherDansLaMainDuJoueurDoublons(joueur, mots.word[compteurMotDuJoueur], tableauIndice, tailleTableau);
            if( answerRecherche == -1){
                return ENTREE_INVALIDE;
            }
            else{
                mottmp.word[tailleTableau] = mots.word[compteurMotDuJoueur];
                tableauIndice[tailleTableau] = answerRecherche;
                tailleTableau++;
            }
        }
        else{
            compteurMotInitial++;

        }
    }
    mottmp.taille = tailleTableau;
    std::cout << "le tableau vaut " << tailleTableau;
    if(tailleTableau==0){
        return ENTREE_INVALIDE;
    }

    if(!rechercheMotDansLeDictionnaire(mots)){
        return MOT_INVALIDE ;
    }

    retirerDansLesCartesDeLaMainDuJoueur(joueur, mottmp, tableauIndice, tailleTableau);
    delete [] mottmp.word;
    miseAJourMots(tabMots, mots, commande.designationMot-1);
    return ENTREE_VALIDE;
}