#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Estructura para la Tabla de Símbolos
struct Simbolo {
    string nombre;
    string tipo;
    string categoria; // "variable" o "funcion"
};

// Clase del Analizador Semántico
class AnalizadorSemantico {
public:
    unordered_map<string, Simbolo> tablaSimbolos;

    void insertar(string nombre, string tipo, string cat) {
        tablaSimbolos[nombre] = {nombre, tipo, cat};
    }

    void validarAsignacion(string id, string tipoExpresion) {
        if (tablaSimbolos.find(id) == tablaSimbolos.end()) {
            cout << ">>> ERROR SEMANTICO: Variable '" << id << "' no declarada." << endl;
        } else if (tablaSimbolos[id].tipo == "int" && tipoExpresion == "float") {
            cout << ">>> ADVERTENCIA: Posible perdida de precision al asignar float a int en '" << id << "'." << endl;
        }
    }

    void validarLlamada(string nombreFunc, vector<string> tiposArgs) {
        if (tablaSimbolos.find(nombreFunc) == tablaSimbolos.end()) {
            cout << ">>> ERROR SEMANTICO: La funcion '" << nombreFunc << "' no ha sido declarada." << endl;
        } else {
            // Ejemplo de validación de tipos de argumentos
            if (nombreFunc == "suma") {
                for (string t : tiposArgs) {
                    if (t == "float") {
                        cout << ">>> ERROR SEMANTICO: La funcion 'suma' espera (int, int) pero recibio float." << endl;
                        break;
                    }
                }
            }
        }
    }
};

// ==========================================
// FUNCION PRINCIPAL (CORREGIDA)
// ==========================================
int main() {
    AnalizadorSemantico semantico;

    cout << "--- VALIDACION SEMANTICA - SEMINARIO DE TRADUCTORES II ---" << endl << endl;

    // --- EJEMPLO 1 ---
    cout << "EJEMPLO 1:" << endl;
    semantico.insertar("a", "float", "variable");
    semantico.insertar("b", "int", "variable");
    semantico.insertar("c", "int", "variable");
    
    semantico.validarAsignacion("c", "float"); // c = a + b (resultado float)
    semantico.validarLlamada("suma", {"int", "int"}); // Error: suma no declarada
    cout << "------------------------------------------" << endl;

    // Limpiar tabla para ejemplo 2 (Simulacion de nuevo scope)
    semantico.tablaSimbolos.clear();

    // --- EJEMPLO 2 ---
    cout << "EJEMPLO 2:" << endl;
    semantico.insertar("suma", "int", "funcion");
    semantico.insertar("a", "float", "variable");
    semantico.insertar("b", "int", "variable");
    semantico.insertar("c", "int", "variable");

    semantico.validarAsignacion("c", "float"); // c = a + b
    semantico.validarLlamada("suma", {"float", "float"}); // Error: espera int, recibe float
    cout << "------------------------------------------" << endl;

    cout << endl << "Presione ENTER para salir...";
    cin.get(); 

    return 0;
}