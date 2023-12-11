#include <stdio.h>
#include<stdlib.h>
#include "matriz.h"

void manejaMsg(int);

MATRIZ crearMatriz(int f,int c){
    MATRIZ M;
    int i;
    M=(MATRIZ)malloc(sizeof(Matriz));
    M->filas=f;
    M->columnas=c;
   M->matriz=(int**) malloc(f*sizeof(int*));
   if(M->matriz==NULL){
       manejaMsg(0);
       exit(0);
      }
    for(i=0;i<f;i++){
        M->matriz[i]=(int*)malloc(c*sizeof(int));
    }
    return M;
}
int obtenValor(MATRIZ M, int f, int c){
return M->matriz[f][c];
}
MATRIZ asignaValor(MATRIZ M, int f, int c, int elem){
 M->matriz[f][c]=elem;
 return M;
}
int tamFilas(MATRIZ M){
   int f;
   printf("Filas?\n");
   scanf("%d",&f);
   f=M->filas;
   return f;
}
int tamColum(MATRIZ M){
   int c;
   printf("Columnas?\n");
   scanf("%d",&c);
   c=M->columnas;
   return c;
}
MATRIZ sumaMatriz(MATRIZ M1, MATRIZ M2){
 int i,j,v1,v2;
    if(M1->filas !=M2->filas && M1->columnas != M2->columnas){
        printf("No se puede hacer la suma porque tienen dimensiones diferentes las matrices\n");
    }
    else{
        MATRIZ M3=crearMatriz(M1->filas,M1->columnas);
        for(i=0; i<M1->filas;i++){
            for(j=0;j<M1->columnas;j++){
            v1=obtenValor(M1,i,j);
            v2=obtenValor(M2,i,j);
            M3=asignaValor(M3,i,j,v1+v2);
            }
        }
        return M3;
    }
}
MATRIZ restaMatriz(MATRIZ M1, MATRIZ M2){
 int i,j,v1,v2;
    if(M1->filas !=M2->filas && M1->columnas != M2->columnas){
        printf("No se puede hacer la suma porque tienen dimensiones diferentes las matrices\n");
    }
    else{
        MATRIZ M3=crearMatriz(M1->filas,M1->columnas);
        for(i=0; i<M1->filas;i++){
            for(j=0;j<M1->columnas;j++){
            v1=obtenValor(M1,i,j);
            v2=obtenValor(M2,i,j);
            M3=asignaValor(M3,i,j,v1-v2);
            }
        }
        return M3;
    }
}
MATRIZ multiplicaMatriz(MATRIZ M1,MATRIZ M2){
int i,j,suma,k;
    if(M1->columnas != M2->filas){
        printf("No se puede hacer la multiplicacion de matrices.\n");
    }
    else{
        MATRIZ M3=crearMatriz(M1->filas,M2->columnas);
        for(i=0;i< M1->filas;i++){
            for(j=0;j<M2->columnas;j++){
                suma=0;
                for(k=0;k<M1->columnas;k++){
                    suma+=obtenValor(M1,i,k)*obtenValor(M2,k,j);
                }
                M3=asignaValor(M3,i,j,suma);
            }
        }
        return M3;
    }
}

MATRIZ transpuestaMatriz(MATRIZ M1){
    MATRIZ M2=crearMatriz(M1->filas,M1->columnas);
    int i,j,valor;
    for(i=0;i<M1->filas;i++){
        for(j=0;j<M1->columnas;j++){
           valor=obtenValor(M1,i,j);
           M2=asignaValor(M2,j,i,valor);
        }
    }
    return M2;
}
