/**
 * \file conversion.cpp
 * \brief Gestion des conversions/codages du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include <string>
#include "constantes.h"
#include "conversion.h"

unsigned int codageCouleurs(unsigned int unPion)
{
    unsigned int lePionCode=0;
    switch (unPion) {
    case 0:                     //Couleur bleue
    case 1:                     //Couleur verte
        lePionCode=unPion+9;
        break;
    default:                    //Couleurs rouge, magenta, jaune, blanc
        lePionCode=unPion+10;
        break;
    }

    return lePionCode;
}


void enMajuscules(std::string & unMot){
    std::string leMot;
    unsigned int leI(0);
    while(unMot[leI]){
        //Si la lettre est en minuscule, la remplacer par la majuscule correspondante
        if(unMot[leI]>='a'&&unMot[leI]<='z'){
            leMot+=unMot[leI]+'A'-'a';
        }
        //Si la lettre est en majuscule ou s'il s'agit d'un autre caractere
        else{
            leMot+=unMot[leI];
        }
        leI++;
    }

    unMot=leMot;
}


unsigned int conversionStringsCouleur(std::string uneCouleur)
{
    unsigned int laCouleurConvertie(0);
    if(uneCouleur=="BLEU")
        laCouleurConvertie=BLEU;
    else if(uneCouleur=="VERT")
        laCouleurConvertie=VERT;
    else if(uneCouleur=="ROUGE")
        laCouleurConvertie=ROUGE;
    else if(uneCouleur=="MAGENTA")
        laCouleurConvertie=MAGENTA;
    else if(uneCouleur=="JAUNE")
        laCouleurConvertie=JAUNE;
    else if(uneCouleur== "BLANC")
        laCouleurConvertie=BLANC;
    else{                //Dans le cas ou il s'agit d'un autre terme (VIDE, NOIR...)
        laCouleurConvertie=NOIR;
    }

    return laCouleurConvertie;
}


std::string conversionCouleursStrings(Couleur uneCouleur)
{
    std::string laCouleurConvertie;
    switch (uneCouleur) {
    case NOIR:
        laCouleurConvertie="NOIR";
        break;
    case BLEU:
        laCouleurConvertie="BLEU";
        break;
    case VERT:
        laCouleurConvertie="VERT";
        break;
    case ROUGE:
        laCouleurConvertie="ROUGE";
        break;
    case MAGENTA:
        laCouleurConvertie="MAGENTA";
        break;
    case JAUNE:
        laCouleurConvertie="JAUNE";
        break;
    case BLANC:
        laCouleurConvertie="BLANC";
        break;
    default:
        laCouleurConvertie="ERREUR";
        break;
    }

    return laCouleurConvertie;
}

std::string conversionCouleursStrings(unsigned int uneCouleur)
{
    std::string laCouleurConvertie;
    switch (uneCouleur) {
    case NOIR:
        laCouleurConvertie="NOIR";
        break;
    case BLEU:
        laCouleurConvertie="BLEU";
        break;
    case VERT:
        laCouleurConvertie="VERT";
        break;
    case ROUGE:
        laCouleurConvertie="ROUGE";
        break;
    case MAGENTA:
        laCouleurConvertie="MAGENTA";
        break;
    case JAUNE:
        laCouleurConvertie="JAUNE";
        break;
    case BLANC:
        laCouleurConvertie="BLANC";
        break;
    default:
        laCouleurConvertie="ERREUR";
        break;
    }

    return laCouleurConvertie;
}
