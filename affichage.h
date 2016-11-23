#include "constantes.h"

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

//Définir la couleur du terminal
void couleurConsole(unsigned int laCouleurTexte, unsigned int laCouleurFond);

//Afficher le plateau de jeu
void affichagePlateau(unsigned int desJetons[][DIM]);

//Afficher les jetons
void affichageJetons(unsigned int desJetons[][DIM], unsigned int unI, unsigned int unJ);

#endif // AFFICHAGE_H
