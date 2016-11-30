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
            affichageJetons(lesJetons[leI][leJ].saCouleur);
        }
    }

    std::cout<<std::endl;

    //Couleur de texte blanche
    couleurConsole(BLANC);
}

void affichageJetons(unsigned int uneCouleur)
{
    //Couleur de texte de la couleur du jeton
    couleurConsole(uneCouleur);
    std::cout<<JETON<<' ';
}
