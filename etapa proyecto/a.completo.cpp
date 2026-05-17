#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>
#include <map>

using namespace std;

class Lexer {
private:
    string fuente;
    size_t pos;
    map<string, int> palabrasReservadas;
    map<string, int> tiposDato;

public:
    Lexer(string entrada) : fuente(entrada), pos(0) {
        // Inicialización de Palabras Reservadas según la tabla [cite: 23, 25]
        palabrasReservadas["if"] = 19;
        palabrasReservadas["while"] = 20;
        palabrasReservadas["return"] = 21;
        palabrasReservadas["else"] = 22;
        
        // Tipos de dato específicos 
        tiposDato["int"] = 4;
        tiposDato["float"] = 4;
        tiposDato["void"] = 4;
    }

    void analizar() {
        while (pos < fuente.length()) {
            char actual = fuente[pos];

            if (isspace(actual)) {
                pos++;
                continue;
            }

            // Identificadores y Palabras Reservadas [cite: 3, 20]
            if (isalpha(actual)) {
                string lexema = "";
                while (pos < fuente.length() && isalnum(fuente[pos])) {
                    lexema += fuente[pos++];
                }
                
                if (tiposDato.count(lexema)) imprimirToken(lexema, tiposDato[lexema]);
                else if (palabrasReservadas.count(lexema)) imprimirToken(lexema, palabrasReservadas[lexema]);
                else imprimirToken(lexema, 0); // Identificador 
                continue;
            }

            // Números Enteros y Reales [cite: 4, 5]
            if (isdigit(actual)) {
                string num = "";
                while (pos < fuente.length() && isdigit(fuente[pos])) num += fuente[pos++];
                
                if (pos < fuente.length() && fuente[pos] == '.') {
                    num += fuente[pos++];
                    while (pos < fuente.length() && isdigit(fuente[pos])) num += fuente[pos++];
                    imprimirToken(num, 2); // Real 
                } else {
                    imprimirToken(num, 1); // Entero 
                }
                continue;
            }

            // Operadores y Símbolos Especiales
            if (hacerMatch("==")) { imprimirToken("==", 11); continue; }
            if (hacerMatch("!=")) { imprimirToken("!=", 11); continue; }
            if (hacerMatch("<=")) { imprimirToken("<=", 7); continue; }
            if (hacerMatch(">=")) { imprimirToken(">=", 7); continue; }
            if (hacerMatch("&&")) { imprimirToken("&&", 9); continue; }
            if (hacerMatch("||")) { imprimirToken("||", 8); continue; }
            
            switch (actual) {
                case '+': case '-': imprimirToken(string(1, actual), 5); break; // opSuma 
                case '*': case '/': imprimirToken(string(1, actual), 6); break; // opMul 
                case '<': case '>': imprimirToken(string(1, actual), 7); break; // opRelac 
                case '!': imprimirToken("!", 10); break; // opNot 
                case ';': imprimirToken(";", 12); break;
                case ',': imprimirToken(",", 13); break;
                case '(': imprimirToken("(", 14); break;
                case ')': imprimirToken(")", 15); break;
                case '{': imprimirToken("{", 16); break;
                case '}': imprimirToken("}", 17); break;
                case '=': imprimirToken("=", 18); break;
                case '$': imprimirToken("$", 23); break;
                default:
                    cout << "Error lexico: " << actual << endl;
            }
            pos++;
        }
    }

private:
    bool hacerMatch(string esperado) {
        if (fuente.substr(pos, esperado.length()) == esperado) {
            pos += esperado.length();
            return true;
        }
        return false;
    }

    void imprimirToken(string lexema, int tipo) {
        cout << left << setw(15) << lexema << " | Tipo: " << tipo << endl;
    }
};

int main() {
    string codigo = "int suma = 10 + 5.5; if (suma > 0) return $";
    cout << "Analizando: " << codigo << "\n" << endl;
    cout << left << setw(15) << "LEXEMA" << " | VALOR DE TIPO" << endl;
    cout << "-----------------------------------" << endl;
    
    Lexer lex(codigo);
    lex.analizar();

    return 0;
}