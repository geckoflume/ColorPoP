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

    menu(lesJetons);

    initialisationJoueurs(lesJoueurs);

    //interactionUnJoueur(lesJetons);
    //interactionUnJoueurSequences(lesJetons);
    interactionDeuxJoueurs(lesJetons, lesJoueurs);

    return 0;
}
