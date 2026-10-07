/**
 * \file saisie.c
 * \brief Implémentation des fonctions de lecture sécurisée et de traitement textuel des saisies utilisateur.
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "saisie.h"

/**
 * \brief Lit une ligne brute depuis l'entrée standard et supprime le saut de ligne final.
 * \fn static int lire_saisie(char *buffer, size_t taille)
 * 
 * \param buffer Pointeur vers le tampon de stockage.
 * \param taille Taille maximale du tampon.
 * \return 1 en cas de succès, 0 en cas d'échec (EOF).
 */
static int lire_saisie(char *buffer, size_t taille)
{
    if (fgets(buffer, taille, stdin) == NULL)
    {
        return 0;
    }

    buffer[strcspn(buffer, "\n")] = 0;
    return 1;
}

/**
 * \copydoc saisir_commande
 */
int saisir_commande(char *buffer, size_t taille)
{
    while (1)
    {
#ifdef ECHO_SAISIE
        printf("\nSaisir votre commande : ");
        fflush(stdout);
#endif

        if (!lire_saisie(buffer, taille))
        {
            return 0;
        }

#ifdef ECHO_SAISIE
        printf("> %s\n", buffer);
#endif

        if (strlen(buffer) > 0)
        {
            return 1;
        }
    }
}

/**
 * \copydoc extraire_arguments
 */
int extraire_arguments(char *arguments, char *mots[], int nb_max)
{
    assert(mots != NULL);
    assert(nb_max > 0);

    int nb_mots = 0;

    if (arguments == NULL)
    {
        return 0;
    }

    char *mot = strtok(arguments, " ");
    while (mot != NULL && nb_mots < nb_max)
    {
        mots[nb_mots] = mot;
        nb_mots++;
        mot = strtok(NULL, " ");
    }

    return nb_mots;
}

/**
 * \copydoc separer_commande_et_arguments
 */
void separer_commande_et_arguments(char *ligne, char **nom_commande, char **arguments)
{
    *nom_commande = strtok(ligne, " ");
    *arguments = strtok(NULL, "");
}