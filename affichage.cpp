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


void repetitionCaractere(unsigned int unNombre, char unChar)
{
    for(unsigned int leI(0); leI<unNombre; leI++)
        std::cout<<unChar;
}


void afficherMenu()
{
    std::cout<<"   ______      __           ____        ____     ______"<<std::endl;
    std::cout<<"  / ____/___  / /___  _____/ __ \\____  / __ \\   / ____/__    __"<<std::endl;
    std::cout<<" / /   / __ \\/ / __ \\/ ___/ /_/ / __ \\/ /_/ /  / /  __/ /___/ /_"<<std::endl;
    std::cout<<"/ /___/ /_/ / / /_/ / /  / ____/ /_/ / ____/  / /__/_  __/_  __/"<<std::endl;
    std::cout<<"\\____/\\____/_/\\____/_/  /_/    \\____/_/       \\____//_/   /_/"<<std::endl;
    std::cout<<std::endl<<std::endl;
    std::cout<<'\t'<<"Bienvenue dans le mini-jeu ColorPop !"<<std::endl;
    std::cout<<char(201);
    repetitionCaractere(55, 205);
    std::cout<<char(187)<<std::endl;
    std::cout<<char(186)<<" Choisissez une option pour demarrer une partie :";
    repetitionCaractere(6, ' ');
    std::cout<<char(186)<<std::endl;
    std::cout<<char(186);
    repetitionCaractere(55, ' ');
    std::cout<<char(186)<<std::endl;
    std::cout<<char(186)<<'\t'<<"1. Plateau aleatoire";
    repetitionCaractere(28, ' ');
    std::cout<<char(186)<<std::endl;
    std::cout<<char(186)<<'\t'<<"2. Charger depuis un fichier";
    repetitionCaractere(20, ' ');
    std::cout<<char(186)<<std::endl;
    std::cout<<char(200);
    repetitionCaractere(55, 205);
    std::cout<<char(188)<<std::endl;
}
