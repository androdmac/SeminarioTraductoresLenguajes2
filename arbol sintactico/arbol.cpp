#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ============================================================
// 1. DEFINICIÓN DEL NODO DEL ÁRBOL (AST)
// ============================================================
struct Nodo {
    string tipo;
    string valor;
    vector<Nodo*> hijos;

    Nodo(string t, string v = "") : tipo(t), valor(v) {}

    // Método para imprimir el árbol con indentación para GitHub
    void imprimir(int nivel = 0) {
        for (int i = 0; i < nivel; i++) cout << "  ";
        cout << "|-- " << tipo << (valor != "" ? ": " + valor : "") << endl;
        for (auto hijo : hijos) {
            hijo->imprimir(nivel + 1);
        }
    }
};

// ============================================================
// 2. FUNCIONES AUXILIARES PARA CONSTRUIR RAMAS
// ============================================================

// Crea un nodo para declaraciones: int a;
Nodo* crearDeclaracion(string tipoVar, string id) {
    Nodo* decl = new Nodo("Declaracion");
    decl->hijos.push_back(new Nodo("Tipo", tipoVar));
    decl->hijos.push_back(new Nodo("ID", id));
    return decl;
}

// Crea un nodo para la suma: a + b
Nodo* crearOperacion(string op, Nodo* izq, Nodo* der) {
    Nodo* operacion = new Nodo("Operacion", op);
    operacion->hijos.push_back(izq);
    operacion->hijos.push_back(der);
    return operacion;
}

// ============================================================
// 3. CONSTRUCCIÓN DEL ÁRBOL ESPECÍFICO DE LA TAREA
// ============================================================
int main() {
    // Nodo Raíz del Programa
    Nodo* raiz = new Nodo("Programa");

    // --- Parte 1: int a; (Global) ---
    raiz->hijos.push_back(crearDeclaracion("int", "a"));

    // --- Parte 2: int suma(int a, int b) ---
    Nodo* funcionSuma = new Nodo("DefinicionFuncion", "suma");
    funcionSuma->hijos.push_back(new Nodo("TipoRetorno", "int"));
    
    Nodo* paramsSuma = new Nodo("Parametros");
    paramsSuma->hijos.push_back(crearDeclaracion("int", "a"));
    paramsSuma->hijos.push_back(crearDeclaracion("int", "b"));
    funcionSuma->hijos.push_back(paramsSuma);

    Nodo* cuerpoSuma = new Nodo("Cuerpo");
    Nodo* ret = new Nodo("Return");
    ret->hijos.push_back(crearOperacion("+", new Nodo("ID", "a"), new Nodo("ID", "b")));
    cuerpoSuma->hijos.push_back(ret);
    funcionSuma->hijos.push_back(cuerpoSuma);

    raiz->hijos.push_back(funcionSuma);

    // --- Parte 3: int main() ---
    Nodo* funcionMain = new Nodo("DefinicionFuncion", "main");
    funcionMain->hijos.push_back(new Nodo("TipoRetorno", "int"));

    Nodo* cuerpoMain = new Nodo("Cuerpo");
    cuerpoMain->hijos.push_back(crearDeclaracion("float", "a"));
    cuerpoMain->hijos.push_back(crearDeclaracion("int", "b"));
    cuerpoMain->hijos.push_back(crearDeclaracion("int", "c"));

    // c = a + b;
    Nodo* asign1 = new Nodo("Asignacion", "=");
    asign1->hijos.push_back(new Nodo("ID", "c"));
    asign1->hijos.push_back(crearOperacion("+", new Nodo("ID", "a"), new Nodo("ID", "b")));
    cuerpoMain->hijos.push_back(asign1);

    // c = suma(8, 9);
    Nodo* asign2 = new Nodo("Asignacion", "=");
    asign2->hijos.push_back(new Nodo("ID", "c"));
    Nodo* llamada = new Nodo("LlamadaFuncion", "suma");
    llamada->hijos.push_back(new Nodo("Literal", "8"));
    llamada->hijos.push_back(new Nodo("Literal", "9"));
    asign2->hijos.push_back(llamada);
    cuerpoMain->hijos.push_back(asign2);

    funcionMain->hijos.push_back(cuerpoMain);
    raiz->hijos.push_back(funcionMain);

    // ============================================================
    // 4. SALIDA DE RESULTADOS
    // ============================================================
    cout << "ARBOL SINTACTICO GENERADO:" << endl;
    cout << "==========================" << endl;
    raiz->imprimir();

    return 0;
}