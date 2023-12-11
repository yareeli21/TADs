#ifndef conjunto_h
#define conjunto_h

typedef struct {
    int *c;
    int tamanio;
} Conjunto;

typedef Conjunto *CONJUNTO;

CONJUNTO conjuntovacio(int n);
void anadir(CONJUNTO C, int elemento);
void retirar(CONJUNTO C, int elemento);
int pertenece(CONJUNTO C, int elemento);
int esVacio(CONJUNTO C);
int cardinal(CONJUNTO C);
CONJUNTO unir(CONJUNTO C1, CONJUNTO C2);
CONJUNTO interseccion(CONJUNTO C1, CONJUNTO C2);
int inclusion(CONJUNTO C1, CONJUNTO C2);

#endif

