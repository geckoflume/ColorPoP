/**
 * \file main.cpp
 * \brief Fichier principal du TP ColorPoP
 * \author Florian MORNET
 * \version 0.1
 * \date 06 decembre 2016
 */
#include <iostream>
#include "affichage.h"
#include "constantes.h"
#include "generation.h"
#include "interaction.h"

/**
 * \brief Fonction principale
 *
 * \return Un entier
 */
int main()
{
    //Declaration du tableau de jetons
    Emplacement lesJetons[DIM][DIM];

    /*
    //Verification du nombre de termes du fichier, initialisation du plateau et affichage
    if(init(lesJetons, "save.txt"))
        affichagePlateau(lesJetons);
    else
        std::cout<<"Erreur, le nombre de termes du fichier ne correspond pas a la taille du plateau !\n";
    */

    //Generation, initialisation du plateau et affichage
    generationJetons(lesJetons);
    affichagePlateau(lesJetons);

    //interactionUnJoueur(lesJetons);
    interactionUnJoueurSequences(lesJetons);

    return 0;
}
