#include <stdlib.h>
#include <stdio.h>

#include "arbrebinaire.h"

arbre ArbreVide() {
	arbre tree = NULL;
	return tree;
}

int EstArbreVide(arbre tree) {
	return(tree == NULL);
}

element Racine(arbre tree) {
	return tree->e;
}

arbre Gauche(arbre tree) {
	return tree->gauche;
}


arbre Droit(arbre tree) {
	return tree->droit;
}

arbre Construire(element n, arbre gauche, arbre droit) {
	arbre tree = ArbreVide();
	tree = (arbre)malloc(sizeof(struct noeud));
	tree->e = n;
	tree->gauche = gauche;
	tree->droit = droit;
	return tree;
}

void ParcoursPref(arbre tree) {
	if (!EstArbreVide(tree)) {
		printf("%d ",Racine(tree));
		arbre gauche = Gauche(tree);
		ParcoursPref(gauche);
		arbre droit = Droit(tree);
		ParcoursPref(droit);
	}
}

void ParcoursInf(arbre tree) {
	if (!EstArbreVide(tree)) {
		arbre gauche = Gauche(tree);
		ParcoursPref(gauche);
		printf("%d ",Racine(tree));
		arbre droit = Droit(tree);
		ParcoursPref(droit);
	}
}

void ParcoursSuff(arbre tree) {
	if (!EstArbreVide(tree)) {
		arbre gauche = Gauche(tree);
		ParcoursPref(gauche);
		arbre droit = Droit(tree);
		ParcoursPref(droit);
		printf("%d ",Racine(tree));
	}
}

arbre Insertion(element n, arbre tree) {
	if (EstArbreVide(tree)) {
		tree = Construire(n,ArbreVide(),ArbreVide());              
	} else {
		if (Racine(tree)>n) {
			tree->gauche = Insertion(n,Gauche(tree));
		} else {
			if (Racine(tree)<n) {
					tree->droit = Insertion(n,Droit(tree));
			}
		}
	}
	return tree;
}


int Recherche(element n, arbre tree) {
	return 0;
}





