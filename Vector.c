#include<stdlib.h>
#include<math.h>
#include "vector.h"

void manejaMsg(int);
void liberarMem(VECTOR);
VECTOR crearVector(int elem){
   VECTOR V;
   V = (VECTOR)malloc(sizeof(VECTOR));
   V->componente = (int*)malloc(elem*sizeof(int));
   V->tam= elem;
   if( V == NULL && V->componente ==NULL){
        manejaMsg(0);
        exit(0);
   }
   return V;
}

void asignaComponente(VECTOR V,  int valor, int elem){

    V -> componente[elem] = valor;
}

int obtenComponente(VECTOR V, int elem){
   return ( V -> componente[elem]);
}

int tamano(VECTOR V){
    return V->tam ;
}

VECTOR suma(VECTOR V1, VECTOR V2){
    int i;
      VECTOR V3 =  crearVector(tamano(V1));
      for(i=0;i<tamano(V1);i++){
        asignaComponente( V3, obtenComponente(V1,i) + obtenComponente(V2,i), i);

      }
      
       return V3;
}

VECTOR resta(VECTOR V1, VECTOR V2){
    int i;
      VECTOR V4 =  crearVector(tamano(V1));
      for(i=0;i<tamano(V1);i++){
        asignaComponente( V4, obtenComponente(V1,i) - obtenComponente(V2,i), i);

      }
      
       return V4;
}

int productopunto(VECTOR V1, VECTOR V2){
    int i,mul;
        mul=0;
      for(i=0;i<tamano(V1);i++){
        mul += obtenComponente(V1,i) * obtenComponente(V2,i);

      }
      
       return mul;
}
int mayor(int elem, int elem2){

       if(elem>elem2)
      return 0;
      else{
            return 1;
      }
}


VECTOR ordenaVector(VECTOR V1){
    int i, j, temp,n;
    n= tamano(V1);
     for (j=0; j < n; j++){
           for (i=0; i < n-1; i++){
                 if(mayor(V1->componente[ i ],V1->componente [ i+1])==0){
                      temp = V1->componente[ i ];
                      V1->componente[ i ] = V1->componente[ i+1];
                      V1->componente [ i+1] = temp;
                 }
            }
     }

     return V1;
}
