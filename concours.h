#ifndef CONCOURS_H
#define CONCOURS_H

#include "donnees.h"

/**
 * \file concours.h
 * \brief Gestion et création des concours (déclarations et prototypes).
 */

/**
 * \brief Ajoute un nouveau concours dans l'application.
 * \details Vérifie si un concours portant le même nom existe déjà. 
 *          Si c'est le cas, affiche "Nom incorrect". Sinon, l'ajoute à la liste, 
 *          initialise les rangs précédents de tous les participants à 1, 
 *          et affiche le message de confirmation avec son identifiant.
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param nom Chaîne de caractères représentant le nom du concours (non NULL, max MAX_LONGUEUR_NOM caractères).
 * 
 * \pre app != NULL
 * \pre nom != NULL
 * \pre strlen(nom) <= MAX_LONGUEUR_NOM
 * \pre app->nb_concours < MAX_CONCOURS
 */
void ajouter_concour(Application *app, const char *nom);

/**
 * \brief Affiche la liste de tous les concours créés.
 * \details Affiche chaque concours sur une ligne dans l'ordre croissant de leurs identifiants, 
 *          suivi du nombre de participants ayant un score non nul pour ce concours.
 *          Si aucun concours n'est créé, affiche "Aucun concours cree".
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * 
 * \pre app != NULL
 */
void lister_concours(const Application *app);

#endif