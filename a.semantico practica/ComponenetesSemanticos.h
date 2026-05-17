#ifndef _COMPONENTES_SEMANTICOS_H
#define _COMPONENTES_SEMANTICOS_H

#include "Nodo.h"
#include "TablaSimbolos.cpp"

// Clase Tipo: Convierte cadenas a caracteres de tipo
class Tipo : public Nodo {
public:
    char dimeTipo() {
        if (simbolo.compare("int") == 0) return 'i';
        if (simbolo.compare("float") == 0) return 'f';
        if (simbolo.compare("string") == 0) return 's';
        if (simbolo.compare("void") == 0) return 'v';
        return 'v';
    }

    // En la clase Tipo (que hereda de Nodo)
char dimeTipo() {
    if (simbolo.compare("int") == 0) return 'i';
    if (simbolo.compare("float") == 0) return 'f';
    if (simbolo.compare("string") == 0) return 's';
    if (simbolo.compare("void") == 0) return 'v';
    return 'v';
}
};

// Clase DefVar: Validación de definición de variables
class DefVar : public Nodo {
public:
    Tipo *tipo;
    class Identificador *listaVar; // Suponiendo que Identificador hereda de Nodo

    void validaTipos() override {
        tipoDato = tipo->dimeTipo();
        // El método de la tabla se encarga de recorrer la lista de variables (a, b, c...)
        tablaSimbolos->agrega(this);
    }

    // En la clase DefVar (que hereda de Nodo)
void validaTipos() override {
    tipoDato = tipo->dimeTipo();
    tablaSimbolos->agrega(this);
}
};

// Ejemplo de validación para una Suma (Expresión)
class Suma : public Nodo {
public:
    Nodo *izq, *der;

    void validaTipos() override {
        izq->validaTipos();
        der->validaTipos();

        // Regla: Solo sumar numéricos
        if (izq->tipoDato == 'i' && der->tipoDato == 'i') {
            tipoDato = 'i';
        } else if ((izq->tipoDato == 'i' || izq->tipoDato == 'f') && 
                   (der->tipoDato == 'i' || der->tipoDato == 'f')) {
            tipoDato = 'f';
        } else {
            tipoDato = 'v';
            Nodo::tablaSimbolos->listaErrores->push_back("Error: Tipos incompatibles en operacion Suma");
        }
    }
};

#endif