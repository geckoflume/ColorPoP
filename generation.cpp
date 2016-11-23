#include <time.h>
#include <iostream>
#include "generation.h"
#include "constantes.h"
#include "affichage.h"

/* On definit une loi de probabilite de 19/100 pour toutes les couleurs sauf le blanc
   qui a une probabilite de 5/100. On va ensuite tester dans quel intervalle se
   situe le nombre aleatoire genere, selon le schema suivant :

   |0.00-0.19|0.19-0.38|0.38-0.57|0.57-0.73|0.73-0.95|0.95-1.00|
       Bleu      Vert     Rouge    Magenta    Jaune     Blanc
 */

unsigned int generationNbAleaLoi(double uneLoi[])
{
    //Generation d'un nombre compris entre 0 et 1
    double leAlea=((double)rand()/(double)RAND_MAX);

    unsigned int leI=0;
    double laSomme=0;

    /* Dans le premier passage dans la boucle, on teste si leAlea
       est inférieur à laSomme, c'est à dire uneLoi[0]. Si ce n'est pas le cas
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
        loi[leI]=nbPionsAPlacer[leI]/totalPionsAPlacer;
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


void generationCouleurPeuplementJetons(unsigned int desJetons[][DIM])
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
            desJetons[leI][leJ]=codageCouleurs(lePion);
        }
    }
}
