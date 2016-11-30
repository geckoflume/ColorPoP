#include "constantes.h"
#include "generation.h"

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

//Definition de la couleur du terminal
void couleurConsole(unsigned int laCouleurTexte, unsigned int laCouleurFond);

//Affichage du plateau de jeu
void affichagePlateau(Emplacement desJetons[DIM][DIM]);

//Affichage des jetons
void affichageJetons(unsigned int uneCouleur);

#endif // AFFICHAGE_H
