#ifndef _SINTACTICO
#define _SINTACTICO
#include <stack>
#include "lexico.h"
#include "nodos.h"

class Sintactico {
public:
    stack<int> pila;
    Lexico* lex;
    // Tabla simplificada para el ejemplo
    Sintactico(Lexico* l) : lex(l) {
        pila.push(2); // $
        pila.push(0); // Estado inicial
    }

    void analizar() {
        // Aquí va el bucle while que usa la tabla LR
        // En cada REDUCCIÓN (accion < 0), haces un:
        // Nodo* n = new Asignacion(...);
    }
};
#endif