#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "arbre.h"


/* -------------------------------------------------------*/
/* Primitives de gestion d’un dictionnaire */
/* -------------------------------------------------------*/
int dicoNbOcc(char mot[], TArbre a){
int i=0,tmp=0;
char end='\0';

if(mot[i]!=arbreRacineLettre(a)){
    while(!arbreEstVide(a) && mot[i]!=arbreRacineLettre(a)){
        a=arbreFilsDroit(a);
    }
    if(arbreEstVide(a)){
        return 0;
    }
}



while(mot[i] != end && !arbreEstVide(a)){

    if(mot[i] != end){
        if(mot[i]==arbreRacineLettre(a)){
            i++;
            a=arbreFilsGauche(a);
        }else{
        a=arbreFilsDroit(a);
        }
    }


}
if(mot[i] == end){
    return arbreRacineNbOcc(a);
}
return 0;
}
/* -------------------------------------------------------*/
int dicoNbMotsDifferents(TArbre a){
    char end='\0';
if(!arbreEstVide(a)){
        if(arbreRacineLettre(a)==end){
            return 1+dicoNbMotsDifferents(arbreFilsGauche(a))+dicoNbMotsDifferents(arbreFilsDroit(a));
        }

    return dicoNbMotsDifferents(arbreFilsGauche(a))+dicoNbMotsDifferents(arbreFilsDroit(a));
}else{
return 0;
}
}
/*-------------------------------------------------------*/
int dicoNbMotsTotal(TArbre a){
    char end='\0';
if(!arbreEstVide(a)){
        if(arbreRacineLettre(a)==end){

            return arbreRacineNbOcc(a)+dicoNbMotsTotal(arbreFilsGauche(a))+dicoNbMotsTotal(arbreFilsDroit(a));
        }

    return dicoNbMotsTotal(arbreFilsGauche(a))+dicoNbMotsTotal(arbreFilsDroit(a));
}else{
return 0;
}
}
/*-------------------------------------------------------*/
void dicoInsererMot(char mot[], TArbre *pa)
{
    char end='\0';
    if (*pa != NULL)
    {
        if (mot[0] != end)
        {if ((*pa)->lettre == mot[0])
            {
                mot++;
                dicoInsererMot(mot, &((*pa)->fgauche));
            }
            else
            {
                if ((*pa)->fdroite != NULL){dicoInsererMot(mot, &((*pa)->fdroite));}
                else
                {
                    (*pa)->fdroite = arbreCons(mot[0], 0, NULL, NULL);
                    dicoInsererMot(mot, &(*pa));
                }
            }
        }
        else if ((*pa)->lettre != end && mot[0] == end)
        {
                    TArbre a = arbreCons(end, 1, NULL, *pa);
                    *pa = a;
        }
        else if ((*pa)->lettre == end && mot[0] == end){(*pa)->nboccurrence=(*pa)->nboccurrence+1;}
    }
    else
    {if (mot[0] != end)
        {
            *pa = arbreCons(mot[0], 0, NULL, NULL);
            mot++;dicoInsererMot(mot, &((*pa)->fgauche));
        }
        else{*pa = arbreCons(end, 1, NULL, NULL);}
    }
}
/*-------------------------------------------------------*/
void afficherElements(char mot[], TArbre a)
{
    char end='\0';

    if (a !=NULL)
    {
        if (arbreRacineLettre(a) != end)
        {
            if (a->fgauche !=NULL)
            {
                afficherElements(mot, a->fdroite);
            }
            if (a->fgauche !=NULL)
            {
                strcat(mot, (char[2]){arbreRacineLettre(a), end});
                afficherElements(mot, arbreFilsGauche(a));
            }
            mot[strlen(mot)-1] = end;
        }
        else
        {
            printf("\"%s\"\n",mot);
            if (a->fdroite!=NULL)
                afficherElements(mot, arbreFilsDroit(a));
        }
    }
}

void dicoAfficher(TArbre a)
{
    printf("\nListe des mots:\n");
    char mots[255] = "";
    afficherElements(mots, a);
}



int nombreAleatoire(int nombreMax)

{
srand(time(NULL));
 return (rand() % nombreMax);
}


int piocherMot(char *motPioche)

{



    FILE* dico = NULL;
    dico = fopen("dico.txt", "r");

    int nombreMots = 0, numMotChoisi = 0, i = 0;

    int caractereLu = 0;

    if (dico == NULL)

    {

        printf("\nImpossible de charger le dictionnaire de mots");

        return 0;
    }


    do{

        caractereLu = fgetc(dico);

        if (caractereLu == '\n')

            nombreMots++;

    } while(caractereLu != EOF);


    numMotChoisi = nombreAleatoire(nombreMots);

    rewind(dico);

    while (numMotChoisi > 0)

    {

        caractereLu = fgetc(dico);

        if (caractereLu == '\n')

            numMotChoisi--;

    }


    fgets(motPioche, 100, dico);


    motPioche[strlen(motPioche) - 1] = '\0';

    fclose(dico);



    return 1;

}



