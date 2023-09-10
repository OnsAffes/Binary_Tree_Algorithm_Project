#ifndef DICO_H_INCLUDED
#define DICO_H_INCLUDED

/* -------------------------------------------------------*/
/* Primitives de gestion d’un dictionnaire */
 /* -------------------------------------------------------*/
// declaration
struct Noeud {
  char lettre;
  int  nboccurrence;
  struct Noeud* fgauche;
  struct Noeud* fdroite;
};

typedef struct Noeud* TArbre;




void dicoAfficher(TArbre a);
void dicoInsererMot(char mot[], TArbre *pa);
int dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsDifferents(TArbre a);
int dicoNbMotsTotal(TArbre a);
void afficherMots(char *mot, TArbre a);
int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);
 /* -------------------------------------------------------*/


#endif

