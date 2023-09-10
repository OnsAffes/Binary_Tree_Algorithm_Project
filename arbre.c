#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"


/* -------------------------------------------------------*/
/* Primitives de gestion des arbres */
/* -------------------------------------------------------*/
TArbre arbreConsVide()
{
  return NULL;
}

int arbreEstVide(TArbre a)
{

  return (a==NULL);
}

TArbre arbreCons(char c, int n, TArbre fg, TArbre fd)
{
  TArbre a = (TArbre)malloc(sizeof(struct Noeud));
  a->lettre     = c;
  a->nboccurrence      = n;
  a->fgauche = fg;
  a->fdroite  = fd;
  return a;
}

char arbreRacineLettre(TArbre a)
{
  return a->lettre;
}

int arbreRacineNbOcc(TArbre a)
{
  return a->nboccurrence;
}

TArbre arbreFilsDroit(TArbre a)
{
  return a->fdroite;
}

TArbre arbreFilsGauche(TArbre a)
{
  return a->fgauche;
}



void arbreSuppr(TArbre a)
{
  if (arbreEstVide(a)==1)
    {
      arbreSuppr(a->fgauche);
      arbreSuppr(a->fdroite);
      free(a);
    }
}




