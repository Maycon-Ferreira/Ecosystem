#ifndef ECOSYSTEM_ECO_H
#define ECOSYSTEM_ECO_H

typedef enum {
    EMPTY,
    FOX,
    RABBIT,
    ROCK
} eco_type_t;

typedef struct {
    eco_type_t type;
    int age;
    int hunger;
} eco_fox_t;

typedef struct {
    eco_type_t type;
    int age;
} eco_rabbit_t;

typedef struct {
    eco_type_t type;
} eco_rock_t;

typedef union {
    eco_fox_t fox;
    eco_rabbit_t rabbit;
    eco_rock_t rock;
} eco_object_t;

int eco_read_input(char* filepath);

int eco_sim_step();
void eco_sim_run();

#endif // ECOSYSTEM_ECO_H
