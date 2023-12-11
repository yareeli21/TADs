#include<stdio.h>
#include "natural.h"
#include<stdlib.h>

void manejaMsg(int);

void liberarMem(NATURAL,NATURAL,NATURAL,NATURAL);
void darNatural(NATURAL,NATURAL);
void mostrarNatural(NATURAL,NATURAL,int,NATURAL,int,int,int,int,NATURAL);

void main(){
   NATURAL N1,N2,N3,N4; 
   int cero, may, maI, men, meI;
   N1=creaNatural();
   N2=creaNatural();
   N3=creaNatural();
   darNatural(N1,N2);
   cero=esCero(N1);
   N3=sucesor(N1);
   men=esMenor(N1,N2);
   meI=esMenorIgual(N1,N2);
   may=esMayor(N1,N2);
   maI=esMayorIgual(N1,N2);
   N4=predecesor(N1);
   mostrarNatural(N1,N2,cero,N3,men,meI,may,maI,N3);  
   liberarMem(N1,N2,N3,N4);
}

void darNatural(NATURAL N1,NATURAL N2){
    int n;
    
    printf("Dar el primer numero natural\n");
    scanf("%d",&n);
    asignaN(N1,n);
    printf("Dar el segundo numero natural\n");
    scanf("%d",&n);
    asignaN(N2,n);
}
void mostrarNatural(NATURAL N1, NATURAL N2, int cero, NATURAL N3,int men, int meI, int may, int maI, NATURAL N4){
  printf("Natural 1 %d\n",obtenN(N1));
  printf("Natural 2 %d\n",obtenN(N2));
  printf("¿Es cero? (1=V, 0=F) %d\n",cero);
  printf("Sucesor: %d\n",obtenN(N3));
  printf("¿Es menor? (1=V, 0=F): %d\n",men);
  printf("¿Es menor o igual? (1=V, 0=F): %d\n",meI);
  printf("¿Es mayor? (1=V, 0=F): %d\n",may);
  printf("¿Es mayor o igual? (1=V, 0=F): %d\n",maI);
  printf("Predecesor: %d\n",obtenN(N4));
  
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
void liberarMem(NATURAL N1, NATURAL N2, NATURAL N3, NATURAL N4){
    free(N1);
    free(N2);
    free(N3);
    free(N4);
    manejaMsg(1);
}
