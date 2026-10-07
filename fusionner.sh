#!/bin/bash

FICHIER_SORTIE="rendu_global.c"

echo "// --- FUSION DE TOUS LES FICHIERS DU PROJET ---" > "$FICHIER_SORTIE"
echo "" >> "$FICHIER_SORTIE"

echo "/* --- EN-TÊTES ET LIBRAIRIES --- */" >> "$FICHIER_SORTIE"
cat << 'EOF' >> "$FICHIER_SORTIE"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
EOF
echo "" >> "$FICHIER_SORTIE"

echo "/* --- FICHIERS D'EN-TÊTE (.h) --- */" >> "$FICHIER_SORTIE"
for f in *.h; do
    if [ -f "$f" ] && [ "$f" != "$FICHIER_SORTIE" ]; then
        echo "/* Début du fichier : $f */" >> "$FICHIER_SORTIE"
        grep -v '^#include "' "$f" >> "$FICHIER_SORTIE"
        echo "" >> "$FICHIER_SORTIE"
    fi
done

echo "/* --- FICHIERS SOURCES (.c) --- */" >> "$FICHIER_SORTIE"
for f in *.c; do
    if [ "$f" != "main.c" ] && [ "$f" != "$FICHIER_SORTIE" ] && [ -f "$f" ]; then
        echo "/* Début du module : $f */" >> "$FICHIER_SORTIE"
        grep -v '^#include "' "$f" >> "$FICHIER_SORTIE"
        echo "" >> "$FICHIER_SORTIE"
    fi
done

if [ -f "main.c" ]; then
    echo "/* --- PROGRAMME PRINCIPAL (main.c) --- */" >> "$FICHIER_SORTIE"
    grep -v '^#include "' "main.c" >> "$FICHIER_SORTIE"
fi

echo "Fusion terminée avec succès dans le fichier : $FICHIER_SORTIE"