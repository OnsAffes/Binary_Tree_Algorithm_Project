#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
// declaration
struct Noeud {
  char lettre;
  int  nboccurrence;
  struct Noeud* fgauche;
  struct Noeud* fdroite;
};

typedef struct Noeud* TArbre;

/* -------------------------------------------------------*/
/* Primitives de gestion des arbres */
 /* -------------------------------------------------------*/
TArbre arbreConsVide(void);
int arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
char arbreRacineLettre(TArbre a);
int arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
void arbreSuppr(TArbre a);

/* -------------------------------------------------------*/



#endif
