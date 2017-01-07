/**
 * \file modification.h
 * \brief Declaration des fonctions de modification du plateau du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include "structures.h"

#ifndef MODIFICATION_H
#define MODIFICATION_H

/**
 * \brief Verification que les pieces ont des voisins
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Un bool, true si il reste des voisins, false s'il n'en reste pas
 */
bool aDesVoisins(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Verification que les colonnes sont decalables
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Un bool, true si une colonne est decalable, false sinon
 */
bool estDecalable(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Verification que les colonnes sont vides
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Un bool, true si il y a une colonne vide, false s'il n'y en a pas
 */
bool aSaColonneVide(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Decalage des pieces vers le bas quand une piece est enlevee
 *
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \param[in] unePiece Piece correspondant aux index saisis
 * \return Void
 */
void decalagePiecesVertical(Emplacement desJetons[DIM][DIM], Piece unePiece);

/**
 * \brief Decalage des pieces vers le bas quand une piece est enlevee
 *
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void decalagePiecesVertical(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Decalage des pieces vers la gauche quand une colonne est vide
 *
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void decalagePiecesHorizontal(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Suppression des pieces voisines automatiquement
 *
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \param[in] unePiece Piece correspondant aux index saisis
 * \param[in] desJoueurs Joueur correspondant aux joueurs
 * \param[in] unJoueur Entier correspondant au joueur dont c'est le tour de jouer
 *
 * \return Void
 */
void suppressionVoisins(Emplacement desJetons[DIM][DIM], Piece unePiece, Joueur desJoueurs[2], unsigned int unJoueur);
#endif // MODIFICATION_H
