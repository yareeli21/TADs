#include<stdio.h>
#include<stdlib.h>

#include "complejo.h"


void manejaMsg(int);

void darComplejos(COMPLEJO, COMPLEJO,float*);

void mostrarComplejo(COMPLEJO);

void liberarMem(COMPLEJO, COMPLEJO, COMPLEJO, COMPLEJO, COMPLEJO, COMPLEJO);

void menu(COMPLEJO C1, COMPLEJO C2);

void main( ){

      COMPLEJO C1, C2, C3, C4, C5,C6,C7,C8;
      float pro,x;

      C1=crearComplejo();

      C2=crearComplejo();

       darComplejos(C1, C2,&pro);
       printf("Complejo 1:\n");
       mostrarComplejo(C1);
       printf("Complejo 2:\n");
       mostrarComplejo(C2);

      menu(C1,C2);
}

void menu(COMPLEJO C1, COMPLEJO C2){
   int opcion;
   COMPLEJO C3,C4,C5,C6;
   C3=crearComplejo();
   C4=crearComplejo();
   C5=crearComplejo();
   C6=crearComplejo();
   do{
       printf("\nMenu\n");
       printf("1. Suma de complejos.\n");
       printf("2. Resta de complejos.\n");
       printf("3. Multiplicacion de complejos.\n");
       printf("4. Division de complejos.\n");
       printf("5. Salir.\n");
       printf("Selecciona una opcion: \n");
       scanf("%d",&opcion);

       switch(opcion){
           case 1: C3=suma(C1,C2);
           printf("La suma es: \n");
           mostrarComplejo(C3);
           break;
           case 2: C4=resta(C1,C2);
           printf("La resta es:\n");
           mostrarComplejo(C4);
           break;
           case 3: C5=multiplicacion(C1,C2);
           printf("La multiplicacion es:\n");
           mostrarComplejo(C5);
           break;
           case 4: C6=division(C1,C2);
           printf("La division es:\n");
           mostrarComplejo(C6);
           break;
           case 5: printf("Se termina el programa jeje, adios:)\n");
           default:
               printf("Caso no valido, selecciona otra opcion\n");
    }

   }while(opcion!=5);
     liberarMem(C1, C2, C3,C4,C5,C6);
}



void darComplejos( COMPLEJO C1, COMPLEJO C2,float *x){

     float r, i;
     
     

     printf("Dar la parte real del complejo 1\n");

     scanf("%f", &r);

     asignaReal(C1, r);

     printf("Dar la parte imaginario del complejo 1\n");

     scanf("%f", &i); 

     asignaImaginario(C1, i);

    printf("Dar la parte real del complejo 2\n");

     scanf("%f", &r);

     asignaReal(C2, r);

     printf("Dar la parte imaginario del complejo 2\n");

     scanf("%f", &i); 

     asignaImaginario(C2, i);
     
     printf("Dar el escalar\n");
     scanf("%f",x);

}



void mostrarComplejo(COMPLEJO C1){

    printf("%f + %fi \n", obtenReal(C1), obtenImaginario(C1) );

}




void manejaMsg(int msg){

     char * mensajes[] = {"No hay memoria disponible ...\n"};

     printf("%s", mensajes[msg] );

}
void liberarMem(COMPLEJO C1, COMPLEJO C2, COMPLEJO C3, COMPLEJO C4, COMPLEJO C5, COMPLEJO C6){
    free(C1);
    free(C2); 
    free(C3);
    free(C4);
    free(C5);
    free(C6);
    manejaMsg(1);
}




