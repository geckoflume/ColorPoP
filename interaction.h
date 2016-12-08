/**
 * \file interaction.h
 * \brief Declaration des fonctions d'interaction du TP ColorPoP
 * \author Florian MORNET
 * \version 0.1
 * \date 06 decembre 2016
 */
#include "constantes.h"
#include "generation.h"

#ifndef INTERACTION_H
#define INTERACTION_H

/**
 * \brief Selection d'une piece par le joueur
 *
 * \param[out] desIndex unsigned int correspondant aux index saisis
 * \return Void
 */
void selectionPiece(unsigned int desIndex[2]);

/**
 * \brief Decalage des pieces vers le bas quand une piece est enlevee
 *
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \param[in] desIndex unsigned int correspondant aux index saisis
 * \return Void
 */
void decalagePieces(Emplacement desJetons[DIM][DIM], unsigned int desIndex[2]);

/**
 * \brief Interaction avec un joueur
 * \param[in] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void interactionUnJoueur(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Interaction avec un joueur avec gestion des sequences
 * \param[in] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void interactionUnJoueurSequences(Emplacement desJetons[DIM][DIM]);
#endif // INTERACTION_H
