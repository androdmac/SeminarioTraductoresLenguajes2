#ifndef _SEMANTICO
#define _SEMANTICO
#include "nodos.h"

class Semantico {
public:
    void analizar(Nodo* raiz) {
        if (raiz) raiz->validaTipos();
    }
};
#endif