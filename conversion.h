/**
 * \file conversion.h
 * \brief Declaration des fonctions de conversion/codage du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include <string>
#include "constantes.h"
#include "structures.h"

#ifndef CONVERSION_H
#define CONVERSION_H

/**
 * \brief Codage du nombre genere en couleur pour l'afficher dans le terminal
 * \param[in] unPion unsigned int correspondant au pion aleatoire
 * \return Un unsigned int correspondant a la couleur codee pour s'afficher dans le terminal
 */
unsigned int codageCouleurs(unsigned int unPion);

/**
 * \brief Conversion en majuscules d'un string
 * \param[in] unMot string correspondant a un mot
 * \return Void
 */
void enMajuscules(std::string & unMot);

/**
 * \brief Conversion des strings en couleurs de l'enum Couleurs
 * \param[in] uneCouleur string correspondant a une couleur
 * \return Un unsigned int correspondant a la couleur de l'enum Couleurs
 */
unsigned int conversionStringsCouleur(std::string uneCouleur);

/**
 * \brief Conversion des Couleurs en leur string correspondant
 * \param[in] uneCouleur Couleur correspondant a une couleur
 * \return Un string correspondant a la couleur de l'enum Couleurs
 */
std::string conversionCouleursStrings(Couleur uneCouleur);

/**
 * \brief Conversion des entiers de couleur en leur string correspondant
 * \param[in] uneCouleur Entier correspondant a une couleur
 * \return Un string correspondant a la couleur de l'enum Couleurs
 */
std::string conversionCouleursStrings(unsigned int uneCouleur);
#endif // CONVERSION_H
