#ifndef _natural_
#define _natural_

typedef struct{
   int natural;
}Natural;

typedef Natural * NATURAL;

//OPERACIONES

NATURAL creaNatural(void);
void asignaN(NATURAL N, int n);
int obtenN(NATURAL N);
int esCero(NATURAL N);
NATURAL sucesor(NATURAL N);
int esMenor(NATURAL N1, NATURAL N2);
int esMenorIgual(NATURAL N1, NATURAL N2);
int esMayor(NATURAL N1, NATURAL N2);
int esMayorIgual(NATURAL N1, NATURAL N2);
NATURAL predecesor(NATURAL N);

#endif
