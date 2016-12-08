/**
 * \file generation.h
 * \brief Declaration des fonctions de generation du TP ColorPoP
 * \author Florian MORNET
 * \version 0.1
 * \date 06 decembre 2016
 */
#include <string>
#include "constantes.h"

#ifndef GENERATION_H
#define GENERATION_H

/**
 * \struct Emplacement
 * \brief Structure d'emplacement pour chaque jeton
 */
struct Emplacement{
    /**
     * \var bool sonExistence
     * \brief Si le pion existe
     */
    bool sonExistence;

    /**
     * \var unsigned int saCouleur
     * \brief Couleur du pion
     */
    unsigned int saCouleur;

    /**
     * \var bool aDesVoisins
     * \brief Si le pion a des voisins
     */
    bool aDesVoisins;
};

/**
 * \brief Verification que les pieces ont des voisins
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Un bool, true si il reste des voisins, false s'il n'en reste pas
 */
bool aDesVoisins(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Initialisation du tableau de jetons
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void initialisationPlateau(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Genereration d'un nombre aleatoire respectant la loi de probabilite
 * \param[in] uneLoi double correspondant a la loi de probabilite
 * \return Un unsigned int correspondant a un nombre aleatoire
 */
unsigned int generationNbAleaLoi(double uneLoi[]);

/**
 * \brief Genereration de la loi de probabilite
 * \param[in] totalPionsAPlacer double correspondant au nombre de pions a placer
 * \param[out] loi double correspondant a la loi de probabilite
 * \param[in] nbPionsAPlacer unsigned int correspondant au nombre de pions restants a placer pour chaque couleur
 * \return Void
 */
void generationLoi(double totalPionsAPlacer, double loi[NB_COULEURS], unsigned int nbPionsAPlacer[]);

/**
 * \brief Codage du nombre genere en couleur pour l'afficher dans le terminal
 * \param[in] unPion unsigned int correspondant au pion aleatoire
 * \return Un unsigned int correspondant a la couleur codee pour s'afficher dans le terminal
 */
unsigned int codageCouleurs(unsigned int unPion);

/**
 * \brief Generation des couleurs et peuplement du tableau de jetons
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void generationJetons(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Conversion en majuscules d'un string
 * \param[in] unMot string correspondant a un mot
 * \return Un string correspondant au mot en majuscules
 */
std::string enMajuscules(std::string unMot);

/**
 * \brief Conversion des strings en couleurs de l'enum Couleurs
 * \param[in] uneCouleur string correspondant a une couleur
 * \return Un unsigned int correspondant a la couleur de l'enum Couleurs
 */
unsigned int conversionStringsCouleur(std::string uneCouleur);

/**
 * \brief Initialisation du plateau a partir d'un fichier
 * \param[out] unPlateau Emplacement correspondant au plateau de jetons
 * \param[in] unNomFichier string correspondant au nom du fichier a importer
 * \return Un bool, true si le fichier comporte le bon nombre de termes, false sinon
 */
bool init(Emplacement unPlateau[DIM][DIM], std::string unNomFichier);

#endif // GENERATION_H
