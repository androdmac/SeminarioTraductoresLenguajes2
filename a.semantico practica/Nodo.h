#ifndef NODO_H
#define NODO_H

#include <string>

class TablaSimbolos; 
class Identificador;
class Tipo;

class Nodo {
public:
    char tipoDato;
    static TablaSimbolos *tablaSimbolos;
    static std::string ambito;
    Nodo* sig;

    Nodo();
    virtual ~Nodo() {}
    virtual void validaTipos();
};

// --- SUBCLASES ---

class Tipo : public Nodo {
public:
    std::string simbolo;
    char dimeTipo();
};

class Identificador : public Nodo {
public:
    std::string simbolo;
    Identificador* sig;
};

class DefVar : public Nodo {
public:
    Tipo* tipo;
    Identificador* listaVar;

    void validaTipos() override;
};

class DefFunc : public Nodo {
public:
    Tipo* tipo;
    Identificador* id;
    Nodo* parametros;
    Nodo* bloque;

    void validaTipos() override;
};

class Parametro : public Nodo {
public:
    Tipo* tipo;
    Identificador* id;

    void validaTipos() override;
};

class Expresion : public Nodo {
public:
    Nodo* izq;
    Nodo* der;
};

class Suma : public Expresion {
public:
    void validaTipos() override;
};

#endif // NODO_H