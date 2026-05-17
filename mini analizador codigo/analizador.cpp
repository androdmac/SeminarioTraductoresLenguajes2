#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// --- 1. DEFINICIÓN DE TABLAS (Los datos que pasaste primero) ---
int tabla2[5][4] = {
    { 2, 0, 0, 1}, 
    { 0, 0, -1, 0}, 
    { 0, 3, -3, 0}, 
    { 2, 0, 0, 4}, 
    { 0, 0, -2, 0}  
};

// --- 2. ESTRUCTURAS Y REGLAS ---
struct Regla {
    int id;       
    int longitud; 
};

Regla reglas[] = {
    {3, 3}, // R1: E -> id + E
    {3, 1}  // R2: E -> id
};

// --- 3. TU FUNCIÓN DE ANÁLISIS ---
void analizarSintactico(vector<int> tokens, int tabla[5][4]) {
    stack<int> pila;
    pila.push(2); // $
    pila.push(0); // Estado inicial

    int i = 0;
    bool terminado = false;

    while (!terminado) {
        int estadoActual = pila.top();
        int tokenActual = tokens[i];
        int accion = tabla[estadoActual][tokenActual];

        if (accion > 0) { 
            pila.push(tokenActual);
            pila.push(accion);
            i++;
            cout << "Desplazamiento al estado " << accion << endl;
        } 
        else if (accion < 0) { 
            if (accion == -1) { 
                cout << "CADENA VALIDA / ACEPTADA" << endl;
                terminado = true;
            } else {
                int numRegla = (accion * -1) - 2; 
                int lon = reglas[numRegla].longitud;
                int noTerminal = reglas[numRegla].id;

                for (int j = 0; j < lon * 2; j++) pila.pop();

                int estadoAnterior = pila.top();
                int nuevoEstado = tabla[estadoAnterior][noTerminal];
                
                pila.push(noTerminal);
                pila.push(nuevoEstado);
                cout << "Reduccion por regla " << (numRegla + 1) << endl;
            }
        } 
        else { 
            cout << "ERROR SINTACTICO en posicion " << i << endl;
            terminado = true;
        }
    }
}

// --- 4. FUNCIÓN MAIN (Necesaria para compilar) ---
int main() {
    // Ejemplo: id + id $
    // Basado en tu tabla: id=0, +=1, $=2, E=3
    vector<int> entrada = {0, 1, 0, 2}; 
    
    cout << "Analizando cadena..." << endl;
    analizarSintactico(entrada, tabla2);
    
    return 0;
}