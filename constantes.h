/**
 * \file constantes.h
 * \brief Constantes du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#ifndef CONSTANTES_H
#define CONSTANTES_H

/**
 * \var unsigned int DIM
 * \brief Constante de la dimension du plateau
 */
const unsigned int DIM=10;

/**
 * \var const char JETON
 * \brief Constante du caractere ASCII des jetons
 */
const char JETON=4;

/**
 * \enum Couleur
 *
 * \brief Couleurs des pions
 */
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

/**
 * \enum Erreur
 *
 * \brief Codes des erreurs en sortie des fonctions
 */
enum Erreur
{
    NON_FINI=-10,
    ISOLE=-2,
};

/**
 * \var const unsigned int NB_COULEURS
 * \brief Constante du nombre de couleurs possibles
 */
const unsigned int NB_COULEURS=6;

#endif // CONSTANTES_H
