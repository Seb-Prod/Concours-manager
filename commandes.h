#ifndef COMMANDES_H
#define COMMANDES_H

/**
 * \file commandes.h
 * \brief Gestion et analyse des commandes utilisateur (déclarations et types).
 */

/**
 * \brief Énumération des différents types de commandes supportées par l'application.
 */
typedef enum
{
    CMD_INCONNUE = 0,   ///< Commande non reconnue ou invalide
    CMD_EXIT,           ///< Quitter l'application
    CMD_INSCRIRE,       ///< Inscrire un participant
    CMD_CREER,          ///< Créer un concours
    CMD_PARTICIPANTS,   ///< Lister les participants
    CMD_CONCOURS,       ///< Lister les concours
    CMD_GAIN,           ///< Saisir les gains/scores d'un concours
    CMD_SCORES,         ///< Afficher les scores
    CMD_CLASSEMENT,     ///< Afficher le classement d'un concours
    CMD_COMPARAISON,    ///< Comparer deux concours
    CMD_BILAN,          ///< Afficher le bilan avec l'évolution des places
    CMD_AIDE            ///< Afficher le menu d'aide
} CommandeType;

/**
 * \brief Structure représentant le résultat de l'analyse d'une ligne saisie.
 */
typedef struct
{
    CommandeType type;   ///< Identifiant numérique de la commande
    char *nom;           ///< Premier mot saisi (ex : "INSCRIRE")
    char *arguments;     ///< Reste de la ligne, NULL s'il n'y en a pas
} CommandeAnalysee;

/**
 * \brief Analyse une ligne de saisie brute pour en extraire la commande et ses arguments.
 * \details Sépare la ligne en mots (via strtok), identifie le type de commande associé 
 *          et remplit la structure `CommandeAnalysee`.
 * 
 * \param ligne_saisie Chaîne de caractères représentant la ligne saisie (attention : elle est modifiée par la fonction).
 * \param commande Pointeur vers la structure `CommandeAnalysee` à remplir (non NULL).
 * \return 1 si la ligne contient une commande valide/analysée, 0 si la ligne est vide ou ne contient que des espaces.
 * 
 * \pre commande != NULL
 */
int analyser_saisie(char *ligne_saisie, CommandeAnalysee *commande);

#endif