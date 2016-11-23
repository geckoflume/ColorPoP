#include <iostream>
#include "affichage.h"
#include "constantes.h"

int main()
{
    //Declaration et initialisation du tableau de jetons
    unsigned int lesJetons[DIM][DIM]={{0}};

    affichagePlateau(lesJetons);

    return 0;
}
