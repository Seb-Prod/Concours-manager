/**
 * \file participants.c
 * \brief Implémentation des fonctions de gestion des participants.
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "participants.h"

/**
 * \brief Compte le nombre de concours pour lesquels un participant a un score non nul.
 * \fn static int compter_concours_du_participant(const Application *app, int p)
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param p Indice du participant concerné (compris entre 0 et nb_participants - 1).
 * \return Le nombre total de concours où le score du participant est strictement positif.
 * 
 * \pre app != NULL
 * \pre p >= 0 && p < app->nb_participants
 */
static int compter_concours_du_participant(const Application *app, int p)
{
    assert(app != NULL);
    assert(p >= 0 && p < app->nb_participants);

    int total = 0;
    for (int c = 0; c < app->nb_concours; c++)
    {
        if (app->scores[p][c] > 0)
        {
            total++;
        }
    }
    return total;
}

/**
 * \brief Recherche un participant existant par son prénom et son nom.
 * \fn static int trouver_participant(const Application *app, const char *prenom, const char *nom)
 * 
 * \param app Pointeur vers la structure principale de l'application.
 * \param prenom Prénom recherché.
 * \param nom Nom recherché.
 * \return L'indice du participant dans le tableau s'il est trouvé, ou -1 s'il est inconnu.
 */
static int trouver_participant(const Application *app, const char *prenom, const char *nom)
{
    for (int i = 0; i < app->nb_participants; i++)
    {
        if (strcmp(app->participants[i].prenom, prenom) == 0 &&
            strcmp(app->participants[i].nom, nom) == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \copydoc inscrire_participant
 */
void inscrire_participant(Application *app, const char *prenom, const char *nom)
{
    assert(app != NULL);
    assert(prenom != NULL && nom != NULL);
    assert(strlen(prenom) <= MAX_LONGUEUR_NOM);
    assert(strlen(nom) <= MAX_LONGUEUR_NOM);
    assert(app->nb_participants < MAX_PARTICIPANTS);

    // Vérification de l'unicité du couple (prénom, nom)
    if (trouver_participant(app, prenom, nom) != -1)
    {
        printf("Nom incorrect\n");
        return;
    }

    // Ajout du nouveau participant
    Participant *nouveau = &app->participants[app->nb_participants];
    strcpy(nouveau->prenom, prenom);
    strcpy(nouveau->nom, nom);
    app->nb_participants++;

    // Initialisation de son rang précédent (score nul) pour chaque concours existant
    int p = app->nb_participants - 1;
    for (int c = 0; c < app->nb_concours; c++)
    {
        app->rang_precedent[c][p] = calculer_rang(app, p, c);
    }

    printf("Inscription enregistree (%d)\n", app->nb_participants);
}

/**
 * \copydoc lister_participants
 */
void lister_participants(const Application *app)
{
    assert(app != NULL);

    if (app->nb_participants == 0)
    {
        printf("Aucun participant inscrit\n");
        return;
    }

    for (int i = 0; i < app->nb_participants; i++)
    {
        printf("(%d) %s %s : %d concours\n",
               i + 1,
               app->participants[i].prenom,
               app->participants[i].nom,
               compter_concours_du_participant(app, i));
    }
}