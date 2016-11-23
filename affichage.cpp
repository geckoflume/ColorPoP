#include <iostream>
#include <windows.h>
#include "affichage.h"
#include "constantes.h"

void affichagePlateau(unsigned int lesJetons[][DIM])
{
    std::cout<<' '<<' ';

    //Affichage des nombres (en horizontal)
    for(unsigned int leJ=0; leJ<DIM; leJ++)
    {
        std::cout<<leJ<<' ';
    }

    //Affichage des lettres (en vertical)
    for(unsigned int leI=0; leI<DIM; leI++)
    {
        //Decalage de la valeur decimale de la lettre de 65 en ASCII
        std::cout<<std::endl<<char(leI+65)<<' ';

        //Affichage des jetons
        for(unsigned int leK=0; leK<DIM; leK++)
        {
            affichageJetons(lesJetons, leI, leK);
        }
    }

    std::cout<<std::endl;
}


void affichageJetons(unsigned int desJetons[][DIM], unsigned int unI, unsigned int unJ)
{
    std::cout<<LE_CHAR_JETON<<' ';
}
