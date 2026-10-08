/**
 * \file concours.c
 * \brief Implémentation des fonctions de gestion et d'affichage des concours.
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "concours.h"
#include "affichage.h"

/**
 * \brief Compte le nombre de participants ayant un score non nul dans un concours.
 * \fn static int compter_participants_du_concours(const Application *app, int c)
 *
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param c Indice du concours concerné (compris entre 0 et nb_concours - 1).
 * \return Le nombre total de participants ayant un score strictement positif pour ce concours.
 *
 * \pre app != NULL
 * \pre c >= 0 && c < app->nb_concours
 */
static int compter_participants_du_concours(const Application *app, int c)
{
    assert(app != NULL);
    assert(c >= 0 && c < app->nb_concours);

    int total = 0;
    for (int p = 0; p < app->nb_participants; p++)
    {
        if (app->scores[p][c] > 0)
        {
            total++;
        }
    }
    return total;
}

/**
 * \brief Recherche un concours existant par son nom.
 * \fn static int touver_concour(const Application *app, const char *nom)
 *
 * \param app Pointeur vers la structure principale de l'application.
 * \param nom Nom du concours recherché.
 * \return L'indice du concours dans le tableau s'il est trouvé, ou -1 s'il est inconnu.
 */
static int touver_concour(const Application *app, const char *nom)
{
    for (int i = 0; i < app->nb_concours; i++)
    {
        if (strcmp(app->concours[i].nom, nom) == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \copydoc ajouter_concour
 */
void ajouter_concour(Application *app, const char *nom)
{
    assert(app != NULL);
    assert(nom != NULL);
    assert(strlen(nom) <= MAX_LONGUEUR_NOM);
    assert(app->nb_concours < MAX_CONCOURS);

    // Vérification de l'unicité du nom du concours
    if (touver_concour(app, nom) != -1)
    {
        printf("Nom incorrect\n");
        return;
    }

    // Ajout du nouveau concours
    Concours *nouveau = &app->concours[app->nb_concours];
    strcpy(nouveau->nom, nom);
    app->nb_concours++;

    // Nouveau concours : tous les scores sont nuls, donc tous les participants sont au rang 1
    int c = app->nb_concours - 1;
    for (int p = 0; p < app->nb_participants; p++)
    {
        app->rang_precedent[c][p] = 1;
    }

    printf("Creation enregistree (%d)\n", app->nb_concours);
}

/**
 * \copydoc lister_concours
 */
void lister_concours(const Application *app)
{
    assert(app != NULL);

    if (app->nb_concours == 0)
    {
        printf("Aucun concours cree\n");
        return;
    }

    for (int i = 0; i < app->nb_concours; i++)
    {
        int nb_participants = compter_participants_du_concours(app, i);
        printf("(%d) %s : %d participant%s\n",
               i + 1,
               app->concours[i].nom,
               nb_participants,
               accord(nb_participants, "", "s"));
    }
}