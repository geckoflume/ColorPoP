#include "constantes.h"

#ifndef GENERATION_H
#define GENERATION_H

//Generer un nombre aleatoire respectant la loi de probabilite
unsigned int generationNbAleaLoi(double uneLoi[]);

//Generer la loi de probabilite
void generationLoi(double totalPionsAPlacer, double loi[], unsigned int nbPionsAPlacer[]);

//Codage du nombre genere en couleur pour l'afficher dans le terminal
unsigned int codageCouleurs(unsigned int unPion);

//Generation des couleurs et peuplement du tableau de jetons
void generationCouleurPeuplementJetons(unsigned int desJetons[][DIM]);

#endif // GENERATION_H
