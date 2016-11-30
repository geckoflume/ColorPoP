#include <iostream>
#include <stdlib.h>
#include "constantes.h"
#include "generation.h"
#include "affichage.h"

void selectionPiece(unsigned int desIndex[2])
{
    char laSaisie(0);
    unsigned int leCptSaisieLignes(0);
    unsigned int leCptSaisieColonnes(0);

    //Saisie de l'index de ligne
    do
    {
        if(leCptSaisieLignes>0)
            std::cout<<"Erreur, ligne incorrecte !\n";
        std::cout<<"Saisir une ligne [A-J] : ";
        std::cin>>laSaisie;
        std::cin.ignore();
        leCptSaisieLignes++;
    }while(laSaisie<'A'||(laSaisie>'J'&&laSaisie<'a')||laSaisie>'j');

    //Prolongement Etape 4, conversion de la ligne saisie (char) en minuscule (ou en majuscule) en entier
    if(laSaisie>='a')
        desIndex[0]=laSaisie-'a';
    else
        desIndex[0]=laSaisie-'A';

    //Saisie de l'index de colonne
    do
    {
        if(leCptSaisieColonnes>0)
            std::cout<<"Erreur, colonne incorrecte !\n";
        std::cout<<"Saisir une colonne [0-9] : ";
        std::cin>>laSaisie;
        std::cin.ignore();
        leCptSaisieColonnes++;
    }while(laSaisie<'0'||laSaisie>'9');

    //Conversion de la colonne saisie (char) en entier
    desIndex[1]=laSaisie-'0';
}


void decalagePieces(Emplacement desJetons[DIM][DIM], unsigned int desIndex[2])
{
    int leI(desIndex[0]);

    for( ; leI>=0&&desJetons[leI][desIndex[1]].sonExistence; leI--)
        desJetons[leI][desIndex[1]].saCouleur=desJetons[leI-1][desIndex[1]].saCouleur;

    //La piece la plus haute de la colonne est descendue, elle n'existe donc plus
    desJetons[leI+1][desIndex[1]].sonExistence=false;
    desJetons[leI+1][desIndex[1]].saCouleur=NOIR;
}


void interactionUnJoueur(Emplacement desJetons[DIM][DIM])
{
    unsigned int lesIndex[2];
    unsigned int leCptSaisiePiece(0);

    //Initialisation du champ sesVoisins pour chaque jeton
    aDesVoisins(desJetons);

    //Interaction avec le joueur jusqu'a ce qu'il n'y ait plus de pieces voisines de même couleur
    do
    {
        leCptSaisiePiece=0;

        //Saisie d'une piece tant que la piece n'existe pas
        do
        {
            if(leCptSaisiePiece>0)
                std::cout<<"Erreur, cette piece n'existe pas !\n";
            selectionPiece(lesIndex);
            leCptSaisiePiece++;
        }while(!desJetons[lesIndex[0]][lesIndex[1]].sonExistence);

        //Si la piece saisie a des voisins, il faut l'enlever et faire descendre les autres pieces
        if(desJetons[lesIndex[0]][lesIndex[1]].sesVoisins)
            decalagePieces(desJetons, lesIndex);

        //Effacer l'affichage de la console
        system("cls");

        affichagePlateau(desJetons);
    }while(aDesVoisins(desJetons));

    std::cout<<"Fin de la partie !\n";
}
