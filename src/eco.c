#include "../include/eco.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GEN_RABBIT_PROC = 0;
int GEN_FOX_PROC = 0;
int GEN_FOX_STARVE = 0;

int MAX_GEN_COUNT = 0;
int step_count = 0;

size_t L = 0;
size_t C = 0;

eco_object_t **ecosystem = NULL;
__uint8_t **candidates = NULL;

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
    candidates = calloc(L, sizeof(__uint8_t *));

    for (int i = 0; i < L; ++i) {
        ecosystem[i] = calloc(C, sizeof(eco_object_t *));
        candidates[i] = calloc(C, sizeof(__uint8_t *));
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

int eco_sim_step() {
    if (step_count == MAX_GEN_COUNT) { return -1; }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            // @TODO register rabbit candidates
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

    ++step_count;

    return 0;
}

void eco_sim_run() {
    while (eco_sim_step() == 0);
}
