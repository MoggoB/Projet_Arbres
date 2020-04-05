#include <stdlib.h>
#include <stdio.h>

#include "arbrebinaire.h"

int main(int argc, char **argv){
	if(argc!=3) {
		printf("Erreur: Il manque un ou des argument(s) \n");
		exit(EXIT_FAILURE);
	}
	char *filename = argv[1];
	FILE *f;
	f = fopen(filename,"r");
	if(f==NULL) {
		printf("Impossible d'ouvrir le fichier\n");
		exit(EXIT_FAILURE);
	}
	size_t sizefile;
	fseek(f,0,SEEK_END);
	sizefile = ftell(f)+1;
	fseek(f,0,SEEK_SET);

	arbre tree = ArbreVide();
	for(size_t line = 0; line < sizefile; line++) {
		int element;
		fscanf(f, "%d", &element);
		tree = Insertion(element,tree);
	}

	//Parcours
	printf("Pref : \n");
	ParcoursPref(tree);
	printf("\n");
	printf("Inf : \n");
	ParcoursInf(tree);
	printf("\n");
	printf("Suff : \n");
	ParcoursSuff(tree);
	printf("\n");
	printf("Larg : \n");
	ParcoursLarg(tree);
	printf("\n");
	
	//Recherche d'un element dans l'arbre
	
	char *a = argv[2];
	int n = atoi(a);
	if(Recherche(n,tree)){
		printf("Element %d dans l'arbre = VRAI\n", n);
	} else {
		printf("Element %d dans l'arbre = FALSE\n", n);
	}

}
