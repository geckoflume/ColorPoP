/**
 * \file interaction.cpp
 * \brief Gestion de l'interaction du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "affichage.h"
#include "constantes.h"
#include "conversion.h"
#include "interaction.h"
#include "modification.h"
#include "structures.h"

void initialisationJoueurs(Joueur desJoueurs[2])
{
    //Initialisation de rand, il n'a pas ete forcement initialise si on a charge un plateau depuis un fichier
    srand(time(NULL));

    couleurConsole(BLANC);

    unsigned int leCptSaisiePiece(0);
    unsigned int laCouleurAlea(0);

    for(unsigned int leI(0); leI<2; leI++)
    {
        leCptSaisiePiece=0;

        do
        {
            if(leCptSaisiePiece>0)
                std::cout<<"Erreur, le nom saisi est invalide !\n";
            std::cout<<"Joueur "<<leI+1<<", quel est votre nom : ";
            std::getline(std::cin, desJoueurs[leI].sonNom);
            leCptSaisiePiece++;
        }while(desJoueurs[leI].sonNom.size()==0);

        do
        {
            laCouleurAlea=rand()%5;
            desJoueurs[leI].saCouleur=codageCouleurs(laCouleurAlea);
        }while(desJoueurs[leI].saCouleur==desJoueurs[leI-1].saCouleur && leI>0);

        //Initialisation du tableau de joueurs
        desJoueurs[leI].sesJetons=0;
        desJoueurs[leI].sesJetonsBlancs=0;
        desJoueurs[leI].sesJetonsRestants=0;
        desJoueurs[leI].aGagne=false;

        std::cout<<"Bienvenue "<<desJoueurs[leI].sonNom<<", votre couleur est le ";
        couleurConsole(desJoueurs[leI].saCouleur);
        std::cout<<conversionCouleursStrings(desJoueurs[leI].saCouleur)<<std::endl;
        couleurConsole(BLANC);
        std::cout<<"Vous devez vous en souvenir et ne pas la communiquer a votre adversaire."<<std::endl;
        system("pause");
        system("cls");
    }
}


void selectionPiece(Piece & unePiece)
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
        unePiece.saLigne=laSaisie-'a';
    else
        unePiece.saLigne=laSaisie-'A';

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
    unePiece.saColonne=laSaisie-'0';
}


bool selectionPiece(Piece & unePiece, Piece & uneSecondePiece, Joueur desJoueurs[2], unsigned int unJoueur, Emplacement desJetons[DIM][DIM])
{
    std::string laSaisie;

    std::cout<<desJoueurs[unJoueur].sonNom<<" : saisir coordonnee d'une piece non isolee ? ";
    std::getline(std::cin, laSaisie);
    enMajuscules(laSaisie);

    bool saisieValide=false;
    bool leRetour=false;

    if(laSaisie.size()==2 || laSaisie.size()==4) //Si la saisie est de 2 ou de 4 caracteres
    {
        if(laSaisie[0]>='A' && laSaisie[0]<='Z' && laSaisie[1]>='0' && laSaisie[1]<='9')
        {
            unePiece.saLigne=laSaisie[0]-'A';
            unePiece.saColonne=laSaisie[1]-'0';
            saisieValide=true;
        }
        else if(laSaisie[0]>='0' && laSaisie[0]<='9' && laSaisie[1]>='A' && laSaisie[1]<='Z')
        {
            unePiece.saLigne=laSaisie[1]-'A';
            unePiece.saColonne=laSaisie[0]-'0';
            saisieValide=true;
        }

        if(laSaisie.size()==2 && saisieValide && desJetons[unePiece.saLigne][unePiece.saColonne].sonExistence)
        {
            aDesVoisins(desJetons);
            leRetour=desJetons[unePiece.saLigne][unePiece.saColonne].aDesVoisins;
        }

        if(laSaisie.size()==4 && saisieValide && desJetons[unePiece.saLigne][unePiece.saColonne].sonExistence)
        {
            if(laSaisie[2]>='A' && laSaisie[2]<='Z' && laSaisie[3]>='0' && laSaisie[3]<='9')
            {
                uneSecondePiece.saLigne=laSaisie[2]-'A';
                uneSecondePiece.saColonne=laSaisie[3]-'0';
            }
            else if(laSaisie[2]>='0' && laSaisie[2]<='9' && laSaisie[3]>='A' && laSaisie[3]<='Z')
            {
                uneSecondePiece.saLigne=laSaisie[3]-'A';
                uneSecondePiece.saColonne=laSaisie[2]-'0';
            }

            //Si la premiere piece est blanche et que la deuxieme ne l'est pas, et que la deuxieme est une voisine
            leRetour = (desJetons[unePiece.saLigne][unePiece.saColonne].saCouleur==BLANC
                    && desJetons[uneSecondePiece.saLigne][uneSecondePiece.saColonne].saCouleur!=BLANC
                    && ((unePiece.saLigne==uneSecondePiece.saLigne+1 && unePiece.saColonne==uneSecondePiece.saColonne)
                        || (unePiece.saLigne==uneSecondePiece.saLigne-1 && unePiece.saColonne==uneSecondePiece.saColonne)
                        || (unePiece.saColonne==uneSecondePiece.saColonne+1 && unePiece.saLigne==uneSecondePiece.saLigne)
                        || (unePiece.saColonne==uneSecondePiece.saColonne-1 && unePiece.saLigne==uneSecondePiece.saLigne)
                        ))
                    //Si la deuxieme piece est blanche et que la premiere ne l'est pas, et que la premiere est une voisine
                    || (desJetons[uneSecondePiece.saLigne][uneSecondePiece.saColonne].saCouleur==BLANC
                    && desJetons[unePiece.saLigne][unePiece.saColonne].saCouleur!=BLANC
                    && ((uneSecondePiece.saLigne==unePiece.saLigne+1 && uneSecondePiece.saColonne==unePiece.saColonne)
                        || (uneSecondePiece.saLigne==unePiece.saLigne-1 && uneSecondePiece.saColonne==unePiece.saColonne)
                        || (uneSecondePiece.saColonne==unePiece.saColonne+1 && uneSecondePiece.saLigne==unePiece.saLigne)
                        || (uneSecondePiece.saColonne==unePiece.saColonne-1 && uneSecondePiece.saLigne==unePiece.saLigne)
                        ));
        }
    }

    return leRetour;
}


int detectionFinPartie(Emplacement desJetons[DIM][DIM], Joueur desJoueurs[2])
{
    int lEtatJoueur=-1;
    int leRetour=NON_FINI;

    for(unsigned int leJoueur(0); leJoueur<2; leJoueur++)
    {
        lEtatJoueur=-1;

        for(unsigned int leI(0); leI<DIM; leI++)
        {
            for(unsigned int leJ(0); leJ<DIM; leJ++)
            {
                if(desJetons[leI][leJ].saCouleur==desJoueurs[leJoueur].saCouleur)
                {
                    lEtatJoueur=0;
                    desJoueurs[leJoueur].sesJetonsRestants++;
                }
            }
        }
        if(lEtatJoueur==-1)
        {
            leRetour=leJoueur;
            desJoueurs[leJoueur].aGagne=true;
        }
    }

    if (leRetour<0 && !aDesVoisins(desJetons))
        leRetour=ISOLE;

    return leRetour;
}


void interactionUnJoueur(Emplacement desJetons[DIM][DIM])
{
    Piece laPiece;
    unsigned int leCptSaisiePiece(0);

    //Initialisation du champ aDesVoisins pour chaque jeton
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
            selectionPiece(laPiece);
            leCptSaisiePiece++;
        }while(!desJetons[laPiece.saLigne][laPiece.saColonne].sonExistence);

        //Si la piece saisie a des voisins, il faut l'enlever et faire descendre les autres pieces
        if(desJetons[laPiece.saLigne][laPiece.saColonne].aDesVoisins)
            decalagePiecesVertical(desJetons, laPiece);

        //Effacer l'affichage de la console
        system("cls");

        affichage(desJetons);
    }while(aDesVoisins(desJetons));

    std::cout<<"Fin de la partie !\n";
}


void interactionUnJoueurSequences(Emplacement desJetons[DIM][DIM])
{
    Piece laPiece;
    unsigned int leCptSaisiePiece(0);
    std::string laSaisie;
    bool lErreur(false);

    //Initialisation du champ aDesVoisins pour chaque jeton
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
        }while(laSaisie.size()%2!=0 || laSaisie.size()==0);

        //Prolongement Etape 5, conversion en majuscules de la saisie pour gerer les reperes de ligne saisis en minuscules
        enMajuscules(laSaisie);

        //Si la piece saisie a des voisins, il faut l'enlever et faire descendre les autres pieces
        for(unsigned int leI=0; leI<laSaisie.size() && !lErreur; leI+=2)
        {
            //Prolongement Etape 5, pour gerer l'ordre des reperes : si le premier repere entre est la ligne et si le deuxieme repere est la colonne
            if(laSaisie[leI]>='A' && laSaisie[leI]<='Z' && laSaisie[leI+1]>='0' && laSaisie[leI+1]<='9')
            {
                laPiece.saLigne=laSaisie[leI]-'A';
                laPiece.saColonne=laSaisie[leI+1]-'0';
            }
            //Prolongement Etape 5, pour gerer l'ordre des reperes : si le premier repere entre est la colonne et si le deuxieme repere est la ligne
            else if(laSaisie[leI]>='0' && laSaisie[leI]<='9' && laSaisie[leI+1]>='A' && laSaisie[leI+1]<='Z')
            {
                laPiece.saLigne=laSaisie[leI+1]-'A';
                laPiece.saColonne=laSaisie[leI]-'0';
            }
            //Si on est dans aucun des cas au dessus, et que les reperes saisis ne sont ni des lettres ni des chiffres
            else
            {
                std::cout<<"Erreur, la sequence saisie est invalide !\n";
                lErreur=true;
            }
            if(desJetons[laPiece.saLigne][laPiece.saColonne].aDesVoisins && !lErreur)
                decalagePiecesVertical(desJetons, laPiece);
        }

        //Effacer l'affichage de la console
        system("cls");

        affichage(desJetons);
    }while(aDesVoisins(desJetons) && !lErreur);

    std::cout<<"Fin de la partie !\n";
}


void interactionDeuxJoueurs(Emplacement desJetons[DIM][DIM], Joueur desJoueurs[2])
{
    Piece laPiece;
    Piece laSecondePiece;
    unsigned int leJoueur=0;

    int leNombreGagnants=detectionFinPartie(desJetons, desJoueurs);

    while(leNombreGagnants==NON_FINI)
    {
        leJoueur=0;

        for(; leJoueur<2; leJoueur++)
        {
            leNombreGagnants=detectionFinPartie(desJetons, desJoueurs);
            system("cls");
            affichage(desJetons);
            laSecondePiece.saLigne=DIM+1;
            laSecondePiece.saColonne=DIM+1;

            if(leNombreGagnants!=NON_FINI || selectionPiece(laPiece, laSecondePiece, desJoueurs, leJoueur, desJetons))
            {
                if(desJetons[laPiece.saLigne][laPiece.saColonne].saCouleur==BLANC
                        || (laSecondePiece.saLigne<DIM
                            && laSecondePiece.saColonne<DIM
                            && desJetons[laSecondePiece.saLigne][laSecondePiece.saColonne].sonExistence
                            && desJetons[laSecondePiece.saLigne][laSecondePiece.saColonne].saCouleur==BLANC))
                    suppressionVoisins(desJetons, laSecondePiece, desJoueurs, leJoueur);

                suppressionVoisins(desJetons, laPiece, desJoueurs, leJoueur);

                decalagePiecesVertical(desJetons);
                estDecalable(desJetons);
                if(aSaColonneVide(desJetons))
                    decalagePiecesHorizontal(desJetons);
            }
        }
    }
    std::cout<<"Fin de la partie !"<<std::endl;


    unsigned int leMoinsDePiecesRestantes=DIM+1;
    unsigned int leMoinsDePieces=DIM+1;
    unsigned int leMoinsDePiecesBlanches=DIM+1;
    unsigned int leGagnant=0;
    bool lEgalite=false;


    switch (leNombreGagnants)
    {
    case ISOLE:
        std::cout<<"Il ne reste que des pieces isolees."<<std::endl;

        //Selection du joueur ayant le moins de pieces de sa couleur restantes
        for(unsigned int leI(0); leI<2; leI++)
        {
            if(desJoueurs[leI].sesJetonsRestants<leMoinsDePiecesRestantes)
            {
                leMoinsDePiecesRestantes=desJoueurs[leI].sesJetonsRestants;
                leGagnant=leI;
            }
            else if(desJoueurs[leI].sesJetonsRestants==leMoinsDePiecesRestantes)
            {
                lEgalite=true;
                desJoueurs[leI].aGagne=true;
            }
        }

        //Dans le cas ou il y a egalite, selection du joueur ayant retire le moins de pieces
        if(lEgalite)
        {
            lEgalite=false;
            for(unsigned int leI(0); leI<2; leI++)
            {
                if(desJoueurs[leI].aGagne && desJoueurs[leI].sesJetons<leMoinsDePieces)
                {
                    leMoinsDePieces=desJoueurs[leI].sesJetons;
                    leGagnant=leI;
                }
                else if(desJoueurs[leI].aGagne && desJoueurs[leI].sesJetons==leMoinsDePieces)
                    lEgalite=true;
                else
                    desJoueurs[leI].aGagne=false;
            }
        }

        //Dans le cas ou il y a egalite, selection du joueur ayant retire le moins de pieces blanches
        if(lEgalite)
        {
            lEgalite=false;
            for(unsigned int leI(0); leI<2; leI++)
            {
                if(desJoueurs[leI].aGagne && desJoueurs[leI].sesJetonsBlancs<leMoinsDePiecesBlanches)
                {
                    leMoinsDePiecesBlanches=desJoueurs[leI].sesJetonsBlancs;
                    leGagnant=leI;
                }
                else if(desJoueurs[leI].aGagne && desJoueurs[leI].sesJetonsBlancs==leMoinsDePiecesBlanches)
                    lEgalite=true;
                else
                    desJoueurs[leI].aGagne=false;
            }
        }

        //Dans le cas ou il y a egalite parfaite
        if(lEgalite)
        {
            std::cout<<"Il y a egalite parfaite entre ";
            for(unsigned int leI(0); leI<2; leI++)
            {
                if(desJoueurs[leI].aGagne)
                {
                    std::cout<<desJoueurs[leI].sonNom<<' ';
                }
            }
        }
        else
        {
            desJoueurs[leGagnant].aGagne=true;
            std::cout<<"Le gagnant est "<<desJoueurs[leGagnant].sonNom<<" !"<<std::endl;
        }

        break;
    default:
        std::cout<<desJoueurs[leNombreGagnants].sonNom<<" a gagne !"<<std::endl;
    }
}


void menu(Emplacement desJetons[DIM][DIM])
{
    int leChoix(0);

    //Affiche le menu et demande a l'utilisateur de saisir un choix tant que leChoix ne correspond pas a une saisie valide
    do
    {
        system("cls");
        afficherMenu();
        std::cout<<"Choix : ";

        //Si la saisie est valide, ignorer le prochain caractere pour eviter que la saisie soit prise pour l'initialisation des joueurs
        if(std::cin>>leChoix)
            std::cin.ignore();
        //Si la saisie est invalide, reinitialiser le flag d'etat de cin et ignore le reste de la saisie
        else
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }while(leChoix!=1 && leChoix!=2);

    switch (leChoix)
    {
    case 1:
        //Generation, initialisation du plateau
        generation(desJetons);
        break;
    case 2:
        //Verification du nombre de termes du fichier, initialisation du plateau et affichage
        if(!init(desJetons, "save.txt"))
            std::cout<<"Erreur, le nombre de termes du fichier ne correspond pas a la taille du plateau !\n";
        break;
    default:
        std::cout<<"Erreur";
    }
    system("cls");
}
