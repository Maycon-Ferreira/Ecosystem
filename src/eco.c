#include "../include/eco.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int GEN_RABBIT_PROC = 0;
int GEN_FOX_PROC = 0;
int GEN_FOX_STARVE = 0;

int MAX_GEN_COUNT = 0;
int gen_count = 0;

size_t L = 0;
size_t C = 0;

eco_object_t **ecosystem = NULL;
__uint8_t **candidates[4] = {0};

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

// @TODO safe input read
int eco_read_input(char *filepath) {
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        return 2;
    }

    fscanf(file, "%d %d %d %d %zu %zu", &GEN_RABBIT_PROC, &GEN_FOX_PROC, &GEN_FOX_STARVE, &MAX_GEN_COUNT, &L, &C);

    ecosystem = calloc(L, sizeof(eco_object_t *));

    for (int i = 0; i < 4; ++i) {
        candidates[i] = calloc(L, sizeof(__uint8_t *));

        for (int j = 0; j < L; ++j) {
            candidates[i][j] = calloc(C, sizeof(__uint8_t));
            ecosystem[j] = calloc(C, sizeof(eco_object_t));
        }
    }

    int object_count = 0;

    fscanf(file, "%d\n", &object_count);

    int i, j;
    char object[7] = {0};

    for (int k = 0; k < object_count; ++k) {
        fscanf(file, "%6s %d %d\n", object, &i, &j);

        if (strcmp(object, "COELHO") == 0) { ecosystem[i][j].rabbit.type = RABBIT; }
        else if (strcmp(object, "ROCHA") == 0) { ecosystem[i][j].rock.type = ROCK; }
        else if (strcmp(object, "RAPOSA") == 0) { ecosystem[i][j].fox.type = FOX; }
    }

    fclose(file);

    return 0;
}

#pragma clang diagnostic pop

void register_rabbit(int i, int j) {
    if (*((eco_type_t *) &ecosystem[i][j]) == RABBIT) {
        int P = 0;

        if (i - 1 >= 0 && *((eco_type_t *) &ecosystem[i - 1][j]) == EMPTY) { ++P; }
        if (j + 1 < C && *((eco_type_t *) &ecosystem[i][j + 1]) == EMPTY) { ++P; }
        if (i + 1 < L && *((eco_type_t *) &ecosystem[i + 1][j]) == EMPTY) { ++P; }
        if (j - 1 >= 0 && *((eco_type_t *) &ecosystem[i][j - 1]) == EMPTY) { ++P; }

        P = (gen_count + i + j) % P;

        if (i - 1 >= 0 && *((eco_type_t *) &ecosystem[i - 1][j]) == EMPTY && --P == 0) {
            candidates[SOUTH][i - 1][j] = 1;
        }
        if (j + 1 < C && *((eco_type_t *) &ecosystem[i][j + 1]) == EMPTY && --P == 0) {
            candidates[WEST][i][j + 1] = 1;
        }
        if (i + 1 < L && *((eco_type_t *) &ecosystem[i + 1][j]) == EMPTY && --P == 0) {
            candidates[NORTH][i + 1][j] = 1;
        }
        if (j - 1 >= 0 && *((eco_type_t *) &ecosystem[i][j - 1]) == EMPTY && --P == 0) {
            candidates[EAST][i][j - 1] = 1;
        }
    }
}

int eco_sim_step() {
    if (gen_count == MAX_GEN_COUNT) { return -1; }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            register_rabbit(i, j);
        }
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            // @TODO move rabbits
        }
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            // @TODO register fox candidates
        }
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            // @TODO move foxes
        }
    }

    ++gen_count;

    return 0;
}

void eco_sim_run() {
    while (eco_sim_step() == 0);
}
