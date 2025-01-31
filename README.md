# Lexicon S1.02

Lexicon est un jeu de cartes et de mots où les joueurs tentent de vider leur main en formant des mots valides à partir des lettres qu'ils possèdent. Ce projet est une implémentation en C++ de ce jeu, développé dans le cadre d'un projet de première année de BUT Informatique.

---

## 📋 Table des matières
1. But du jeu
2. Fonctionnalités
3. Structure du projet
4. Comment jouer ?
5. Installation
6. Compilation et exécution
7. Contribution
8. Auteur
9. Licence
---

## 🎯 But du jeu

Le but du jeu est de vider sa main de cartes en formant des mots valides à partir des lettres disponibles. Chaque joueur commence avec 10 cartes (lettres) et doit les utiliser pour créer des mots. Le jeu se termine lorsqu'un joueur réussit à vider sa main ou lorsque les conditions de fin de partie sont remplies.

---

## 🛠 Fonctionnalités

- **Gestion des joueurs** : Initialisation des joueurs, distribution des cartes et suivi des points.
- **Gestion des cartes** : Mélange des cartes, distribution et gestion du talon et de la pile de cartes exposées.
- **Validation des mots** : Vérification des mots proposés par les joueurs à l'aide d'un dictionnaire.
- **Commandes du jeu** :
  - **Piocher une carte** : Tirer une carte du talon ou de la pile exposée.
  - **Échanger une carte** : Échanger une carte de sa main avec la carte au sommet de la pile des cartes exposées.
  - **Poser un mot** : Utiliser les lettres de sa main pour former un mot valide.
  - **Remplacer un mot** : Remplacer un mot déjà posé par un nouveau mot.
  - **Compléter un mot** : Ajouter des lettres à un mot déjà posé pour en former un nouveau.
- **Fin de partie** : Calcul des scores et détermination du gagnant.

---

## 📂 Structure du projet

Le projet est structuré comme suit :

hsleymn-lexicon-s1.02/
├── README.md
├── carte.cpp
├── carte.h
├── commandes.cpp
├── commandes.h
├── joueur.cpp
├── joueur.h
├── main.cpp
├── main.h
├── mots.cpp
├── mots.h
├── pile.cpp
├── pile.h
├── talonEtExposee.cpp
└── talonEtExposee.h
Copy


### Description des fichiers principaux :
- **`carte.cpp` / `carte.h`** : Gestion des cartes et du jeu de cartes.
- **`joueur.cpp` / `joueur.h`** : Gestion des joueurs, de leurs mains et de leurs points.
- **`mots.cpp` / `mots.h`** : Validation des mots et gestion du dictionnaire.
- **`pile.cpp` / `pile.h`** : Implémentation d'une pile pour gérer le talon et les cartes exposées.
- **`commandes.cpp` / `commandes.h`** : Gestion des commandes du jeu (piocher, poser un mot, etc.).
- **`talonEtExposee.cpp` / `talonEtExposee.h`** : Gestion du talon et de la pile de cartes exposées.
- **`main.cpp` / `main.h`** : Point d'entrée du programme et gestion du déroulement de la partie.

---

## 🎮 Comment jouer ?

### Commandes disponibles :
1. **Piocher du talon** :
   ```bash
   T <lettre_à_remplacer>

 Exemple : T K pour remplacer la lettre K par une carte du talon.  

 Piocher la carte exposée :

    E <lettre_à_remplacer>

 Exemple : E Q pour remplacer la lettre Q par la carte exposée.
 Poser un mot :


    P <mot_à_poser>

 Exemple : P SE pour poser le mot "SE".
 
 Remplacer un mot :
    

    R <id_du_mot> <nouveau_mot>

 Exemple : R 1 SON pour remplacer le mot à l'identifiant 1 par "SON".

 Compléter un mot :

    C <id_du_mot> <mot_complété>

 Exemple : C 1 DESIR pour compléter le mot à l'identifiant 1 en "DESIR".

💻 Installation

Clonez le dépôt :
    
    git clone https://github.com/HSleymn/hsleymn-lexicon-s1.02.git

Accédez au répertoire du projet :


    cd hsleymn-lexicon-s1.02

🛠 Compilation et exécution

Compilez le programme :
   

    g++ main.cpp carte.cpp commandes.cpp joueur.cpp mots.cpp pile.cpp talonEtExposee.cpp -o lexicon

Exécutez le programme :


    ./lexicon <nombre_de_joueurs>

Remplacez <nombre_de_joueurs> par un nombre entre 2 et 4.


👤 Auteur

    HADJ MESSAOUD Souleymane - HSleymn

📜 Licence

Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.
