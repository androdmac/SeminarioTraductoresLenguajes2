#ifndef _NODOS
#define _NODOS
#include <iostream>
#include <string>
#include "tablasimbolos.h"

using namespace std;

class Nodo {
public:
    char tipoDato;
    static TablaSimbolos* tabla;
    static string ambito;
    virtual void validaTipos() {}
};

class Expresion : public Nodo {};

class Identificador : public Expresion {
public:
    string nombre;
    Identificador(string n) : nombre(n) {}
    void validaTipos() override {
        tipoDato = tabla->buscaTipo(nombre);
        if (tipoDato == 'v') tabla->errores.push_back("Error: Variable '" + nombre + "' no declarada.");
    }
};

class Suma : public Expresion {
public:
    Expresion *izq, *der;
    Suma(Expresion* i, Expresion* d) : izq(i), der(d) {}
    void validaTipos() override {
        izq->validaTipos();
        der->validaTipos();
        // Regla: int + int = int, cualquier otro caso = float
        if (izq->tipoDato == 'i' && der->tipoDato == 'i') tipoDato = 'i';
        else tipoDato = 'f';
    }
};

class Asignacion : public Nodo {
public:
    string id;
    Expresion* exp;
    Asignacion(string i, Expresion* e) : id(i), exp(e) {}
    void validaTipos() override {
        exp->validaTipos();
        char tVar = tabla->buscaTipo(id);
        if (tVar == 'i' && exp->tipoDato == 'f') {
            tabla->errores.push_back("Error Semantico: Incompatibilidad en '" + id + "'. No se puede asignar float a int.");
        }
    }
};
#endif