#include "constantes.h"
#include "generation.h"

#ifndef INTERACTION_H
#define INTERACTION_H

//Selection d'une piece par le joueur
void selectionPiece(unsigned int desIndex[2]);

//Decalage des pieces vers le bas quand une piece est enlevee
void decalagePieces(Emplacement desJetons[DIM][DIM], unsigned int desIndex[2]);

//Interaction avec un joueur
void interactionUnJoueur(Emplacement desJetons[DIM][DIM]);

#endif // INTERACTION_H
