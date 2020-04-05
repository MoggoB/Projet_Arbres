#ifndef _ARBREBINAIRE_
#define _ARBREBINAIRE_

typedef int element;

typedef struct noeud {
	element e;
	struct noeud*droit;
	struct noeud*gauche;
}*arbre;

arbre ArbreVide();        // renvoie un arbre vide
int EstArbreVide(arbre tree);  // teste si un arbre est vide
element Racine(arbre tree);    //renvoie la valeur de la racine de l’arbre
arbre Gauche(arbre tree);      //renvoie le sous-arbre gauche
arbre Droit(arbre tree);       //renvoie le sous-arbre droit
arbre Construire(element n, arbre gauche, arbre droit);
void ParcoursPref(arbre tree);
void ParcoursInf(arbre tree);
void ParcoursSuff(arbre tree);
arbre Insertion(element n, arbre tree);
int Recherche(element n, arbre tree);
void ParcoursLarg(arbre tree);
int Max(int a, int b);
int Hauteur(arbre tree);
void Largeur(arbre tree, size_t niveau);
#endif
