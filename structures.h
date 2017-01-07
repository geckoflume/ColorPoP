/**
 * \file structures.h
 * \brief Declaration des structures du TP ColorPoP
 * \author Florian MORNET
 * \version 0.3
 * \date 04 janvier 2017
 */
#include <string>

#ifndef STRUCTURES_H
#define STRUCTURES_H

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

    /**
     * \var bool estDecalable
     * \brief Si le pion est decalable
     */
    bool estDecalable;

    /**
     * \var unsigned int sonNombreVidesEnHaut
     * \brief Le nombre de cases vides sur le haut du plateau, apres la derniere piece
     */
    unsigned int sonNombreVidesEnHaut;

    /**
     * \var bool aSaColonneVide
     * \brief Si la colonne est vide
     */
    bool aSaColonneVide;

    /**
     * \var bool aSaColonneDecalable
     * \brief Si la colonne est decalable
     */
    bool aSaColonneDecalable;
};

/**
 * \struct Joueur
 * \brief Structure d'emplacement pour chaque joueur
 */
struct Joueur{
    /**
     * \var bool sonNom
     * \brief Le nom du joueur
     */
    std::string sonNom;

    /**
     * \var unsigned int saCouleur
     * \brief Couleur du joueur
     */
    unsigned int saCouleur;

    /**
     * \var unsigned int sesJetons
     * \brief Nombre de jetons que le joueur a enlevé
     */
    unsigned int sesJetons;

    /**
     * \var unsigned int sesJetonsBlancs
     * \brief Nombre de jetons blancs que le joueur a enlevé
     */
    unsigned int sesJetonsBlancs;

    /**
     * \var unsigned int sesJetonsRestants
     * \brief Nombre de jetons de la couleur du joueur qu'il reste a la fin de la partie
     */
    unsigned int sesJetonsRestants;

    /**
     * \var bool aGagne
     * \brief Si le joueur a gagne
     */
    bool aGagne;
};

/**
 * \struct Piece
 * \brief Structure d'emplacement pour chaque piece
 */
struct Piece{
    /**
     * \var unsigned int saLigne
     * \brief La coordonnee de la ligne de la piece
     */
    unsigned int saLigne;

    /**
     * \var unsigned int saColonne
     * \brief La coordonnee de la colonne de la piece
     */
    unsigned int saColonne;
};
#endif // STRUCTURES_H
