#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexerh.h"
#include "../paser/paser.h"

void lexer_analizar(const char *codigo) {
    char *copia = malloc(strlen(codigo) + 1);

    if (copia == NULL) {
        printf("ERROR: no hay memoria suficiente\n");
        return;
    }
    
    strcpy(copia, codigo);

    char *token = strtok(copia, " \t\n\r");

    while (token != NULL) {
        if (strcmp(token, "echo") == 0) {
            paser_recibir_token("TOKEN_ECHO");
        } else if (strcmp(token, "set") == 0) {
            paser_recibir_token("TOKEN_SET");
        } else if (strcmp(token, "boner") == 0 ||
                   strcmp(token, "borne") == 0) {
            paser_recibir_token("TOKEN_BORNE");
        } else if (strcmp(token, "cls") == 0) {
            paser_recibir_token("TOKEN_CLS");
        } else if (strcmp(token, "{") == 0) {
            paser_recibir_token("TOKEN_LLAVES_ABRIR");
        } else if (strcmp(token, "}") == 0) {
            paser_recibir_token("TOKEN_LLAVES_CERRAR");
        } else {
            paser_recibir_token(token);
        } token = strtok(NULL, " \t\n\r");
    } free(copia);
}