/**
 * \file affichage.h
 * \brief Declaration des fonctions d'affichage du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include "constantes.h"
#include "structures.h"
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
void couleurConsole(unsigned int laCouleurTexte, unsigned int laCouleurFond=NOIR);

/**
 * \brief Affichage du plateau de jeu
 * \param[in] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void affichage(Emplacement desJetons[DIM][DIM]);

#endif // AFFICHAGE_H
