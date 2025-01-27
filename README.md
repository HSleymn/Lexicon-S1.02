# Lexicon S1.02

Ce projet a été mon deuxième projet en 1ère année de BUT Informatique, intégralement réalisé en C++.

## But du jeu

Le but du projet est de développer un logiciel permettant à un ensemble de joueurs de disputer une partie de Lexicon. L’application doit veiller au respect des règles du jeu et gérer la totalité du déroulement de la partie jusqu’à l’annonce du gagnant. Chaque joueur dispose au début de chaque partie de 10 cartes (en réalité des lettres) et le but de vider sa main. 

## Avant de lancer une partie..

Assurez-vous d'entrer en paramètre un nombre valide de joueur allant de 2 à 4.

## Comment jouer ?

5 choix possibles : piocher du talon, piocher la carte exposée, poser un mot, remplacer un mot déjà posé ou compléter un mot déja posé.
Ce jeu se joue entièrement dans le terminal, ainsi pour lancer chacune des possibilités citées, voici comment faire:

**Piocher du talon**

```Input : T "lettre à remplacer"```

La lettre à remplacer doit impérativement être présente dans la main.

*Exemple :*

```
(Commandes valides : TEPRC)
* Joueur 1 (G) KBGEDNSCEB
> T K
.
.

* Joueur 1 (I) QBGEDNSCEB
> 
```
On voit que le K à été remplacer par le Q.
Il est important de savoir que la carte choisies dans la main du joueur devient la carte exposée courante.

**Piocher la carte exposée**

```Input : E "lettre à remplacer"```

La lettre à remplacer doit impérativement être présente dans la main.
La carte exposées est la carte qui figure entre parenthèse.
Elle est énoncée à chaque tour.

*Exemple :*

```
* Joueur 2 (D) EQALHEJRNH
> E Q
.
.

* Joueur 2 (Q) EDALHEJRNH
1 - SE
> 
```

**Poser un mot**

```Input : P "mot à placer"```

Les lettres du mot à placer doivent être impérativement présentes dans la main.

*Exemple :*

```
* Joueur 1 (Q) TIGEDNSCEB
> P SE
.
.
* Joueur 1 (E) TIGDNCEB
1 - SE
> 
```
Les lettres ont bien été retirées.

**Compléter un mot déjà posé**

```Input : C "identifiant du mot à compléter" "mot avec la complétion"```

Les lettres additionnelles au mot originel doivent être impérativement présentes dans la main.
L'identifiant du mot doit être correct.
Le nouveau mot doit être un mot valide.

*Exemple :*

```
* Joueur 1 (J) ADEECHAGEB
> P DE

* Joueur 2 (J) HGFOISIRNU
1 - DE
> C 1 DESIR
.
.
* Joueur 2 (A) HGFOINU
1 - DESIR
> 
```
