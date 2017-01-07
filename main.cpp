/**
 * \file main.cpp
 * \brief Fichier principal du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include <iostream>
#include "affichage.h"
#include "constantes.h"
#include "structures.h"
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

    //Declaration du tableau de joueurs
    Joueur lesJoueurs[2];

    initialisationJoueurs(lesJoueurs);

    /*
    //Verification du nombre de termes du fichier, initialisation du plateau et affichage
    if(init(lesJetons, "save.txt"))
        affichage(lesJetons);
    else
        std::cout<<"Erreur, le nombre de termes du fichier ne correspond pas a la taille du plateau !\n";
    */

    //Generation, initialisation du plateau et affichage
    generation(lesJetons);
    affichage(lesJetons);

    //interactionUnJoueur(lesJetons);
    //interactionUnJoueurSequences(lesJetons);
    interactionDeuxJoueurs(lesJetons, lesJoueurs);

    return 0;
}
