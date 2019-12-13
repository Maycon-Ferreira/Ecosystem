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

int eco_read_input(char *filepath) {
    return 0;
}

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
