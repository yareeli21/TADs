#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void manejaMsg(int);
void darDatos(MATRIZ);
void mostrarM(MATRIZ);
void menu(MATRIZ, MATRIZ);
void liberarM(MATRIZ M1);

void main() {
    int fil, col;
    MATRIZ M1, M2;
    printf("#DE FILAS?\n");
    scanf("%d",&fil);
    printf("#DE COLUMNAS?\n");
    scanf("%d",&col);

    M1 = crearMatriz(fil, col);
    M2 = crearMatriz(fil, col);

    printf("Dar datos a la matriz 1\n");
    darDatos(M1);
    printf("Dar datos a la matriz 2\n");
    darDatos(M2);

    menu(M1, M2);
}
void menu(MATRIZ M1, MATRIZ M2) {
    int opcion;
    MATRIZ M3, M4, M5, M6;
    M3 = crearMatriz(M1->filas, M1->columnas);
    M4 = crearMatriz(M1->filas, M1->columnas);
    M5 = crearMatriz(M1->filas, M1->columnas);
    M6 = crearMatriz(M1->filas, M1->columnas);

    do {
        printf("\nMenu\n");
        printf("1. Suma de matrices.\n");
        printf("2. Resta de matrices.\n");
        printf("3. Multiplicacion de matrices.\n");
        printf("4. Matriz transpuesta.\n");
        printf("5. Salir, adiós, jejeje:)\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                M3 = sumaMatriz(M1, M2);
                printf("La suma de las matrices es:\n");
                mostrarM(M3);
                break;
            case 2:
                M4 = restaMatriz(M1, M2);
                printf("La resta de matrices es:\n");
                mostrarM(M4);
                break;
            case 3:
                M5 = multiplicaMatriz(M1, M2);
                printf("La multiplicación de matrices es:\n");
                mostrarM(M5);
                break;
            case 4:
                M6 = transpuestaMatriz(M1);
                printf("La transpuesta de alguna de las matrices es:\n");
                mostrarM(M6);
                break;
            case 5:
                printf("Salir del programa jeje.\n");
                break;
            default:
                printf("Opción no válida, intenta con otra.\n");
        }
    } while (opcion != 5);

    liberarM(M1);
    liberarM(M2);
    liberarM(M3);
    liberarM(M4);
    liberarM(M5);
    liberarM(M6);
}

void darDatos(MATRIZ M1) {
    int i, j, elem;
    printf("Ingrese los datos de la matriz:\n");
    for (i = 0; i < M1->filas; i++) {
        for (j = 0; j < M1->columnas; j++) {
            printf("Dato[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &elem);
            M1 = asignaValor(M1, i, j, elem);
        }
    }
}

void mostrarM(MATRIZ M1) {
    int i, j;
    printf("La matriz es:\n");
    for (i = 0; i < M1->filas; i++) {
        for (j = 0; j < M1->columnas; j++) {
            printf("%d ", obtenValor(M1, i, j));
        }
        printf("\n");
    }
}

void liberarM(MATRIZ M1) {
    int i;
    for (i = 0; i < M1->filas; i++) {
        free(M1->matriz[i]);
    }
    free(M1->matriz);

    manejaMsg(1);
}

void manejaMsg(int msj) {
    char *mensaje[] = { "No hay memoria disponible...\n", "Memoria liberada...\n" };
    printf("%s", mensaje[msj]);
}

