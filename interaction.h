/**
 * \file interaction.h
 * \brief Declaration des fonctions d'interaction du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include "constantes.h"
#include "structures.h"

#ifndef INTERACTION_H
#define INTERACTION_H

/**
 * \brief Initialisation du tableau de joueurs
 * \param[in] desJoueurs Joueur correspondant aux joueurs
 * \return Void
 */
void initialisationJoueurs(Joueur desJoueurs[2]);

/**
 * \brief Selection d'une piece par le joueur
 *
 * \param[out] unePiece Piece correspondant aux index saisis
 * \return Void
 */
void selectionPiece(Piece & unePiece);

/**
 * \brief Selection d'une piece par le joueur
 *
 * \param[out] unePiece Piece correspondant aux index saisis
 * \param[out] uneSecondePiece Piece correspondant aux index saisis si la premiere piece est blanche
 * \param[in] desJoueurs Joueur correspondant aux joueurs
 * \param[in] unJoueur Entier correspondant au joueur dont c'est le tour de jouer
 * \param[in] desJetons Emplacement correspondant au plateau de jetons
 * \return Un bool, true si le joueur a correctement selectionne une piece, false si il a perdu son tour
 */
bool selectionPiece(Piece & unePiece, Piece & uneSecondePiece, Joueur desJoueurs[2], unsigned int unJoueur, Emplacement desJetons[DIM][DIM]);

/**
 * \brief Detection de la fin de la partie
 * \param[in] desJetons Emplacement correspondant au plateau de jetons
 * \param[in, out] desJoueurs Joueur correspondant aux joueurs
 * \return Un entier, NON_FINI si la partie n'est pas finie, ISOLE si il ne reste que des pieces isolees, le joueur gagnant sinon
 */
int detectionFinPartie(Emplacement desJetons[DIM][DIM], Joueur desJoueurs[2]);

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

/**
 * \brief Interaction avec deux joueurs avec suppression automatique des voisins
 * \param[in] desJetons Emplacement correspondant au plateau de jetons
 * \param[in] desJoueurs Joueur correspondant aux joueurs
 * \return Void
 */
void interactionDeuxJoueurs(Emplacement desJetons[DIM][DIM], Joueur desJoueurs[2]);

/**
 * \brief Affichage du menu et gestion de la saisie
 * \param[in] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void menu(Emplacement desJetons[DIM][DIM]);
#endif // INTERACTION_H
