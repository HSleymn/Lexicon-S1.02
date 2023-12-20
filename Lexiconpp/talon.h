#ifndef LEXICONPP_TALON_H
#define LEXICONPP_TALON_H


struct Talon {
    unsigned int capacite;  
    Carte* tab;		
    int sommet;			

};

void initialiser(Talon& t, unsigned int c );{

        for (int i = 0; i < taille; ++i)
    empiler(t, m[i]);
        for (int i = 0; i < taille; ++i) {
     m[i] = sommet(t);
    depiler(t);
     }
    detruire(t);
}


bool estVide(const Talon& t);{
    T  = 0;
    std::stack<T> temp = elements;  // Utilise une copie pour ne pas modifier la pile originale
        while (!temp.empty()) {
            somme += temp.top();
            temp.pop();
}

void empiler(Talon& t, const Carte& Ca);{

    assert(!estPleine(p));
	t.elems[++t.sommet] = Ca;
}
}

void depiler(Talon& t){

    assert(!estVide(t));
	int v = t.elems[t.sommet--];
	return v;



}




