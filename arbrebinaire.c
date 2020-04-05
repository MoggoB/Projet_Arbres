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
	if(EstArbreVide(tree)) {
		return(0);
	} else {
		if (n == Racine(tree)) {
			return(1);
		} else if (n < Racine(tree)) {
			Recherche(n,Gauche(tree));
		} else {
			Recherche(n,Droit(tree));
		}
	}
}

int Max(int a, int b) {
	return(a>b) ? a : b;
}

int Hauteur(arbre tree){
	if(!EstArbreVide(tree)) {
		return(1+Max(Hauteur(Gauche(tree)),Hauteur(Droit(tree))));
	} else {
		return(0);
	}

}


void Largeur(arbre tree, size_t niveau) {
	if(!EstArbreVide(tree)) {
		if(niveau == 1) {
			printf("%d ",Racine(tree));
		} else {
			Largeur(Gauche(tree), niveau-1);
			Largeur(Droit(tree), niveau-1);
		}
	}
}


void ParcoursLarg(arbre tree){
	int h = Hauteur(tree);
	for(size_t niv = 1; niv<=h; niv++) {
		Largeur(tree,niv);
	}
}





