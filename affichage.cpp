/**
 * \file affichage.cpp
 * \brief Gestion de l'affichage du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include <iostream>
#include <windows.h>
#include "affichage.h"
#include "constantes.h"
#include "structures.h"
#include "generation.h"

void couleurConsole(unsigned int laCouleurTexte, unsigned int laCouleurFond)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, laCouleurFond*16+laCouleurTexte);
}


void affichage(Emplacement lesJetons[DIM][DIM])
{
    //Couleur de texte noire, couleur de fond blanche
    couleurConsole(NOIR, BLANC);
    std::cout<<' '<<' ';

    //Affichage des nombres (en horizontal)
    for(unsigned int leI=0; leI<DIM; leI++)
    {
        std::cout<<leI<<' ';
    }

    //Affichage des lettres (en vertical)
    for(unsigned int leI=0; leI<DIM; leI++)
    {
        //Couleur de texte noire, couleur de fond blanche
        couleurConsole(NOIR, BLANC);

        //Decalage de la valeur decimale de la lettre de 65 en ASCII
        std::cout<<std::endl<<char(leI+'A')<<' ';

        //Affichage des jetons
        for(unsigned int leJ=0; leJ<DIM; leJ++)
        {
            couleurConsole(lesJetons[leI][leJ].saCouleur);
            std::cout<<JETON<<' ';
        }
    }

    std::cout<<std::endl;

    //Couleur de texte blanche
    couleurConsole(BLANC);
}
