/**
 * \file modification.cpp
 * \brief Gestion de la modification du plateau du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include "constantes.h"
#include "modification.h"
#include "structures.h"

bool aDesVoisins(Emplacement desJetons[DIM][DIM])
{
    unsigned int leNombreVoisins(0);

    for(unsigned int leI(0); leI<DIM; leI++)
    {
        for(unsigned int leJ(0); leJ<DIM; leJ++)
        {
            if(desJetons[leI][leJ].sonExistence &&                                                  //Si le jeton existe
                    ((leI<DIM && desJetons[leI][leJ].saCouleur==desJetons[leI+1][leJ].saCouleur)    //Si l'on ne se situe pas sur une bordure basse et que le jeton en dessous est identique
                     || (leJ>0 && desJetons[leI][leJ].saCouleur==desJetons[leI][leJ-1].saCouleur)   //Si l'on ne se situe pas sur une bordure gauche et que le jeton a gauche est identique
                     || (leI>0 && desJetons[leI][leJ].saCouleur==desJetons[leI-1][leJ].saCouleur)   //Si l'on ne se situe pas sur une bordure haute et que le jeton au dessus est identique
                     || (leJ<DIM && desJetons[leI][leJ].saCouleur==desJetons[leI][leJ+1].saCouleur) //Si l'on ne se situe pas sur une bordure droite et que le jeton a droite est identique
                     ))
            {
                desJetons[leI][leJ].aDesVoisins=true;
                leNombreVoisins++;
            }
        }
    }

    return leNombreVoisins>0;
}


bool estDecalable(Emplacement desJetons[DIM][DIM])
{
    unsigned int leCpt(0);
    bool leFlag=false;
    bool leRetour=false;

    for(int leJ(DIM-1); leJ>=0; leJ--)
    {
        leCpt=0;
        leFlag=false;
        for(unsigned int leI(0); leI<DIM; leI++)
        {
            if(!leFlag && desJetons[leI][leJ].saCouleur!=NOIR)
                leFlag=true;
            if(!leFlag)
                leCpt++;
        }
        if(leCpt>0)
        {
            desJetons[0][leJ].sonNombreVidesEnHaut=leCpt;
            desJetons[0][leJ].estDecalable=leCpt<10;
            leRetour=true;
        }
    }

    return leRetour;
}


bool aSaColonneVide(Emplacement desJetons[DIM][DIM])
{
    unsigned int leCptVides(0);
    bool leRetour=false;

    for(int leJ(DIM-1); leJ>=0; leJ--)
    {
        leCptVides=0;
        for(unsigned int leI(0); leI<DIM; leI++)
        {
            if(!desJetons[0][leJ].aSaColonneVide && !desJetons[leI][leJ].sonExistence)
                leCptVides++;
        }
        if(leCptVides==DIM)
            desJetons[0][leJ].aSaColonneVide=true;
        if(leCptVides==DIM && (!desJetons[0][leJ+1].aSaColonneVide || desJetons[0][leJ+1].aSaColonneDecalable) && leJ!=DIM-1)
        {
            leRetour=true;
            desJetons[0][leJ].aSaColonneDecalable=true;
        }
    }

    return leRetour;
}


void decalagePiecesVertical(Emplacement desJetons[DIM][DIM], Piece unePiece)
{
    int leI(unePiece.saLigne);

    for( ; leI>=0&&desJetons[leI][unePiece.saColonne].sonExistence; leI--)
        desJetons[leI][unePiece.saColonne]=desJetons[leI-1][unePiece.saColonne];

    //La piece la plus haute de la colonne est descendue, elle n'existe donc plus
    desJetons[leI+1][unePiece.saColonne].sonExistence=false;
    desJetons[leI+1][unePiece.saColonne].saCouleur=NOIR;
}


void decalagePiecesVertical(Emplacement desJetons[DIM][DIM])
{
    int leCpt(0);
    int leK(0);

    for(unsigned int leI(0); leI<DIM; leI++)
    {
        for(int leJ(DIM-1); leJ>0; leJ--)
        {
            if(!desJetons[leJ][leI].sonExistence)
            {
                leK=leJ;
                leCpt=0;

                //On compte le nombre de cases vides au dessus de la premiere case vide
                while(!desJetons[leK][leI].sonExistence && leK>=0)
                {
                    leK--;
                    leCpt++;
                }

                //On verifie que le nombre de cases vides au dessus de la premiere case vide ne correspond pas a la coordonnee de ligne,
                //ce qui signifierait que l'on se situe en haut de la grille et que rien est a decaler
                if(leCpt-1!=leJ)
                {
                    for(int leK(leJ); leK>=0; leK--)
                        if(leK>0)
                            desJetons[leK][leI]=desJetons[leK-1][leI];

                    //La piece tout en haut de la colonne est descendue, elle n'existe donc plus
                        else
                        {
                            desJetons[leK][leI].sonExistence=false;
                            desJetons[leK][leI].saCouleur=NOIR;
                        }

                    //On recommence la boucle for a partir de la meme ligne si le pion juste au dessus etait non existant
                    if(!desJetons[leJ][leI].sonExistence)
                        leJ++;
                }
            }
        }
    }
}


void decalagePiecesHorizontal(Emplacement desJetons[DIM][DIM])
{
    for(int leJ(DIM-1); leJ>=0; leJ--)
    {
        if(desJetons[0][leJ].aSaColonneDecalable)
        {
            for(unsigned int leK(leJ); leK<DIM-1; leK++)
            {
                for(unsigned int leI(0); leI<DIM; leI++)
                {
                    desJetons[leI][leK]=desJetons[leI][leK+1];
                    if(leK+1==DIM-1 || desJetons[leI][leK+1].saCouleur==NOIR)
                    {
                        desJetons[leI][leK+1].sonExistence=false;
                        desJetons[leI][leK+1].saCouleur=NOIR;
                    }
                }
            }
            desJetons[0][leJ].aSaColonneDecalable=false;
        }
    }
}


void suppressionVoisins(Emplacement desJetons[DIM][DIM], Piece unePiece, Joueur desJoueurs[2], unsigned int unJoueur)
{
    Piece laPieceVoisine;
    unsigned int laCouleurJeton=desJetons[unePiece.saLigne][unePiece.saColonne].saCouleur;
    desJetons[unePiece.saLigne][unePiece.saColonne].saCouleur=NOIR;
    desJetons[unePiece.saLigne][unePiece.saColonne].sonExistence=false;
    desJoueurs[unJoueur].sesJetons++;
    if(laCouleurJeton==BLANC)
        desJoueurs[unJoueur].sesJetonsBlancs++;
    else
    {
        if(unePiece.saLigne+1<DIM && desJetons[unePiece.saLigne+1][unePiece.saColonne].saCouleur==laCouleurJeton) //Si l'on ne se situe pas sur une bordure basse et que le jeton en dessous est identique
        {
            laPieceVoisine.saLigne=unePiece.saLigne+1;
            laPieceVoisine.saColonne=unePiece.saColonne;
            suppressionVoisins(desJetons, laPieceVoisine, desJoueurs, unJoueur);
        }
        if(desJetons[unePiece.saLigne][unePiece.saColonne-1].saCouleur==laCouleurJeton)   //Si le jeton a gauche est identique
        {
            laPieceVoisine.saLigne=unePiece.saLigne;
            laPieceVoisine.saColonne=unePiece.saColonne-1;
            suppressionVoisins(desJetons, laPieceVoisine, desJoueurs, unJoueur);
        }
        if(desJetons[unePiece.saLigne-1][unePiece.saColonne].saCouleur==laCouleurJeton)   //Si le jeton au dessus est identique
        {
            laPieceVoisine.saLigne=unePiece.saLigne-1;
            laPieceVoisine.saColonne=unePiece.saColonne;
            suppressionVoisins(desJetons, laPieceVoisine, desJoueurs, unJoueur);
        }
        if(unePiece.saColonne+1<DIM && desJetons[unePiece.saLigne][unePiece.saColonne+1].saCouleur==laCouleurJeton) //Si l'on ne se situe pas sur une bordure droite et que le jeton a droite est identique
        {
            laPieceVoisine.saLigne=unePiece.saLigne;
            laPieceVoisine.saColonne=unePiece.saColonne+1;
            suppressionVoisins(desJetons, laPieceVoisine, desJoueurs, unJoueur);
        }
    }
}
