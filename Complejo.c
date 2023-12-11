#include<stdlib.h>
#include<math.h>

#include "complejo.h"



void manejaMsg(int);



COMPLEJO crearComplejo(void){

   COMPLEJO C;

   C = (COMPLEJO)malloc(sizeof(Complejo));

   if( C == NULL){

        manejaMsg(0);

        exit(0);

   }

}

void asignaReal(COMPLEJO C,  float r){

    C -> real = r;

}

void asignaImaginario(COMPLEJO C, float i){

      C -> imaginario = i;

}



float obtenReal(COMPLEJO C){

       return ( C -> real);

}



float obtenImaginario(COMPLEJO C){

      return ( C -> imaginario);

}



COMPLEJO suma(COMPLEJO C1, COMPLEJO C2){

      COMPLEJO C3 =  crearComplejo();

      asignaReal( C3, obtenReal(C1) + obtenReal(C2) );

      asignaImaginario( C3, obtenImaginario(C1) + obtenImaginario(C2) );

       return C3;

}
COMPLEJO resta(COMPLEJO C1, COMPLEJO C2){

      COMPLEJO C3 =  crearComplejo();

      asignaReal( C3, obtenReal(C1) - obtenReal(C2) );

      asignaImaginario( C3, obtenImaginario(C1) - obtenImaginario(C2) );

       return C3;

}
COMPLEJO producto(float x, COMPLEJO C1){
    
    COMPLEJO C3=crearComplejo();
    asignaReal(C3, x*obtenReal(C1));
    asignaImaginario(C3, x*obtenImaginario(C1));
    
    return C3;
}
float modulo(COMPLEJO C1){

   float x;
   x=sqrt(pow(obtenReal(C1),2)+pow(obtenImaginario(C1),2));
   
   return x;
}
COMPLEJO complemento(COMPLEJO C1){
    COMPLEJO C2=crearComplejo();
    asignaReal(C2,obtenReal(C1));
    asignaImaginario(C2,-obtenImaginario(C1));
    return C2;
}

COMPLEJO multiplicacion(COMPLEJO C1, COMPLEJO C2){
    COMPLEJO C3=crearComplejo();
    asignaReal(C3,obtenReal(C1)*obtenReal(C2));
    asignaImaginario(C3,obtenImaginario(C1)*obtenReal(C2));
    return C3;
}
COMPLEJO division(COMPLEJO C1, COMPLEJO C2){
    COMPLEJO C3=crearComplejo();
    asignaReal(C3,obtenReal(C1)/obtenReal(C2));
    asignaImaginario(C3,obtenImaginario(C1)/obtenReal(C2));
    return C3;
}




