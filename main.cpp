
// program named mainreturn.cpp
#include "main.h"

//defining main with arguments
int main(int argc, char** argv)
{
    // initialisation du jeu

    unsigned int nbJoueurs = atoi(argv[1]);
    jeuDeCarte jeuDeCartes;
    initialiserJeuDeCarte(jeuDeCartes);
    Joueurs joueurs;
    initialiserLesJoueurs(joueurs, nbJoueurs, jeuDeCartes);
    recupererJeuDeCarteRestant(jeuDeCartes, joueurs.nbJoueursEnLice);
    Pile pileDuTalon;
    initialiser(pileDuTalon, jeuDeCartes.capacite);
    Pile pileCartesExposee;
    initialiser(pileCartesExposee, jeuDeCartes.capacite);
    remplirTalonEtExposee(pileDuTalon, pileCartesExposee, jeuDeCartes);
    Commande commande;
    int pointDeControle = ETAT_DE_BASE;
    int resultatEntree;
    TabMots tableauDeMot;
    initialiserTableauDeMot(tableauDeMot, TAILLE_TABLEAU , PAS_EXTENSTION_TABLEAU_MOT);

    //affichage

    std::cout << "(Commandes valides : TEPRC)" << std::endl;
    int tourDuJoueurDebut = 0;
    int tourApresDebut = 0;
    while(joueurs.nbJoueursEnLice > 1){
        for (int tourDuJoueur = tourApresDebut; tourDuJoueur < joueurs.nbJoueursTotal; tourDuJoueur++) {
            tourApresDebut = 0;
            if(verificationJoueurEnLice(joueurs, joueurs.tabJoueurs[tourDuJoueur])){
                //affichage des mots
                pointDeControle = ETAT_DE_BASE;
                //vérification que talon plein, sinon le remplir
                if (estVide(pileDuTalon)){
                    rechargementDuTalon(pileDuTalon, pileCartesExposee);
                }
                //affichage propre au joueur
                std::cout << "* Joueur " << joueurs.tabJoueurs[tourDuJoueur].idJoueur << " (" << pileCartesExposee.tab[pileCartesExposee.sommet].lettre << ") ";
                //affichage des cartes
                for (int compteur =0; compteur < joueurs.tabJoueurs[tourDuJoueur].nombreDeCartesEnMain; compteur ++){
                    std::cout << joueurs.tabJoueurs[tourDuJoueur].mainDuJoueur[compteur].lettre;

                }
                std::cout << std::endl;
                afficherTableauMot(tableauDeMot);

                //gesttion de l'entrée du joueur
                while(pointDeControle != ENTREE_VALIDE && pointDeControle != MOT_INVALIDE){
                    std::cout << ">";
                    resultatEntree = LectureCommande(joueurs.tabJoueurs[tourDuJoueur], pileDuTalon, pileCartesExposee,commande, std::cin, tableauDeMot);
                    if (resultatEntree == ENTREE_VALIDE)
                        pointDeControle = ENTREE_VALIDE;
                    else if(resultatEntree == ENTREE_INVALIDE)
                        std::cout  << "Coup invalide, recommencez" << std::endl;
                    else if(resultatEntree == MOT_INVALIDE){
                        std::cout  << "Mot invalide, vous passez votre tour" << std::endl;
                        joueurs.tabJoueurs[tourDuJoueur].nombreDePoints +=3;
                        pointDeControle = MOT_INVALIDE;
                        }
                }
                std::cout << std::endl;
                //vérification que le joueur qui vient de jouer a toujours des cartes, si non, terminer le tour
                if(!verificationJoueurAEncoreDesCartes(joueurs.tabJoueurs[tourDuJoueur])){
                    initialisationNouveauTour(joueurs, jeuDeCartes, tableauDeMot, pileDuTalon, pileCartesExposee);
                    tourDuJoueurDebut++;
                    if(tourDuJoueurDebut >= joueurs.nbJoueursTotal){
                        tourDuJoueurDebut=0;
                    }
                }
            }
        }
    }
    std::cout << "La partie est finie";
    return 0;
}

void initialisationNouveauTour(Joueurs& lesJoueurs, jeuDeCarte& jeuDeCartes, TabMots& tabMots, Pile& pileDuTalon, Pile& pileCartesExposees){
    ajoutPointsFinDeTour(lesJoueurs);
    std::cout << "Le tour est fini" << std::endl << "* Scores" << std::endl;
    for(int compteurJoueur=0; compteurJoueur < lesJoueurs.nbJoueursTotal ; compteurJoueur++) {
        if(verificationJoueurEnLice(lesJoueurs, lesJoueurs.tabJoueurs[compteurJoueur]))
            std::cout << "Joueur " << lesJoueurs.tabJoueurs[compteurJoueur].idJoueur << " : " << lesJoueurs.tabJoueurs[compteurJoueur].nombreDePoints << std::endl;
    }
    for(int compteur=0; compteur<lesJoueurs.nbJoueursTotal; compteur++){
        if(lesJoueurs.tabJoueurs[compteur].nombreDePoints > 100){
            eliminationJoueur(lesJoueurs, lesJoueurs.tabJoueurs[compteur]);
        }
    }

    detruire(pileDuTalon);
    detruire(pileCartesExposees);
    initialiserJeuDeCarte(jeuDeCartes);
    unsigned int indiceCarte=0;
    for(int compteur=0; compteur < lesJoueurs.nbJoueursTotal; compteur++){
        if(verificationJoueurEnLice(lesJoueurs, lesJoueurs.tabJoueurs[compteur])){
            initialiserLaMainDuJoueur(lesJoueurs.tabJoueurs[compteur], jeuDeCartes, indiceCarte);
            indiceCarte++;
        }
    }
    recupererJeuDeCarteRestant(jeuDeCartes, lesJoueurs.nbJoueursEnLice);
    initialiser(pileDuTalon, jeuDeCartes.capacite);
    initialiser(pileCartesExposees, jeuDeCartes.capacite);
    remplirTalonEtExposee(pileDuTalon, pileCartesExposees, jeuDeCartes);
    initialiserTableauDeMot(tabMots, TAILLE_TABLEAU , PAS_EXTENSTION_TABLEAU_MOT);

}


