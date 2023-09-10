// declaration
struct Noeud {
  char lettre;
  int  nboccurrence;
  struct Noeud* fgauche;
  struct Noeud* fdroite;
};

typedef struct Noeud* TArbre;

