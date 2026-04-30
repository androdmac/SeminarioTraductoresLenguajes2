#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

enum TipoToken {
    IDENTIFICADOR,
    REAL,
    ERROR
};

struct Token {
    TipoToken tipo;
    string valor;
};

class AnalizadorLexico {
private:
    string entrada;
    size_t pos;

public:
    AnalizadorLexico(string texto) : entrada(texto), pos(0) {}

    Token siguienteToken() {
        // Omitir espacios en blanco
        while (pos < entrada.length() && isspace(entrada[pos])) {
            pos++;
        }

        if (pos >= entrada.length()) return {ERROR, ""};

        char actual = entrada[pos];
        string lexema = "";

        // Lógica para IDENTIFICADORES: letra(letra|digito)*
        if (isalpha(actual)) {
            while (pos < entrada.length() && (isalnum(entrada[pos]))) {
                lexema += entrada[pos++];
            }
            return {IDENTIFICADOR, lexema};
        }

        // Lógica para REALES: entero.entero+
        if (isdigit(actual)) {
            while (pos < entrada.length() && isdigit(entrada[pos])) {
                lexema += entrada[pos++];
            }

            // Verificar si sigue un punto para ser Real
            if (pos < entrada.length() && entrada[pos] == '.') {
                lexema += entrada[pos++];
                
                // Debe haber al menos un dígito después del punto
                if (pos < entrada.length() && isdigit(entrada[pos])) {
                    while (pos < entrada.length() && isdigit(entrada[pos])) {
                        lexema += entrada[pos++];
                    }
                    return {REAL, lexema};
                }
            }
        }

        // Si no coincide con nada o el real está incompleto
        lexema += entrada[pos++];
        return {ERROR, lexema};
    }

    bool haTerminado() {
        return pos >= entrada.length();
    }
};

int main() {
    string texto;
    cout << "Introduce la cadena a analizar: ";
    getline(cin, texto);

    AnalizadorLexico lexico(texto);

    cout << "\nTokens encontrados:\n";
    cout << "---------------------------\n";

    while (!lexico.haTerminado()) {
        Token t = lexico.siguienteToken();
        if (t.tipo == IDENTIFICADOR)
            cout << "ID: " << t.valor << endl;
        else if (t.tipo == REAL)
            cout << "Real: " << t.valor << endl;
        else if (t.valor != "")
            cout << "Error Lexico: " << t.valor << endl;
    }

    return 0;
}