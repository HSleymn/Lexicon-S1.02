
// program named mainreturn.cpp
#include "talonEtExposee.h"

#define TAILLE_TABLEAU 5
#define PAS_EXTENSTION_TABLEAU_MOT 2



//    defining main with arguments
int main(int argc, char** argv)
{
    unsigned int nbJoueurs = atoi(argv[1]);
    jeuDeCarte jeuDeCartes;
    initialiserJeuDeCarte(jeuDeCartes);
    Joueurs joueurs;
    initialiserLesJoueurs(joueurs, nbJoueurs, jeuDeCartes);
    std::cout << std::endl;


    recupererJeuDeCarteRestant(jeuDeCartes, joueurs.nbJoueursEnLice);

    Pile pileDuTalon;
    initialiser(pileDuTalon, jeuDeCartes.capacite);

    Pile pileCartesExposee;
    initialiser(pileCartesExposee, jeuDeCartes.capacite);

    remplirTalonEtExposee(pileDuTalon, pileCartesExposee, jeuDeCartes);


    //affichage
    Commande commande;
    int pointDeControle = ETAT_DE_BASE;
    int resultatEntree;
    TabMots tableauDeMot;
    initialiserTableauDeMot(tableauDeMot, TAILLE_TABLEAU , PAS_EXTENSTION_TABLEAU_MOT);

    while(joueurs.nbJoueursEnLice > 1){
        for (int tourDuJoueur = 0; tourDuJoueur < joueurs.nbJoueursEnLice; tourDuJoueur++) {
            afficherTableauMot(tableauDeMot);
            pointDeControle = ETAT_DE_BASE;
            if (estVide(pileDuTalon)){
                rechargementDuTalon(pileDuTalon, pileCartesExposee);
            }

            std::cout << "* Joueur" << joueurs.tabJoueurs[tourDuJoueur].idJoueur << "(" << pileCartesExposee.tab[pileCartesExposee.sommet].lettre << ") ";
        for (int compteur =0; compteur < joueurs.tabJoueurs[tourDuJoueur].nombreDeCartesEnMain; compteur ++){
            std::cout << joueurs.tabJoueurs[tourDuJoueur].mainDuJoueur[compteur].lettre;

        }
            std::cout << std::endl;

            while(pointDeControle != ENTREE_VALIDE && pointDeControle != MOT_INVALIDE){
                std::cout << ">";
                resultatEntree = LectureCommande(joueurs.tabJoueurs[tourDuJoueur], pileDuTalon, pileCartesExposee,commande, std::cin, tableauDeMot);
                if (resultatEntree == ENTREE_VALIDE)
                    pointDeControle = ENTREE_VALIDE;
                else if(resultatEntree == ENTREE_INVALIDE)
                    std::cout  << "Coup invalide, recommencez" << std::endl;
                else if(resultatEntree == MOT_INVALIDE){
                    std::cout  << "Mot invalide, vous passez votre tour" << std::endl;
                    pointDeControle = MOT_INVALIDE;
                    }
            }
            std::cout << std::endl;


    }


    }
    }


