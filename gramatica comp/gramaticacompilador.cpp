#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// --- 1. DEFINICIONES BASE (Para que el compilador las reconozca) ---
struct Token {
    int tipo;
    string lexema;
};

// Clase Lexer simplificada (Asegúrate de que coincida con tu lógica del PDF)
class Lexer {
private:
    string entrada;
    size_t posicion;
public:
    Lexer(string e) : entrada(e), posicion(0) {}
    
    Token obtenerSiguienteToken() {
        // Aquí debe ir tu lógica real de símbolos_lexicos.pdf
        // Por ahora devuelve un token vacío para que no truene
        return {23, "$"}; 
    }
};

// --- 2. ESTRUCTURA DE REGLAS ---
struct Regla {
    int id;       // ID del No Terminal
    int longitud; // Cantidad de elementos a la derecha
};

Regla reglasModulo4[] = {
    {24, 1}, // R1
    {25, 2}, // R2
    {26, 0}, // R3
    {27, 3}, // R4
    {28, 6}  // R5
};

// --- 3. TABLA LR ---
// Nota: Asegúrate de que las dimensiones [95][X] coincidan con tu tabla completa
int tablaLR[95][40] = { 
    // id, ent, real, cad, tipo...
    { 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 }, 
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1 }
};

// --- 4. ANALIZADOR SINTÁCTICO ---
class AnalizadorCompilador {
public:
    stack<int> pila;

    void mostrarPaso(int st, string lex, int acc) {
        cout << "Estado: " << st << " | Token: " << lex << " | Accion: " << acc << endl;
    }

    void ejecutar(string entrada) {
        Lexer lex(entrada); 
        
        // Limpiar pila por si se reutiliza el objeto
        while(!pila.empty()) pila.pop();

        pila.push(23); // Símbolo inicial de fondo $ 
        pila.push(0);  // Estado inicial

        Token t = lex.obtenerSiguienteToken();

        while (true) {
            int fila = pila.top();
            int col = t.tipo;
            int accion = tablaLR[fila][col];

            mostrarPaso(fila, t.lexema, accion);

            if (accion > 0) { // DESPLAZAMIENTO
                pila.push(t.tipo);
                pila.push(accion);
                t = lex.obtenerSiguienteToken();
            } 
            else if (accion < 0) { // REDUCCIÓN O ACEPTACIÓN
                if (accion == -1) {
                    cout << "RESULTADO: Cadena gramaticalmente correcta." << endl;
                    break;
                }

                // Lógica de Reducción LR
                // Usamos abs(accion) para obtener el índice de la regla
                int rIdx = (accion * -1) - 2; 
                int lon = reglasModulo4[rIdx].longitud;
                
                // Sacar de la pila (longitud * 2) porque guardamos (Símbolo, Estado)
                for (int i = 0; i < lon * 2; i++) {
                    if(!pila.empty()) pila.pop();
                }

                int estadoSalto = pila.top();
                int noTerminal = reglasModulo4[rIdx].id;
                
                pila.push(noTerminal);
                pila.push(tablaLR[estadoSalto][noTerminal]);
            } 
            else { // ACCION == 0 (ERROR)
                cout << "ERROR SINTACTICO: No se esperaba el lexema '" << t.lexema << "'" << endl;
                break;
            }
        }
    }
};

// --- 5. FUNCIÓN PRINCIPAL PARA PRUEBAS ---
int main() {
    AnalizadorCompilador sintactico;
    sintactico.ejecutar("int principal ;");
    return 0;
}