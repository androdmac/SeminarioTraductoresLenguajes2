#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

// Función para limpiar la pantalla según el sistema
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void imprimirEstado(const vector<string>& pila, string entrada, string accion) {
    limpiarPantalla();
    cout << "====================================================" << endl;
    cout << "     ANIMACION ANALIZADOR SINTACTICO LR - 2025B" << endl;
    cout << "====================================================" << endl;
    
    // Mostrar Pila
    cout << left << setw(15) << "PILA:";
    for (const string& s : pila) cout << s << " ";
    cout << endl;

    // Mostrar Entrada
    cout << left << setw(15) << "ENTRADA:" << entrada << endl;
    
    // Mostrar Acción
    cout << left << setw(15) << "ACCION:" << ">> " << accion << " <<" << endl;
    cout << "====================================================" << endl;
}

int main() {
    vector<string> pila = {"0"};
    string entrada = "id + id $";
    string pasos[] = {"Shift id", "Reduce E -> id", "Shift +", "Shift id", "Reduce E -> id", "Reduce E -> E + E", "Aceptar"};
    
    for (int i = 0; i < 7; i++) {
        imprimirEstado(pila, entrada, pasos[i]);

        // Simulación lógica del movimiento de la pila
        if (pasos[i].find("Shift") != string::npos) {
            pila.push_back("sym");
            pila.push_back(to_string(i + 1));
        } else if (pasos[i].find("Reduce") != string::npos) {
            pila.pop_back();
            pila.pop_back();
            pila.push_back("E");
            pila.push_back(to_string(i));
        }

        this_thread::sleep_for(chrono::milliseconds(1200));
    }

    cout << "\n[!] Analisis Sintactico Finalizado con Exito.\n";
    return 0;
}