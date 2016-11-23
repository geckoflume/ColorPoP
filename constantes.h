#ifndef CONSTANTES_H
#define CONSTANTES_H

//Constante de la dimension du plateau
const unsigned int DIM=10;

//Constante du caractere ASCII des jetons
const char LE_CHAR_JETON=4;

//Couleurs des pions
enum Couleur
{
    noir,
    bleu=9,
    vert_clair,
    rouge=12,
    magenta,
    jaune,
    blanc,
};

//Constante du nombre de couleurs possibles
const unsigned int NB_COULEURS=6;

#endif // CONSTANTES_H
