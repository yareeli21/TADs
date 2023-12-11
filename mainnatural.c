#include<stdio.h>
#include "natural.h"
#include <math.h>

void darNatural(int a, int b);
void mostrarNatural(NATURAL c, NATURAL d);

void main(){
    int n1, n2; 
    darNatural(n1, n2);
    
}

void darNatural(int n1, int n2){ 
    NATURAL N1, N2;
//----------------------------------------------------------------
    printf("Da el primer natural\n");
    scanf("%d", &n1);
    while(n1<0){
        printf("Numero no valido. Ingrese un numero natural:\n");
        scanf("%d", &n1);
    }
//-----------------------------------------------------------------------------
/*
    while(n1<0){
	SYSTEM("CLEAR SCREEN");
	printf("Ingresa el primer numero natural mayor o igual a cero\n");
	scanf("%d", &n1);
}
*/
    N1 = crearNatural(n1); 
//----------------------------------------------------------------
    printf("Da el segundo natural\n");
    scanf("%d", &n2);
    while(n2<0){
        printf("Numero no valido. Ingrese un numero natural:\n");
        scanf("%d", &n2);
    }
//----------------------------------------------------------------
    N2 = crearNatural(n2);
    mostrarNatural(N1,N2);

}

void mostrarNatural(NATURAL N1, NATURAL N2){
/*
printf("El numero n1 es: %d\n", N1->numero);
printf("El numero n2 es: %d\n", N2->numero);
*/
    if (esCero(N1)==1){
    printf("El primer natural es cero\n");
} else {
    printf("El primer natural no es cero\n");
}

if (esCero(N2)==1){
    printf("El segundo natural es cero\n");
} else {
    printf("El segundo natural no es cero\n");
}
 printf("El sucesor del primer numero es %d \n", sucesor(N1) );
    printf("El sucesor del segundo numero es %d \n", sucesor(N2) );
if (esMenor(N1,N2)==1){
    printf("El primer natural es menor\n");
} else {
    printf("El segundo natural es menor\n");
}
if (esMenorIgual(N1,N2)==1){
    printf("El primer natural es menor igual que el segundo\n");
} else {
    printf("El segundo natural es menor igual que el primero\n");
}

if (esMayor(N1,N2)==1){
    printf("El primer natural es mayor\n");
} else {
    printf("El segundo natural es mayor\n");
}

if (esMayorIgual(N1,N2)==1){
    printf("El primer natural es mayor igual que el segundo\n");
} else {
    printf("El segundo natural es mayor igual que el primero\n");
}
printf("El presecesor del primer numero es %d \n", predecesor(N1));
printf("El predecesor del segundo numero es %d \n", predecesor(N2));
}