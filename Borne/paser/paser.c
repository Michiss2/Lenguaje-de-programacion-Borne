#include <stdio.h>
#include <string.h>
#include "paser.h"
#include "../read/read.h"

void paser_recibir_token(const char *token) {
    static int boner = 0;
    static int cls = 0;
    static int abrir = 0;
    static int cerrar = 0;

    read_recibir_token(token);

    if (strcmp(token, "TOKEN_BORNE") == 0 ||
        strcmp(token, "boner") == 0) {
        boner = 1;
    }

    if (strcmp(token, "TOKEN_CLS") == 0) {
        cls = 1;
    }

    if (strcmp(token, "TOKEN_LLAVES_ABRIR") == 0) {
        abrir = 1;
    }

    if (strcmp(token, "TOKEN_LLAVES_CERRAR") == 0) {
        cerrar = 1;
    }

    if (boner && cls && abrir && cerrar) {
        printf("Verificado: estructura correcta: token BONER, token CLS, token LLAVES_ABRIR, token LLAVES_CERRAR\n");

        read_recibir_estructura();

        boner = 0;
        cls = 0;
        abrir = 0;
        cerrar = 0;
    }
}