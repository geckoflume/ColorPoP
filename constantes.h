#ifndef CONSTANTES_H
#define CONSTANTES_H

//Constante de la dimension du plateau
const unsigned int DIM=10;

//Constante du caractere ASCII des jetons
const char JETON=4;

//Couleurs des pions
enum Couleur
{
    NOIR,
    BLEU=9,
    VERT,
    ROUGE=12,
    MAGENTA,
    JAUNE,
    BLANC,
};

//Constante du nombre de couleurs possibles
const unsigned int NB_COULEURS=6;

#endif // CONSTANTES_H
