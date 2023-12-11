#include<stdio.h>
#include "vector.h"
#include<stdlib.h>

void manejaMsg(int);
void darVectores(VECTOR, VECTOR, int);
void mostrarVector(VECTOR,VECTOR,VECTOR,int);
void liberarMem(VECTOR);
void gram(int);

void main( ){
   int c,d,tam, pro,i,j;
      VECTOR V1, V2,V3,V4;
      printf("Indique el valor de la dimesion que se trabajara R2, R3, etc..2\n");
      scanf("%d", &c);
      V1=crearVector(c);
      V2=crearVector(c);
      tam= tamano(V1);
      darVectores(V1, V2,c);
      V3=crearVector(tam);
      V4=crearVector(tam);
      
       
      
      
     
    int op;
    while(op!=4){
    printf("Menu\n");
    printf("1.Suma de vectores +\n");
    printf("2.Resta de vectores -\n");
    printf("3.Producto de punto de vectores *\n");
    printf("4.Ordenar vector /\n");
    printf("5. Salir\n");
    printf("Seleccionar la opcion\n");
    scanf("%d",&op);

    if(op==1){
        V3=suma(V1,V2);
        printf("La suma del Vector 1 y Vector 2:\n");
        mostrarVector(V1,V2,V3,c);
        


    }else 
    if(op==2){
        V4=resta(V1,V2); 
        printf("La resta del Vector 1 y Vector 2:\n"); 
        mostrarVector(V1,V2,V4,c);

        }else
        if(op==3){
        printf("Vector 1: (");
        for(i=0; i<c;i++){
        printf("%d,", obtenComponente(V1,i));
        }
        printf(")\n");

        printf("Vector 2: (");
        for(j=0; j<c;j++){
             printf("%d,", obtenComponente(V2,j));
            }
        printf(")\n");
        pro= productopunto(V1,V2);
        printf("El producto punto del Vector 1 y Vector 2: %d\n", pro);

        
        }
        else
            if(op==4){
            printf("Vector 1 sin ordenar: (");
            for(i=0; i<c;i++){
            printf("%d,", obtenComponente(V1,i));
            }
            printf(")\n");
               V1= ordenaVector(V1);
               printf("Vector 1 ORDENADO: (");
               for(i=0; i<c;i++){
                 printf("%d,", obtenComponente(V1,i));
            }
            printf(")\n");

        
            }else{
                exit(0);
                 liberarMem(V1);
                 liberarMem(V2);
                 liberarMem(V3);
                 liberarMem(V4);

            }
        
      
      
      

        }   
}


   


void darVectores( VECTOR V1, VECTOR V2, int c){
     int r, i,j,s;
    
     for(i=0; i<c;i++){
     printf("Dar componente %d del vector 1\n", i+1);
     scanf("%d", &r);
     asignaComponente(V1, r,i);
     }
     for(j=0;j<c;j++){
      printf("Dar componente %d del vector 2\n", j+1);
     scanf("%d", &s); 
     asignaComponente(V2, s,j);
     }
    
}


void mostrarVector(VECTOR V1,VECTOR V2,VECTOR V3,int c){
     int r, i,j;
      printf("Vector 1: (");
     for(i=0; i<c;i++){
      printf("%d,", obtenComponente(V1,i));
     }
     printf(")\n");

      printf("Vector 2: (");
     for(j=0; j<c;j++){
      printf("%d,", obtenComponente(V2,j));
     }
     printf(")\n");

   printf("El resultado de la operacion entre el Vector 1 y Vector 2: (");
     for(j=0; j<c;j++){
      printf("%d,", obtenComponente(V3,j));
     }
     printf(")\n"); 


}
     


void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . .\n","Se ha liberado la memoria . . .  \n"};
     printf("%s", mensajes[msg] );
}

void liberarMem(VECTOR V1){
    free(V1);
    //free(F5);
    manejaMsg(1);
}
