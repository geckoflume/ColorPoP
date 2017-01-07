/**
 * \file generation.h
 * \brief Declaration des fonctions de generation du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include <string>
#include "constantes.h"
#include "structures.h"

#ifndef GENERATION_H
#define GENERATION_H

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
 * \brief Generation des couleurs et peuplement du tableau de jetons
 * \param[in, out] desJetons Emplacement correspondant au plateau de jetons
 * \return Void
 */
void generation(Emplacement desJetons[DIM][DIM]);

/**
 * \brief Initialisation du plateau a partir d'un fichier
 * \param[out] unPlateau Emplacement correspondant au plateau de jetons
 * \param[in] unNomFichier string correspondant au nom du fichier a importer
 * \return Un bool, true si le fichier comporte le bon nombre de termes, false sinon
 */
bool init(Emplacement unPlateau[DIM][DIM], std::string unNomFichier);

#endif // GENERATION_H
