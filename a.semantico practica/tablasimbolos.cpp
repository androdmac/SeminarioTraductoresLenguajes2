#include "TablaSimbolos.h"
#include "nodo.h"
#include <iostream>

TablaSimbolos::TablaSimbolos(std::list<std::string>* listaErrores) {
    this->listaErrores = listaErrores;
}

void TablaSimbolos::agrega(ElementoTabla *elemento) {
    tabla.push_back(elemento);
}

bool TablaSimbolos::varGlobalDefinida(std::string simbolo) {
    for (auto const& elem : tabla) {
        if (elem->nombre == simbolo && elem->ambito == "") return true;
    }
    return false;
}

bool TablaSimbolos::varLocalDefinida(std::string variable, std::string funcion) {
    for (auto const& elem : tabla) {
        if (elem->nombre == variable && elem->ambito == funcion) return true;
    }
    return false;
}

bool TablaSimbolos::funcionDefinida(std::string simbolo) {
    // Lógica similar para validar redefinición de funciones
    return false;
}

// 1. COMPLETADO: Agrega DefVar controlando listas encadenadas y redefiniciones
void TablaSimbolos::agrega(DefVar *defVar) {
    char tipo = defVar->tipo->dimeTipo();
    Identificador *p = defVar->listaVar;

    while (p != nullptr) {
        if (Nodo::ambito == "") { // Ámbito Global
            if (varGlobalDefinida(p->simbolo)) {
                listaErrores->push_back("Error: variable global \"" + p->simbolo + "\" redefinida");
            } else {
                ElementoTabla *elem = new Variable(tipo, p->simbolo, Nodo::ambito);
                agrega(elem);
            }
        } else { // Ámbito Local
            if (varLocalDefinida(p->simbolo, Nodo::ambito)) {
                listaErrores->push_back("Error: variable local \"" + p->simbolo + "\" redefinida");
            } else {
                ElementoTabla *elem = new Variable(tipo, p->simbolo, Nodo::ambito);
                agrega(elem);
            }
        }
        p = p->sig; // Avanzar por si declararon: int a, b, c;
    }
}

// 2. COMPLETADO: Agrega DefFunc
void TablaSimbolos::agrega(DefFunc *defFunc) {
    char tipo = defFunc->tipo->dimeTipo();
    std::string nombreFunc = defFunc->id->simbolo;
    
    ElementoTabla *elem = new ElementoTabla(tipo, nombreFunc, "FUNCION");
    agrega(elem);
}

// 3. COMPLETADO: Agrega Parametros
void TablaSimbolos::agrega(Parametro *parametro) {
    char tipo = parametro->tipo->dimeTipo();
    std::string nombreParam = parametro->id->simbolo;

    if (varLocalDefinida(nombreParam, Nodo::ambito)) {
        listaErrores->push_back("Error: parametro \"" + nombreParam + "\" redefinido en la funcion " + Nodo::ambito);
    } else {
        ElementoTabla *elem = new Variable(tipo, nombreParam, Nodo::ambito);
        agrega(elem);
    }
}

void TablaSimbolos::muestra() {
    std::cout << "\n======= CONTENIDO DE LA TABLA DE SIMBOLOS =======" << std::endl;
    for (auto const& elem : tabla) {
        std::cout << "ID: " << elem->nombre << "\tTipo: " << elem->tipo << "\tAmbito: " << (elem->ambito == "" ? "global" : elem->ambito) << std::endl;
    }
}