#ifndef _LEXICO
#define _LEXICO
#include <iostream>
#include <string>

using namespace std;

class Lexico {
public:
    string fuente;
    int pos;
    string simbolo;
    int tipo; // 0: id, 1: +, 2: $, 3: int, 4: float, 5: =, 6: ;

    Lexico(string s) : fuente(s + "$"), pos(0) { sigSimbolo(); }

    void sigSimbolo() {
        while (pos < fuente.length() && isspace(fuente[pos])) pos++;
        if (pos >= fuente.length()) return;

        char c = fuente[pos];
        simbolo = c;

        if (isalpha(c)) {
            simbolo = "";
            while (pos < fuente.length() && isalnum(fuente[pos])) simbolo += fuente[pos++];
            if (simbolo == "int") tipo = 3;
            else if (simbolo == "float") tipo = 4;
            else tipo = 0; // Identificador
        } 
        else if (isdigit(c)) {
            simbolo = "";
            while (pos < fuente.length() && (isdigit(fuente[pos]) || fuente[pos] == '.')) simbolo += fuente[pos++];
            tipo = 0; // Tratado como id/valor para simplificar
        }
        else if (c == '+') { tipo = 1; pos++; }
        else if (c == '=') { tipo = 5; pos++; }
        else if (c == ';') { tipo = 6; pos++; }
        else if (c == '$') { tipo = 2; pos++; }
    }
};
#endif