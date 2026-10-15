#include <stdio.h>
#include <stdlib.h>
#include "lexer/lexerh.h"

int main(void) {
    FILE *archivo = fopen("Proyecto.bn", "r");

    if (archivo == NULL) {
        printf("ERROR: no se pudo abrir Proyecto.bn\n");
        return 1;
    }

    char linea[1024];

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        lexer_analizar(linea);
    }

    fclose(archivo);
    return 0;
}