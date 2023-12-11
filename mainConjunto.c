#include <stdio.h>
#include "conjunto.h"
#include <stdlib.h>
void liberarMem(CONJUNTO);
void manejaMsg(int msg);
void darTamanio(int *);
void darElemento(int *);
void mostrar(int pertenece,int vacio,int cardinal);
void darDatos(CONJUNTO,int);
void menu(CONJUNTO,CONJUNTO);
void mostrarConjunto(CONJUNTO C);

void main() {
    int numElem1, numElem2,elemento,per,vacio,car;
    printf("Ingrese el número de elementos del primer conjunto: ");
    darTamanio(&numElem1);
    CONJUNTO C1 = conjuntovacio(numElem1);
    printf("Ingrese los elementos del primer conjunto:\n");
   darDatos(C1,numElem1);

    printf("Ingrese el número de elementos del segundo conjunto: ");
    darTamanio(&numElem2);
    CONJUNTO C2 = conjuntovacio(numElem2);
    printf("Ingrese los elementos del segundo conjunto:\n");
   darDatos(C2,numElem2);
   darElemento(&elemento);
   per=pertenece(C1, elemento);
   vacio=esVacio(C1);
   car=cardinal(C1);
   mostrar(per,vacio,car);
   menu(C1,C2);

}
void darTamanio(int *numElem){
    printf("Ingrese el numero de elementos del conjunto:\n");
    scanf("%d",numElem);
}
void darDatos(CONJUNTO C1,int tamanio){
        for (int i = 0; i <tamanio ; i++) {
        int elem;
        scanf("%d", &elem);
        anadir(C1, elem);
    }
}
void darElemento(int *elem){
  printf("Digite el elemento:\n");
  scanf("%d",elem);
}
void mostrar(int pertenece,int vacio,int cardinal){
    printf("¿El elemento pertenece?\n %d",pertenece);
    printf("\n¿El conjunto es vacio?\n %d",vacio);
    printf("\n¿El cardinal del conjunto?\n %d",cardinal);
}
void menu(CONJUNTO C1, CONJUNTO C2){
  int opcion;
    do {
        printf("\nMenu\n");
        printf("1. Unión de conjuntos\n");
        printf("2. Intersección de conjuntos\n");
        printf("3. Inclusión de conjuntos\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                CONJUNTO unionResult = unir(C1, C2);
                printf("Unión de conjuntos: ");
                mostrarConjunto(unionResult);
                break;
            case 2:
                CONJUNTO interseccionResult = interseccion(C1, C2);
                printf("Intersección de conjuntos: ");
                mostrarConjunto(interseccionResult);
                break;
            case 3:
                if (inclusion(C1, C2)) {
                    printf("El primer conjunto está incluido en el segundo conjunto.\n");
                } else {
                    printf("El primer conjunto no está incluido en el segundo conjunto.\n");
                }
                break;
            case 4:
                printf("Saliendo del programa, adios jejeje.\n");
                break;
            default:
                printf("Opción no válida):, intenta con otra :)\n");
        }
    } while (opcion != 4);

    liberarMem(C1);
    liberarMem(C2);
}
void mostrarConjunto(CONJUNTO C) {
    printf("{ ");
    for (int i = 0; i < C->tamanio; i++) {
        printf("%d ", C->c[i]);
    }
    printf("}\n");
}
void liberarMem(CONJUNTO C) {
    free(C);
    manejaMsg(1);
}
void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
