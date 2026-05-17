#include "nodo.h"
#include "TablaSimbolos.h"

// Inicialización de variables estáticas obligatorias
TablaSimbolos* Nodo::tablaSimbolos = nullptr;
std::string Nodo::ambito = "";

// Constructor base
Nodo::Nodo() : tipoDato('v'), sig(nullptr) {}

// Implementación de métodos virtuales de validación
void Nodo::validaTipos() { 
    tipoDato = 'v';  
    if (sig != nullptr) sig->validaTipos();  
}

char Tipo::dimeTipo() { 
    if (simbolo.compare("int") == 0) return 'i'; 
    if (simbolo.compare("float") == 0) return 'f'; 
    if (simbolo.compare("string") == 0) return 's'; 
    if (simbolo.compare("void") == 0) return 'v'; 
    return 'v';
}

void DefVar::validaTipos() {
    tipoDato = tipo->dimeTipo();
    if (tablaSimbolos != nullptr) {
        tablaSimbolos->agrega(this); 
    }
    if (sig != nullptr) sig->validaTipos();
}

void DefFunc::validaTipos() {
    std::string viejoAmbito = Nodo::ambito;
    Nodo::ambito = id->simbolo;
    
    if (tablaSimbolos != nullptr) {
        tablaSimbolos->agrega(this);
    }
    
    if (parametros != nullptr) parametros->validaTipos();
    if (bloque != nullptr) bloque->validaTipos();
    
    Nodo::ambito = viejoAmbito;
    if (sig != nullptr) sig->validaTipos();
}

void Parametro::validaTipos() {
    if (tablaSimbolos != nullptr) {
        tablaSimbolos->agrega(this);
    }
    if (sig != nullptr) sig->validaTipos();
}

void Suma::validaTipos() {
    if (izq != nullptr) izq->validaTipos();
    if (der != nullptr) der->validaTipos();

    if (izq != nullptr && der != nullptr) {
        if (izq->tipoDato == 'i' && izq->tipoDato == der->tipoDato) {
            tipoDato = 'i';
        } else if (izq->tipoDato == 'f' && der->tipoDato == 'f') {
            tipoDato = 'f';
        } else {
            tipoDato = 'v';
        }
    }
    if (sig != nullptr) sig->validaTipos();
}