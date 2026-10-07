#ifndef SAISIE_H
#define SAISIE_H

#include <stddef.h>

/**
 * \file saisie.h
 * \brief Gestion des entrées utilisateur, de la lecture de commandes et du découpage des arguments (déclarations et prototypes).
 */

/**
 * \brief Affiche le prompt (si activé) et lit une commande non vide depuis l'entrée standard.
 * \details Ignore les lignes vides et continue la lecture jusqu'à obtenir une chaîne valide 
 *          ou rencontrer une fin de fichier (EOF).
 * 
 * \param buffer Pointeur vers le tableau de caractères (tampon) devant stocker la saisie (non NULL).
 * \param taille Taille maximale du tampon.
 * \return 0 en cas de fin de flux (EOF), 1 si une commande valide a été lue.
 */
int saisir_commande(char *buffer, size_t taille);

/**
 * \brief Sépare une ligne de saisie en nom de commande et en chaîne d'arguments.
 * \details Utilise `strtok` pour isoler le premier mot (nom de commande) et récupérer le reste de la ligne (arguments).
 * 
 * \param ligne Ligne de caractères brute à analyser (attention : modifiée par la fonction).
 * \param nom_commande Pointeur de pointeur pour stocker le nom de la commande extrait.
 * \param arguments Pointeur de pointeur pour stocker la chaîne des arguments restante.
 */
void separer_commande_et_arguments(char *ligne, char **nom_commande, char **arguments);

/**
 * \brief Découpe une chaîne d'arguments en plusieurs mots individuels.
 * \details Remplit le tableau de pointeurs avec au plus `nb_max` mots. Modifie la chaîne source.
 * 
 * \param arguments Chaîne de caractères contenant les arguments à découper (peut être NULL).
 * \param mots Tableau pré-alloué de pointeurs de caractères destiné à recevoir les mots extraits (non NULL).
 * \param nb_max Nombre maximal de mots que le tableau peut accepter (doit être > 0).
 * \return Le nombre total de mots trouvés et extraits.
 * 
 * \pre mots != NULL
 * \pre nb_max > 0
 */
int extraire_arguments(char *arguments, char *mots[], int nb_max);

#endif