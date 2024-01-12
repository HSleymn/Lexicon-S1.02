//
// Created by PC on 25/12/2023.
//


#include "commandes.h"


/**
 * @brief detecter quelle est la commande entrée
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream
 * @param[in] tabMots : le tableau de mots

 */
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


/**
 * @brief lire  la commande
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le flux d entrée
 * @param[in] tabMots : le tableau de mots

 */
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


/**
 * @brief detecter la commande T et E
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream

 */
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


/**
 * @brief faire les commandes T et E
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande


 */
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


/**
 * @brief detecter la commande P
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream

 */
int detectionDeLaCommandeP(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is){
    if (commande.nomDeLaCommande != 'P'){
        return ENTREE_INVALIDE;
    }
    else {
        return ENTREE_VALIDE;

    }}


/**
 * @brief faire la commande P
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream
 * @param[in] tabMots : le tableau de mots

 */
int commandeP(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots){
    Mot mots;
    initialiser(mots, 1, 1);
    int resultatEcriture;
    resultatEcriture = ecrire(mots, is);
    if(resultatEcriture == 0){
        return ENTREE_INVALIDE ;
    }
    else if(resultatEcriture == 1){
        return MOT_INVALIDE ;
    }
    char test;
    if(is >> test){
        return ENTREE_INVALIDE;
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


/**
 * @brief detecter la commande R
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream

 */
int detectionDeLaCommandeR(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is){
    if (commande.nomDeLaCommande != 'R'){
        return ENTREE_INVALIDE;
    }
    else {
        return ENTREE_VALIDE;

    }}


/**
 * @brief faire la commande R
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream
 * @param[in] tabMots : le tableau de mots

 */
int commandeR(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots){
    Mot mots;
    initialiser(mots, 1, 1);

    is>>commande.designationMot;
    if(is.peek() != ' '){
        return ENTREE_INVALIDE;
    }
    std::cout << commande.designationMot;
    std::cout << tabMots.indiceDernierMot << std::endl;
    if(commande.designationMot-1 > tabMots.indiceDernierMot){
        return ENTREE_INVALIDE;
    }

    int resultatEcriture;
    resultatEcriture = ecrire(mots, is);
    if(resultatEcriture == 0){
        return ENTREE_INVALIDE ;
    }
    else if(resultatEcriture == 1){
        return MOT_INVALIDE ;
    }
    Mot mottmp;
    mottmp.word = new char[mots.taille+1];


    Mot motDesigne = tabMots.tableauDeMots[commande.designationMot-1];
    if(mots.taille != motDesigne.taille){
        return ENTREE_INVALIDE;
    }
    int tableauIndice[mots.taille];
    int tableauIndiceMot[mots.taille];
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
                tableauIndiceMot[tailleTableau] = compteurTailleMot;
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

    Carte carteTmp;
    for(int compteur=0; compteur<tailleTableau;compteur++){
        carteTmp = joueur.mainDuJoueur[tableauIndice[compteur]];
        joueur.mainDuJoueur[tableauIndice[compteur]].lettre = motDesigne.word[tableauIndiceMot[compteur]];
        ajouterPointsPourCartes(joueur.mainDuJoueur[tableauIndice[compteur]]);
        motDesigne.word[tableauIndiceMot[compteur]] = carteTmp.lettre;
    }

    delete [] mottmp.word;
    miseAJourMots(tabMots, mots, commande.designationMot-1);
    return ENTREE_VALIDE;
}


/**
 * @brief detecter la commande C
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream

 */
int detectionDeLaCommandeC(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is){
    if (commande.nomDeLaCommande != 'C'){
        return ENTREE_INVALIDE;
    }
    else {
        return ENTREE_VALIDE;

    }}


/**
 * @brief faire la commande C
 * @param[in] joueur : le joueur
 * @param[in] pileduTalon : la pile du talon
 * @param[in] pileDeCartesExposees : la pile de cartes exposées
 * @param[in] commande : la commande
 * @param[in] is : le stream
 * @param[in] tabMots : le tableau de mots

 */
int commandeC(Joueur& joueur, Pile& pileduTalon, Pile& pileDeCartesExposees, Commande& commande, std::istringstream& is, TabMots& tabMots){
    Mot mots;
    initialiser(mots, 1, 1);

    is>>commande.designationMot;
    if(is.peek() != ' '){
        return ENTREE_INVALIDE;
    }

    std::cout << commande.designationMot;
    std::cout << tabMots.indiceDernierMot << std::endl;
    if(commande.designationMot-1 > tabMots.indiceDernierMot){
        return ENTREE_INVALIDE;
    }

    int resultatEcriture;
    resultatEcriture = ecrire(mots, is);
    if(resultatEcriture == 0){
        return ENTREE_INVALIDE ;
    }
    else if(resultatEcriture == 1){
        return MOT_INVALIDE ;
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
    std::cout << "compteur mot initial " << compteurMotInitial;
    std::cout << " taille mot initial "<< motDesigne.taille;
    std::cout << " le tableau vaut " << tailleTableau;
    if(compteurMotInitial!= motDesigne.taille){
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