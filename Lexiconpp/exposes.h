#ifndef LEXICONPP_TALON_H
#define LEXICONPP_TALON_H


struct  expose{
    unsigned int capacite;  
    Carte* tab;		
    int sommet;			

};
void initialiser(expose& e, unsigned int c );{

        for (int i = 0; i < taille; ++i)
    empiler(e, m[i]);
        for (int i = 0; i < taille; ++i) {
     m[i] = sommet(e);
    depiler(t);
     }
    detruire(e);
}


bool estVide(const expose& e);{
    E  = 0;
    std::stack<E> temp = elements;  // Utilise une copie pour ne pas modifier la pile originale
        while (!temp.empty()) {
            somme += temp.top();
            temp.pop();
}

void empiler(expose& e, const Carte& Ca);{

    assert(!estPleine(p));
	e.elems[++e.sommet] = Ca;
}
}

void depiler(expose& e){

    assert(!estVide(t));
	int v = e.elems[e.sommet--];
	return v;

}

}