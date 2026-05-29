#include "generator.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const char *UPPER   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char *LOWER   = "abcdefghijklmnopqrstuvwxyz";
static const char *DIGITS  = "0123456789";
static const char *SYMBOLS = "!@#$%^&*()-_=+[]{}|;:,.<>?";

char *generate_password(const GenConfig *cfg) {
    char pool[256] = {0};
    if (cfg->use_upper)   strncat(pool, UPPER,   sizeof(pool) - strlen(pool) - 1);
    if (cfg->use_lower)   strncat(pool, LOWER,   sizeof(pool) - strlen(pool) - 1);
    if (cfg->use_digits)  strncat(pool, DIGITS,  sizeof(pool) - strlen(pool) - 1);
    if (cfg->use_symbols) strncat(pool, SYMBOLS, sizeof(pool) - strlen(pool) - 1);

    size_t pool_len = strlen(pool);
    if (pool_len == 0) return NULL;

    srand((unsigned int)time(NULL));
    char *password = malloc(cfg->length + 1);
    if (!password) return NULL;

    for (int i = 0; i < cfg->length; i++) {
        password[i] = pool[rand() % pool_len];
    }
    password[cfg->length] = '\0';
    return password;
}
