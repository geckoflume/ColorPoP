#include <string>
#include "constantes.h"

#ifndef GENERATION_H
#define GENERATION_H

struct Emplacement{
    bool sonExistence;
    unsigned int saCouleur;
};

//Genereration d'un nombre aleatoire respectant la loi de probabilite
unsigned int generationNbAleaLoi(double uneLoi[]);

//Genereration de la loi de probabilite
void generationLoi(double totalPionsAPlacer, double loi[], unsigned int nbPionsAPlacer[]);

//Codage du nombre genere en couleur pour l'afficher dans le terminal
unsigned int codageCouleurs(unsigned int unPion);

//Generation des couleurs et peuplement du tableau de jetons
void generationJetons(Emplacement desJetons[DIM][DIM]);

//Conversion en majuscules d'un string
std::string enMajuscules(std::string unMot);

//Initialisation du plateau a partir d'un fichier
bool init(Emplacement unPlateau[DIM][DIM], std::string unNomFichier);

#endif // GENERATION_H
