#include <iostream>
#include "lexico.h"
#include "sintactico.h"
#include "semantico.h"
#include "nodos.h"

// Inicialización de variables estáticas
TablaSimbolos* Nodo::tabla = new TablaSimbolos();
string Nodo::ambito = "global";

int main() {
    cout << "--- PROYECTO FINAL: TRADUCTOR ---" << endl;

    // 1. Fase Global
    Nodo::tabla->agrega("a", 'i', "global");

    // 2. Simulando entrada al ambito local de 'main'
    Nodo::ambito = "main";
    Nodo::tabla->agrega("a", 'f', "main");
    Nodo::tabla->agrega("b", 'i', "main");
    Nodo::tabla->agrega("c", 'i', "main");

    // 3. Simulamos que el Sintactico construyó este árbol de: c = a + b;
    // 'a' es float (local), 'b' es int (local). Suma = float.
    Expresion* idA = new Identificador("a");
    Expresion* idB = new Identificador("b");
    Suma* suma = new Suma(idA, idB);
    Asignacion* asig = new Asignacion("c", suma);

    // 4. Analizador Semántico entra en acción
    Semantico sem;
    sem.analizar(asig);

    // 5. Mostrar Resultados
    if (Nodo::tabla->errores.empty()) {
        cout << "Resultado: Codigo Semantico Valido." << endl;
    } else {
        cout << "\nERRORES DETECTADOS:" << endl;
        for (string err : Nodo::tabla->errores) {
            cout << ">> " << err << endl;
        }
    }

    return 0;
}