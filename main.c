#include <stdlib.h>
#include <stdio.h>

#include "arbrebinaire.h"

int main(void){
	arbre tree = ArbreVide();
	int vide = EstArbreVide(tree);
	if (vide){
		printf("L'arbre est vide\n");
	} else {
		printf("L'arbre n'est pas vide\n");
	}
	arbre droit = Construire(1,ArbreVide(),ArbreVide());
	arbre gauche = Construire(5,ArbreVide(),ArbreVide());
	tree = Construire(7,gauche,droit);
	printf("Pref : \n");
	ParcoursPref(tree);
	printf("\n");
	printf("Inf : \n");
	ParcoursInf(tree);
	printf("\n");
	printf("Suff : \n");
	ParcoursSuff(tree);
	printf("\n");
	/*-----------------------------------------*/
	arbre newtree = ArbreVide();
        newtree = Insertion(8,newtree);
	newtree = Insertion(10,newtree);
	newtree = Insertion(6,newtree);
	newtree = Insertion(12,newtree);
	newtree = Insertion(9,newtree);
	printf("==========NewTree======\n");
	ParcoursSuff(newtree);
	printf("\n");
}


