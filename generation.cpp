#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include "generation.h"
#include "constantes.h"

/* On definit une loi de probabilite de 19/100 pour toutes les couleurs sauf le blanc
   qui a une probabilite de 5/100. On va ensuite tester dans quel intervalle se
   situe le nombre aleatoire genere, selon les intervalles suivants :

   [0;18]=BLEU
   [19;37]=VERT
   [38;56]=ROUGE
   [57;75]=MAGENTA
   [76;94]=JAUNE
   [95;99]=BLANC
*/

void initialisationPlateau(Emplacement desJetons[DIM][DIM])
{
    for(unsigned int leI=0; leI<DIM; leI++){
        for(unsigned int leJ=0; leJ<DIM; leJ++){
            desJetons[leI][leJ].sonExistence=true;
            desJetons[leI][leJ].saCouleur=NOIR;
            desJetons[leI][leJ].sesVoisins=false;
        }
    }
}


unsigned int generationNbAleaLoi(double uneLoi[])
{
    //Generation d'un nombre compris entre 0 et 99
    unsigned int leAlea=rand()%100;

    unsigned int leI=0;
    double laSomme=0;

    /* Dans le premier passage dans la boucle, on teste si leAlea
       est inferieur a laSomme, c'est a dire a uneLoi[0]. Si ce n'est pas le cas
       on relance la boucle : laSomme vaudra uneLoi[0] + uneLoi[1].
    */
    do{
        laSomme = laSomme+uneLoi[leI];
        leI++;
    }while(laSomme < leAlea && leI < NB_COULEURS);

    return leI-1;                   //Pour obtenir un nombre compris entre 0 et 5
}


void generationLoi(double totalPionsAPlacer, double loi[], unsigned int nbPionsAPlacer[])
{
    for(unsigned int leI=0; leI<NB_COULEURS; leI++)
    {
        loi[leI]=(nbPionsAPlacer[leI]/totalPionsAPlacer)*100;
    }
}


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


void generationJetons(Emplacement desJetons[DIM][DIM])
{
    //Initialisation de rand
    srand(time(NULL));

    //Nombre de pions a placer pour chaque couleur
    unsigned int nbPionsAPlacer[NB_COULEURS]={19,19,19,19,19,5};

    unsigned int totalPionsAPlacer=DIM*DIM;
    unsigned int lePion=0;

    //Generation de la loi de probabilite initiale (laLoi[])
    double laLoi[NB_COULEURS]={0};
    generationLoi(totalPionsAPlacer, laLoi, nbPionsAPlacer);

    /* Generation des nombres aleatoires et peuplement du tableau
       en decrementant le nombre de pions total a placer et le nombre
       de pions de chaque couleur a placer. A chaque passage dans la
       boucle, on met a jour le tableau de loi de probabilite de maniere
       a obtenir un tirage sans remise.
     */
    for(unsigned int leI=0; leI<DIM; leI++)
    {
        for(unsigned int leJ=0; leJ<DIM; leJ++)
        {
            lePion=generationNbAleaLoi(laLoi);
            nbPionsAPlacer[lePion]--;
            totalPionsAPlacer--;
            generationLoi(totalPionsAPlacer, laLoi, nbPionsAPlacer);
            desJetons[leI][leJ].saCouleur=codageCouleurs(lePion);
        }
    }
}


std::string enMajuscules(std::string unMot){
    std::string leMot;
    unsigned int leI(0);
    while(unMot[leI]){
        //Si la lettre est en minuscule, la remplacer par la majuscule correspondante
        if(unMot[leI]>='a'&&unMot[leI]<='z'){
            leMot+=unMot[leI]-' ';
        }
        //Si la lettre est en majuscule
        else if(unMot[leI]>='A'&&unMot[leI]<='Z'){
            leMot+=unMot[leI];
        }
        leI++;
    }

    return leMot;
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


bool init(Emplacement unPlateau[DIM][DIM], std::string unNomFichier)
{
    std::ifstream leFichierSave(unNomFichier);
    std::string laCouleur;
    std::string laCouleurMaj;
    unsigned int laCouleurConvertie(0);
    unsigned int leNombreTermes(0);

    for(unsigned int leI=0; leI<DIM; leI++)
    {
        for(unsigned int leJ=0; leJ<DIM; leJ++)
        {
            //Prolongement Etape 3, comptage des termes et verification que le fichier existe
            if(!leFichierSave.eof()&&!leFichierSave.fail())
                leNombreTermes++;

            leFichierSave>>laCouleur;
            leFichierSave.ignore();

            //Prolongement Etape 3, conversion des termes du fichier en majuscules
            laCouleurMaj=enMajuscules(laCouleur);

            //Prolongement Etape 3, conversion des termes du fichier en majuscules
            laCouleurMaj=enMajuscules(laCouleur);

            laCouleurConvertie=conversionStringsCouleur(laCouleurMaj);
            unPlateau[leI][leJ].saCouleur=laCouleurConvertie;
            if(laCouleurConvertie==NOIR)
                unPlateau[leI][leJ].sonExistence=false;
        }
    }

    //Prolongement Etape 3, verification du nombre de termes
    return leNombreTermes==DIM*DIM;
}


bool aDesVoisins(Emplacement desJetons[DIM][DIM])
{
    unsigned int leNombreVoisins(0);

    for(unsigned int leI(0); leI<DIM; leI++)
    {
        for(unsigned int leJ(0); leJ<DIM; leJ++)
        {
            if(desJetons[leI][leJ].sonExistence &&                                                  //Si le jeton existe
                    ((desJetons[leI][leJ].saCouleur==desJetons[leI+1][leJ].saCouleur && leI<DIM)    //Si le jeton en dessous est identique et que l'on ne se situe pas sur une bordure basse
                     || (desJetons[leI][leJ].saCouleur==desJetons[leI][leJ-1].saCouleur && leJ>0)   //Si le jeton a gauche est identique et que l'on ne se situe pas sur une bordure gauche
                     || (desJetons[leI][leJ].saCouleur==desJetons[leI-1][leJ].saCouleur && leI>0)   //Si le jeton au dessus est identique et que l'on ne se situe pas sur une bordure haute
                     || (desJetons[leI][leJ].saCouleur==desJetons[leI][leJ+1].saCouleur && leJ<DIM) //Si le jeton a droite est identique et que l'on ne se situe pas sur une bordure droite
                     || desJetons[leI][leJ].saCouleur==BLANC))
            {
                desJetons[leI][leJ].sesVoisins=true;
                leNombreVoisins++;
            }
        }
    }

    return leNombreVoisins>0;
}
