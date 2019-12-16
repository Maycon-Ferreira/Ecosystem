#include "../include/eco.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("Usage: ./ecosystem FILE");
        return -1;
    }

    eco_read_input(argv[1]);
    eco_sim_run();
    eco_print_step();

    return 0;
}
