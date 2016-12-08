/**
 * \file interaction.cpp
 * \brief Gestion de l'interaction du TP ColorPoP
 * \author Florian MORNET
 * \version 0.1
 * \date 06 decembre 2016
 */
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
        if(desJetons[lesIndex[0]][lesIndex[1]].aDesVoisins)
            decalagePieces(desJetons, lesIndex);

        //Effacer l'affichage de la console
        system("cls");

        affichagePlateau(desJetons);
    }while(aDesVoisins(desJetons));

    std::cout<<"Fin de la partie !\n";
}


void interactionUnJoueurSequences(Emplacement desJetons[DIM][DIM])
{
    unsigned int lesIndex[2];
    unsigned int leCptSaisiePiece(0);
    std::string laSaisie;
    bool lErreur(false);

    //Initialisation du champ sesVoisins pour chaque jeton
    aDesVoisins(desJetons);

    //Interaction avec le joueur jusqu'a ce qu'il n'y ait plus de pieces voisines de même couleur
    do
    {
        leCptSaisiePiece=0;

        //Saisie d'une piece tant que la sequence ne contient pas un nombre pair de caracteres
        do
        {
            if(leCptSaisiePiece>0)
                std::cout<<"Erreur, la sequence saisie est invalide !\n";
            std::cout<<"Saisir une sequence de selection : ";
            std::getline(std::cin, laSaisie);
            leCptSaisiePiece++;
        }while(laSaisie.size()%2!=0 && laSaisie.size()>0);

        //Prolongement Etape 5, conversion en majuscules de la saisie pour gerer les reperes de ligne saisis en minuscules
        laSaisie=enMajuscules(laSaisie);

        //Si la piece saisie a des voisins, il faut l'enlever et faire descendre les autres pieces
        for(unsigned int leI=0; leI<laSaisie.size() && !lErreur; leI+=2)
        {
            //Prolongement Etape 5, pour gerer l'ordre des reperes : si le premier repere entre est la ligne et si le deuxieme repere est la colonne
            if(laSaisie[leI]>='A' && laSaisie[leI]<='Z' && laSaisie[leI+1]>='0' && laSaisie[leI+1]<='9')
            {
                lesIndex[0]=laSaisie[leI]-'A';
                lesIndex[1]=laSaisie[leI+1]-'0';
            }
            //Prolongement Etape 5, pour gerer l'ordre des reperes : si le premier repere entre est la colonne et si le deuxieme repere est la ligne
            else if(laSaisie[leI]>='0' && laSaisie[leI]<='9' && laSaisie[leI+1]>='A' && laSaisie[leI+1]<='Z')
            {
                lesIndex[0]=laSaisie[leI+1]-'A';
                lesIndex[1]=laSaisie[leI]-'0';
            }
            //Si on est dans aucun des cas au dessus, et que les reperes saisis ne sont ni des lettres ni des chiffres
            else
            {
                std::cout<<"Erreur, la sequence saisie est invalide !\n";
                lErreur=true;
            }
            if(desJetons[lesIndex[0]][lesIndex[1]].aDesVoisins && !lErreur)
                decalagePieces(desJetons, lesIndex);
        }

        //Effacer l'affichage de la console
        system("cls");

        affichagePlateau(desJetons);
    }while(aDesVoisins(desJetons) && !lErreur);

    std::cout<<"Fin de la partie !\n";
}
