#include "../inc/string.h"

char *strnew(unsigned int size) {
    char *new_str = malloc((size + 1) * sizeof(char));
    for (unsigned int i = 0; i < size + 1; i++) {
        new_str[i] = '\0';
    }
    return new_str;
}

