#include <iostream>
#include "affichage.h"
#include "constantes.h"
#include "generation.h"

int main()
{
    //Declaration et initialisation du tableau de jetons
    Emplacement lesJetons[DIM][DIM];
    for(unsigned int leI=0; leI<DIM; leI++){
        for(unsigned int leJ=0; leJ<DIM; leJ++){
            lesJetons[leI][leJ].sonExistence=true;
            lesJetons[leI][leJ].saCouleur=NOIR;
        }
    }

    /*
    //Verification du nombre de termes du fichier, initialisation du plateau et affichage
    if(init(lesJetons, "save.txt"))
        affichagePlateau(lesJetons);
    else
        std::cout<<"Erreur, le nombre de termes du fichier ne correspond pas a la taille du plateau !\n";
    */

    //Generation, initialisation du plateau et affichage
    generationJetons(lesJetons);
    affichagePlateau(lesJetons);

    return 0;
}
