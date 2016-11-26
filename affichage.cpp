#include <iostream>
#include <windows.h>
#include "affichage.h"
#include "constantes.h"
#include "generation.h"


//Définir la couleur du terminal, la couleur de fond par defaut est noire
void couleurConsole(unsigned int laCouleurTexte, unsigned int laCouleurFond=NOIR)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, laCouleurFond*16+laCouleurTexte);
}


void affichagePlateau(Emplacement lesJetons[][DIM])
{
    //Couleur de texte noire, couleur de fond blanche
    couleurConsole(NOIR, BLANC);
    std::cout<<' '<<' ';

    //Affichage des nombres (en horizontal)
    for(unsigned int leJ=0; leJ<DIM; leJ++)
    {
        std::cout<<leJ<<' ';
    }

    //Affichage des lettres (en vertical)
    for(unsigned int leI=0; leI<DIM; leI++)
    {
        //Couleur de texte noire, couleur de fond blanche
        couleurConsole(NOIR, BLANC);

        //Decalage de la valeur decimale de la lettre de 65 en ASCII
        std::cout<<std::endl<<char(leI+65)<<' ';

        //Affichage des jetons
        for(unsigned int leK=0; leK<DIM; leK++)
        {
            affichageJetons(lesJetons, leI, leK);
        }
    }

    std::cout<<std::endl;

    //Couleur de texte blanche
    couleurConsole(BLANC);
}

void affichageJetons(Emplacement desJetons[][DIM], unsigned int unI, unsigned int unJ)
{
    //Couleur de texte de la couleur du jeton
    couleurConsole(desJetons[unI][unJ].saCouleur);
    std::cout<<JETON<<' ';
}
