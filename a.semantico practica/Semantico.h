#ifndef SEMANTICO_H
#define SEMANTICO_H

#include "nodo.h"
#include "TablaSimbolos.h"
#include <list>
#include <string>
#include <iostream>

class Semantico {
private:
    std::list<std::string> listaErrores;
    TablaSimbolos* tablaSimbolos;
    Nodo* arbol;

public:
    Semantico() {
        // Sincroniza la tabla local con el puntero estático de los Nodos
        Nodo::tablaSimbolos = tablaSimbolos = new TablaSimbolos(&listaErrores);
    }

    ~Semantico() {
        delete tablaSimbolos;
    }

    void analiza(Nodo *arbol) {
        this->arbol = arbol;
        if (arbol != nullptr) {
            arbol->validaTipos(); // Lanza la recursión en el árbol sintáctico
        }

        tablaSimbolos->muestra();
        muestraErrores();
    }

    void muestraErrores() {
        std::cout << "\n======= ERRORES SEMANTICOS RESTRICCIONES =======" << std::endl;
        if (listaErrores.empty()) {
            std::cout << "0 Errores detectados. Analisis Semantico correcto." << std::endl;
        } else {
            for (std::string const& err : listaErrores) {
                std::cout << err << std::endl;
            }
        }
    }
};

#endif // SEMANTICO_H