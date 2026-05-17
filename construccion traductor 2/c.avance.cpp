#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura básica para un Token (útil para tu avance)
struct Token {
    string valor;
    int tipo; // 0: Identificador, 1: Entero, 2: Operador, etc.
};

// --- AQUÍ EMPIEZA LA CORRECCIÓN ---
// Asegúrate de que esta función esté fuera de cualquier clase

int main() {
    string entrada;
    cout << "--- Avance de Traductor / Compiladores ---" << endl;
    cout << "Introduce una cadena para analizar: ";
    
    // Usamos getline para leer la entrada del usuario
    if (!(cin >> entrada)) {
        return 0;
    }

    cout << "Analizando: " << entrada << endl;

    // Lógica de ejemplo: un analizador muy simple
    for (char c : entrada) {
        if (isdigit(c)) {
            cout << "Token: Entero (" << c << ")" << endl;
        } else if (isalpha(c)) {
            cout << "Token: Identificador/Letra (" << c << ")" << endl;
        } else {
            cout << "Token: Simbolo Especial (" << c << ")" << endl;
        }
    }

    cout << "\nAnalisis finalizado exitosamente." << endl;

    return 0;
}