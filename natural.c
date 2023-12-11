#include<stdio.h>
#include "natural.h"
#include<stdlib.h>

void manejaMsg(int);

NATURAL creaNatural(void){
 NATURAL N;
   N=(NATURAL)malloc(sizeof(Natural));
   if(N==NULL){
      manejaMsg(0);
      exit(0);
   }
   return N;
}
void asignaN(NATURAL N,  int n){
    N -> natural = n;
}

int obtenN(NATURAL N){
       return ( N -> natural);
}
int esCero(NATURAL N){
   if((obtenN(N))==0){
      return 1;
   }
   else{
      return 0;
   }
}

NATURAL sucesor(NATURAL N1){
   NATURAL N2=creaNatural();
   asignaN(N2, obtenN(N1)+1);
   return N2;
}
int esMenor(NATURAL N1, NATURAL N2){
  if(obtenN(N1)<obtenN(N2)){
    return 1;
  }
  else{
     return 0;
  }
}
int esMenorIgual(NATURAL N1, NATURAL N2){
  if(obtenN(N1)<=obtenN(N2)){
      return 1;
  }
  else{
      return 0;
  }
}
int esMayor(NATURAL N1, NATURAL N2){
    if(obtenN(N1)>obtenN(N2)){
       return 1;
    }
    else{
        return 0;
    }
}
int esMayorIgual(NATURAL N1, NATURAL N2){
  if(obtenN(N1)>=obtenN(N2)){
      return 1;
  }
  else{
      return 0;
  }
}
NATURAL predecesor(NATURAL N1){
   NATURAL N2=creaNatural();
   asignaN(N2, obtenN(N1)-1);
   return N2;
}
