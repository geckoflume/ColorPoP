/**
 * \file affichage.h
 * \brief Declaration des fonctions d'affichage du TP ColorPoP
 * \author Florian MORNET
 * \version 0.1
 * \date 06 decembre 2016
 */
#include "constantes.h"
#include "generation.h"

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

/**
 * \brief Definir la couleur du terminal, la couleur de fond par defaut est noire
 *
 * \param[in] laCouleurTexte Entier correspondant a la couleur du texte affiche dans la console
 * \param[in] laCouleurFond Entier correspondant a la couleur de fond affichee dans la console, NOIR par defaut
 * \return Void
 */
void couleurConsole(unsigned int laCouleurTexte, unsigned int laCouleurFond);

/**
 * \brief Affichage du plateau de jeu
 * \param[in] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void affichagePlateau(Emplacement desJetons[DIM][DIM]);

#endif // AFFICHAGE_H
