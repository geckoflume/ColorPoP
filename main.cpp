#include <iostream>
#include "affichage.h"
#include "constantes.h"
#include "generation.h"

int main()
{
    //Declaration et initialisation du tableau de jetons
    unsigned int lesJetons[DIM][DIM]={{0}};

    generationCouleurPeuplementJetons(lesJetons);

    affichagePlateau(lesJetons);

    return 0;
}
