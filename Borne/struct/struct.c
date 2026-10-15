#include <stdio.h>
#include <string.h>
#include "struct.h"

void struct_recibir_token(const char *token) {
    static int esperando_texto = 0;

    if (strcmp(token, "TOKEN_ECHO") == 0) {
        esperando_texto = 1;
        return;
    }

    if (esperando_texto) {
        if (token[0] == '\'') {
            printf("%s\n", token + 1);
        } else {
            printf("%s\n", token);
        } esperando_texto = 0;
    }
}