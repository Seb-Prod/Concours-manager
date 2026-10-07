#ifndef DONNEES_H
#define DONNEES_H

/**
 * \file donnees.h
 * \brief Définition des structures de données principales et des constantes globales de l'application.
 */

/** \brief Nombre maximal de participants gérés par l'application. */
#define MAX_PARTICIPANTS 100

/** \brief Nombre maximal de concours gérés par l'application. */
#define MAX_CONCOURS 20

/** \brief Longueur maximale autorisée pour les noms et prénoms (ainsi que les noms de concours). */
#define MAX_LONGUEUR_NOM 30

/**
 * \brief Représente un participant avec son prénom et son nom.
 */
typedef struct
{
    char prenom[MAX_LONGUEUR_NOM + 1]; ///< Prénom du participant (+1 pour le caractère nul '\0')
    char nom[MAX_LONGUEUR_NOM + 1];    ///< Nom de famille du participant (+1 pour le caractère nul '\0')
} Participant;

/**
 * \brief Représente un concours avec son nom.
 */
typedef struct
{
    char nom[MAX_LONGUEUR_NOM + 1];    ///< Nom du concours (+1 pour le caractère nul '\0')
} Concours;

/**
 * \brief Structure globale contenant tout l'état de l'application.
 */
typedef struct
{
    Participant participants[MAX_PARTICIPANTS];         ///< Tableau stockant les participants inscrits
    int nb_participants;                                ///< Nombre actuel de participants inscrits
    Concours concours[MAX_CONCOURS];                    ///< Tableau stockant les concours créés
    int nb_concours;                                    ///< Nombre actuel de concours créés
    int scores[MAX_PARTICIPANTS][MAX_CONCOURS];         ///< Matrice des scores (0 = aucun gain / score nul)
    int rang_precedent[MAX_CONCOURS][MAX_PARTICIPANTS]; ///< Rangs mémorisés pour l'évolution des places (utilisé par la commande BILAN)
} Application;

#endif