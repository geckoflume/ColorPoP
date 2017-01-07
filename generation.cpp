/**
 * \file generation.cpp
 * \brief Gestion de la generation du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include "generation.h"
#include "constantes.h"
#include "conversion.h"
#include "structures.h"

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
            desJetons[leI][leJ].aDesVoisins=false;
            desJetons[leI][leJ].estDecalable=false;
            desJetons[leI][leJ].sonNombreVidesEnHaut=0;
            desJetons[leI][leJ].aSaColonneVide=false;
            desJetons[leI][leJ].aSaColonneDecalable=false;
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


void generationLoi(double totalPionsAPlacer, double loi[NB_COULEURS], unsigned int nbPionsAPlacer[])
{
    for(unsigned int leI=0; leI<NB_COULEURS; leI++)
    {
        loi[leI]=(nbPionsAPlacer[leI]/totalPionsAPlacer)*100;
    }
}


void generation(Emplacement desJetons[DIM][DIM])
{
    //Initialisation de rand
    srand(time(NULL));

    //Initialisation du tableau de jetons
    initialisationPlateau(desJetons);

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


bool init(Emplacement unPlateau[DIM][DIM], std::string unNomFichier)
{
    std::ifstream leFichierSave(unNomFichier);
    std::string laCouleur;
    std::string laCouleurMaj;
    unsigned int laCouleurConvertie(0);
    unsigned int leNombreTermes(0);

    //Initialisation du tableau de jetons
    initialisationPlateau(unPlateau);

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
            enMajuscules(laCouleur);

            laCouleurConvertie=conversionStringsCouleur(laCouleur);
            unPlateau[leI][leJ].saCouleur=laCouleurConvertie;
            if(laCouleurConvertie==NOIR)
                unPlateau[leI][leJ].sonExistence=false;
        }
    }

    //Prolongement Etape 3, verification du nombre de termes
    return leNombreTermes==DIM*DIM;
}
