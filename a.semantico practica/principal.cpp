#include <iostream>
#include "Semantico.h"
#include "nodo.h"

int main() {
    std::cout << "Iniciando Simulacion Analizador Semantico..." << std::endl;

    // Generamos un escenario de prueba (Variable local redefinida)
    DefVar* variable1 = new DefVar();
    Tipo* tInt = new Tipo(); tInt->simbolo = "int";
    Identificador* idX1 = new Identificador(); idX1->simbolo = "x"; idX1->sig = nullptr;
    variable1->tipo = tInt;
    variable1->listaVar = idX1;

    DefVar* variable2 = new DefVar();
    Identificador* idX2 = new Identificador(); idX2->simbolo = "x"; idX2->sig = nullptr;
    variable2->tipo = tInt;
    variable2->listaVar = idX2;

    variable1->sig = variable2;
    Nodo::ambito = "main"; 

    // Ejecución del análisis
    Semantico semantico;
    semantico.analiza(variable1);

    // Liberación básica de memoria
    delete variable1; delete variable2; delete tInt; delete idX1; delete idX2;
    return 0;
}