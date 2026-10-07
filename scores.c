/**
 * \file scores.c
 * \brief Implémentation des fonctions d'enregistrement des gains et d'affichage des scores individuels.
 */

#include <assert.h>
#include <stdio.h>
#include "scores.h"
#include "affichage.h"

/**
 * \copydoc enregistrer_gain
 */
void enregistrer_gain(Application *app, int id_participant, int id_concours, int points)
{
    assert(app != NULL);

    if (id_participant < 1 || id_participant > app->nb_participants)
    {
        printf("Participant incorrect\n");
        return;
    }

    if (id_concours < 1 || id_concours > app->nb_concours)
    {
        printf("Concours incorrect\n");
        return;
    }

    if (points <= 0)
    {
        printf("Points incorrects\n");
        return;
    }

    // Identifiant - 1 = indice dans les tableaux ; les points s'ajoutent au score existant
    app->scores[id_participant - 1][id_concours - 1] += points;
    printf("Gain enregistre\n");
}

/**
 * \copydoc afficher_scores
 */
void afficher_scores(const Application *app, int id_participant)
{
    assert(app != NULL);

    if (id_participant < 1 || id_participant > app->nb_participants)
    {
        printf("Identifiant incorrect\n");
        return;
    }

    int p = id_participant - 1; // Conversion de l'identifiant en indice

    printf("%s %s\n", app->participants[p].prenom, app->participants[p].nom);

    // Suivi pour s'assurer d'afficher un unique "Aucun gain" si tous les scores sont nuls
    int a_des_gains = 0;

    for (int c = 0; c < app->nb_concours; c++)
    {
        int score = app->scores[p][c];

        if (score > 0)
        {
            printf("(%d) %s : %d %s\n",
                   c + 1,
                   app->concours[c].nom,
                   score,
                   accord(score, "point", "points"));
            a_des_gains = 1;
        }
    }

    if (!a_des_gains)
    {
        printf("Aucun gain\n");
    }
}