#!/bin/bash

# Vérification que les deux paramètres sont bien fournis
if [ $# -ne 2 ]; then
    echo "Usage: $0 <numero_sp> <numero_test>"
    echo "Exemple: $0 3 2 (utilisera in-sp3-2.txt et out-sp3-2.txt)"
    exit 1
fi

SP=$1
TEST_NUM=$2

INPUT_FILE="tests/inout/in-sp${SP}-${TEST_NUM}.txt"
EXPECTED_FILE="tests/inout/out-sp${SP}-${TEST_NUM}.txt"
OUTPUT_BRUT="tests/output_brut.txt"
OUTPUT_ACTUEL="tests/output_actuel.txt"

# Vérification de l'existence des fichiers de test
if [ ! -f "$INPUT_FILE" ] || [ ! -f "$EXPECTED_FILE" ]; then
    echo "=== ERREUR : Fichiers introuvables pour sp${SP}-${TEST_NUM} ==="
    echo "Vérifie que $INPUT_FILE et $EXPECTED_FILE existent."
    exit 1
fi

# Compilation
gcc -Wall -Wextra *.c -o programme
if [ $? -ne 0 ]; then
    echo "=== ERREUR DE COMPILATION ==="
    exit 1
fi

# Exécution avec le fichier d'entrée correspondant
./programme < "$INPUT_FILE" > "$OUTPUT_BRUT"

# Nettoyage des séquences d'échappement ANSI (comme \033[2J) pour la comparaison
sed 's/\x1B\[[0-9;]*[JKmsu]//g' "$OUTPUT_BRUT" > "$OUTPUT_ACTUEL"

# Comparaison avec le fichier de sortie attendu
if diff -u --strip-trailing-cr "$EXPECTED_FILE" "$OUTPUT_ACTUEL"; then
    echo "=== TEST sp${SP}-${TEST_NUM} PASSÉ AVEC SUCCÈS ==="
    exit 0
else
    echo "=== ÉCHEC DU TEST sp${SP}-${TEST_NUM} : LA SORTIE DIFFÈRE ==="
    exit 1
fi