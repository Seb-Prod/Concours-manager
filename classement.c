/**
 * \file classement.c
 * \brief Implémentation des fonctions de calcul, de tri et d'affichage des classements.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "classement.h"
#include "affichage.h"

/**
 * \copydoc calculer_rang
 */
int calculer_rang(const Application *app, int p, int c)
{
    assert(app != NULL);
    assert(p >= 0 && p < app->nb_participants);
    assert(c >= 0 && c < app->nb_concours);

    int rang = 1;
    for (int q = 0; q < app->nb_participants; q++)
    {
        if (app->scores[q][c] > app->scores[p][c])
        {
            rang++;
        }
    }
    return rang;
}

/**
 * \brief Vérifie si un participant est ex æquo avec un autre dans un concours.
 * \fn static int est_ex_aequo(const Application *app, int p, int c)
 * 
 * \param app Pointeur vers la structure principale de l'application.
 * \param p Indice du participant concerné.
 * \param c Indice du concours.
 * \return 1 si un autre participant a exactement le même score, 0 sinon.
 */
static int est_ex_aequo(const Application *app, int p, int c)
{
    for (int q = 0; q < app->nb_participants; q++)
    {
        if (q != p && app->scores[q][c] == app->scores[p][c])
        {
            return 1;
        }
    }
    return 0;
}

/**
 * \brief Remplit un tableau avec les indices des participants triés pour un concours.
 * \fn static void trier_classement(const Application *app, int c, int ordre[], int *nb)
 * \details Tri par insertion par score décroissant, puis par identifiant croissant en cas d'égalité.
 * 
 * \param app Pointeur vers la structure principale de l'application.
 * \param c Indice du concours.
 * \param ordre Tableau pré-alloué destiné à recevoir les indices triés.
 * \param nb Pointeur vers un entier pour stocker le nombre effectif de participants classés.
 */
static void trier_classement(const Application *app, int c, int ordre[], int *nb)
{
    *nb = 0;
    for (int p = 0; p < app->nb_participants; p++)
    {
        if (app->scores[p][c] > 0)
        {
            // Tri par insertion : on décale les scores strictement plus petits.
            int i = *nb;
            while (i > 0 && app->scores[ordre[i - 1]][c] < app->scores[p][c])
            {
                ordre[i] = ordre[i - 1];
                i--;
            }
            ordre[i] = p;
            (*nb)++;
        }
    }
}

/**
 * \brief Affiche les lignes individuelles du classement d'un concours.
 * \fn static void afficher_lignes_classement(const Application *app, int c, int avec_bilan)
 * 
 * \param app Pointeur vers la structure principale de l'application.
 * \param c Indice du concours.
 * \param avec_bilan Indicateur booléen (1 pour afficher l'évolution des places, 0 sinon).
 */
static void afficher_lignes_classement(const Application *app, int c, int avec_bilan)
{
    int ordre[MAX_PARTICIPANTS];
    int nb;

    trier_classement(app, c, ordre, &nb);

    if (nb == 0)
    {
        printf("Aucun participant\n");
        return;
    }

    for (int i = 0; i < nb; i++)
    {
        int p = ordre[i];
        int score = app->scores[p][c];

        printf("%d%s -> (%d) %s %s : %d %s",
               calculer_rang(app, p, c),
               est_ex_aequo(app, p, c) ? "ex" : "",
               p + 1,
               app->participants[p].prenom,
               app->participants[p].nom,
               score,
               accord(score, "point", "points"));

        if (avec_bilan)
        {
            // Places gagnées = ancien rang - rang actuel
            int places = app->rang_precedent[c][p] - calculer_rang(app, p, c);
            printf(" : %+d %s", places, accord(abs(places), "place", "places"));
        }
        printf("\n");
    }
}

/**
 * \copydoc afficher_classement
 */
void afficher_classement(const Application *app, int id_concours)
{
    assert(app != NULL);

    if (id_concours < 1 || id_concours > app->nb_concours)
    {
        printf("Identifiant incorrect\n");
        return;
    }

    int c = id_concours - 1;
    printf("%s\n", app->concours[c].nom);
    afficher_lignes_classement(app, c, 0);
}

/**
 * \copydoc afficher_comparaison
 */
void afficher_comparaison(const Application *app, int id_concours1, int id_concours2)
{
    assert(app != NULL);

    if (id_concours1 < 1 || id_concours1 > app->nb_concours ||
        id_concours2 < 1 || id_concours2 > app->nb_concours)
    {
        printf("Identifiant incorrect\n");
        return;
    }

    int c1 = id_concours1 - 1;
    int c2 = id_concours2 - 1;
    int a_un_score = 0;  
    int incompatible = 0; 

    for (int p = 0; p < app->nb_participants; p++)
    {
        int score1 = app->scores[p][c1];
        int score2 = app->scores[p][c2];

        if (score1 > 0 || score2 > 0)
        {
            a_un_score = 1;
        }
        if (score1 == 0 && score2 > 0)
        {
            incompatible = 1;
        }
    }

    if (!a_un_score)
    {
        printf("Aucun participant\n");
        return;
    }
    if (incompatible)
    {
        printf("Concours incompatibles\n");
        return;
    }

    printf("%s versus %s\n", app->concours[c2].nom, app->concours[c1].nom);

    for (int p = 0; p < app->nb_participants; p++)
    {
        int score1 = app->scores[p][c1];
        int score2 = app->scores[p][c2];

        if (score1 > 0) 
        {
            printf("(%d) %s %s : %d %s/%d %s : %.2f%%\n",
                   p + 1,
                   app->participants[p].prenom,
                   app->participants[p].nom,
                   score2, accord(score2, "point", "points"),
                   score1, accord(score1, "point", "points"),
                   100.0 * score2 / score1);
        }
    }
}

/**
 * \copydoc afficher_bilan
 */
void afficher_bilan(Application *app, int id_concours)
{
    assert(app != NULL);

    if (id_concours < 1 || id_concours > app->nb_concours)
    {
        printf("Identifiant incorrect\n");
        return;
    }

    int c = id_concours - 1;
    printf("%s\n", app->concours[c].nom);
    afficher_lignes_classement(app, c, 1);

    // Mémorisation des rangs actuels pour le prochain bilan
    for (int p = 0; p < app->nb_participants; p++)
    {
        app->rang_precedent[c][p] = calculer_rang(app, p, c);
    }
}