/**
 * \file commandes.c
 * \brief Implémentation de l'analyse lexicale et syntaxique des commandes utilisateur.
 */

#include <string.h>
#include "commandes.h"
#include "saisie.h"

/**
 * \brief Associe un nom textuel de commande à son type énuméré.
 * \fn static CommandeType identifier_type_commande(const char *nom_commande)
 * 
 * \param nom_commande Chaîne de caractères représentant le nom de la commande saisie.
 * \return Le type de commande correspondant (`CommandeType`), ou `CMD_INCONNUE` si le nom est inconnu.
 */
static CommandeType identifier_type_commande(const char *nom_commande)
{
    if (strcmp(nom_commande, "EXIT") == 0 || strcmp(nom_commande, "exit") == 0)
        return CMD_EXIT;
    if (strcmp(nom_commande, "INSCRIRE") == 0)
        return CMD_INSCRIRE;
    if (strcmp(nom_commande, "PARTICIPANTS") == 0)
        return CMD_PARTICIPANTS;
    if (strcmp(nom_commande, "CREER") == 0)
        return CMD_CREER;
    if (strcmp(nom_commande, "CONCOURS") == 0)
        return CMD_CONCOURS;
    if (strcmp(nom_commande, "GAIN") == 0)
        return CMD_GAIN;
    if (strcmp(nom_commande, "SCORES") == 0)
        return CMD_SCORES;
    if (strcmp(nom_commande, "CLASSEMENT") == 0)
        return CMD_CLASSEMENT;
    if (strcmp(nom_commande, "COMPARAISON") == 0)
        return CMD_COMPARAISON;
    if (strcmp(nom_commande, "BILAN") == 0)
        return CMD_BILAN;
    if (strcmp(nom_commande, "AIDE") == 0)
        return CMD_AIDE;
    return CMD_INCONNUE;
}

/**
 * \copydoc analyser_saisie
 */
int analyser_saisie(char *ligne_saisie, CommandeAnalysee *commande)
{
    separer_commande_et_arguments(ligne_saisie, &commande->nom, &commande->arguments);

    if (commande->nom == NULL)
    {
        return 0;
    }

    // On convertit le texte saisi en un identifiant numérique (type de commande)
    commande->type = identifier_type_commande(commande->nom);
    return 1;
}