#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H

#include "donnees.h"
#include "classement.h"

/**
 * \file participants.h
 * \brief Gestion des participants (déclarations et prototypes).
 */

/**
 * \brief Inscrit un nouveau participant dans l'application.
 * \details Vérifie si le participant existe déjà (même prénom et même nom).
 *          Si c'est le cas, affiche "Nom incorrect". Sinon, l'ajoute à la liste,
 *          met à jour ses rangs initiaux pour les concours existants et affiche 
 *          le message de confirmation avec son identifiant.
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param prenom Chaîne de caractères représentant le prénom du participant (non NULL, max 30 caractères).
 * \param nom Chaîne de caractères représentant le nom du participant (non NULL, max 30 caractères).
 * 
 * \pre app != NULL
 * \pre prenom != NULL && nom != NULL
 * \pre strlen(prenom) <= MAX_LONGUEUR_NOM
 * \pre strlen(nom) <= MAX_LONGUEUR_NOM
 * \pre app->nb_participants < MAX_PARTICIPANTS
 */
void inscrire_participant(Application *app, const char *prenom, const char *nom);

/**
 * \brief Affiche la liste de tous les participants inscrits.
 * \details Affiche chaque participant sur une ligne dans l'ordre croissant de leurs identifiants, 
 *          suivi du nombre de concours pour lequel leur score est non nul.
 *          Si aucun participant n'est inscrit, affiche "Aucun participant inscrit".
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * 
 * \pre app != NULL
 */
void lister_participants(const Application *app);

#endif