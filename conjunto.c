#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

void manejaMsg(int);

CONJUNTO conjuntovacio(int tamanio) {
    CONJUNTO C;
    C = (CONJUNTO)malloc(sizeof(Conjunto));
    if (C == NULL) {
        manejaMsg(1);
        exit(0);
    }
    C->c = (int *)malloc(tamanio * sizeof(int));
    if (C->c == NULL) {
        manejaMsg(1);
        free(C);
        exit(0);
    }
    C->tamanio = 0;
    return C;
}

void anadir(CONJUNTO C, int elemento) {
//hacemos uso de la función pertenecer
    if (!pertenece(C, elemento)) {
        C->c[C->tamanio] = elemento;
        C->tamanio++;
    }
}

void retirar(CONJUNTO C, int elemento) {
    int i;
    for (i = 0; i < C->tamanio; i++) {
        if (C->c[i] == elemento) {
            // Mover los elementos restantes para llenar el espacio
            for (int j = i; j < C->tamanio - 1; j++) {
                C->c[j] = C->c[j + 1];
            }
            C->tamanio--;
            return;
        }
    }
}

int pertenece(CONJUNTO C, int elemento) {
    for (int i = 0; i < C->tamanio; i++) {
        if (C->c[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

int esVacio(CONJUNTO C) {
    return C->tamanio == 0;
}

int cardinal(CONJUNTO C) {
    return C->tamanio;
}

CONJUNTO unir(CONJUNTO C1, CONJUNTO C2) {
    CONJUNTO resultado = conjuntovacio(C1->tamanio + C2->tamanio);
    for (int i = 0; i < C1->tamanio; i++) {
        anadir(resultado, C1->c[i]);
    }
    for (int i = 0; i < C2->tamanio; i++) {
        anadir(resultado, C2->c[i]);
    }
    return resultado;
}

CONJUNTO interseccion(CONJUNTO C1, CONJUNTO C2) {
    CONJUNTO resultado = conjuntovacio(C1->tamanio);
    for (int i = 0; i < C1->tamanio; i++) {
        if (pertenece(C2, C1->c[i])) {
            anadir(resultado, C1->c[i]);
        }
    }
    return resultado;
}

int inclusion(CONJUNTO C1, CONJUNTO C2) {
    for (int i = 0; i < C1->tamanio; i++) {
        if (!pertenece(C2, C1->c[i])) {
            return 0;
        }
    }
    return 1;
}
