#include<stdio.h>
#ifndef  _vector_
#define  _vector_

typedef struct{
   int *componente;
   int tam;
}vector;

typedef vector * VECTOR;

// operaciones
VECTOR crearVector(int);
void asignaComponente(VECTOR V, int valor, int elem);
int obtenComponente(VECTOR V, int elem);
int tamano(VECTOR);
VECTOR suma(VECTOR, VECTOR);
VECTOR resta(VECTOR, VECTOR);
int productopunto(VECTOR, VECTOR);
int mayor(int, int);
VECTOR ordenaVector(VECTOR);
#endif
