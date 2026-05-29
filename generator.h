#ifndef GENERATOR_H
#define GENERATOR_H

#include <stddef.h>

typedef struct {
    int length;
    int use_upper;
    int use_lower;
    int use_digits;
    int use_symbols;
} GenConfig;

char *generate_password(const GenConfig *cfg);

#endif /* GENERATOR_H */
