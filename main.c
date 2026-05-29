#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generator.h"

int main(int argc, char *argv[]) {
    GenConfig cfg = { .length = 12, .use_upper = 1, .use_lower = 1, .use_digits = 1, .use_symbols = 0 };

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0 && i + 1 < argc) { cfg.length  = atoi(argv[++i]); }
        else if (strcmp(argv[i], "-s") == 0) { cfg.use_symbols = 1; }
        else if (strcmp(argv[i], "--no-upper") == 0) { cfg.use_upper = 0; }
        else if (strcmp(argv[i], "--no-lower") == 0) { cfg.use_lower = 0; }
        else if (strcmp(argv[i], "--no-digits") == 0) { cfg.use_digits = 0; }
    }

    char *pw = generate_password(&cfg);
    if (!pw) { fprintf(stderr, "Error: empty character pool.\n"); return 1; }

    printf("Generated password: %s\n", pw);
    free(pw);
    return 0;
}
