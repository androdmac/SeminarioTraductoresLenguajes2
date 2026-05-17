#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H

#include <list>
#include <string>

class DefVar;  
class DefFunc;
class Parametro;

// Estructura base para los elementos guardados dentro de la tabla
class ElementoTabla {
public:
    std::string nombre;
    char tipo;
    std::string ambito;
    ElementoTabla(char t, std::string n, std::string a) : tipo(t), nombre(n), ambito(a) {}
};

class Variable : public ElementoTabla {
public:
    Variable(char t, std::string n, std::string a) : ElementoTabla(t, n, a) {}
};

class TablaSimbolos {
public:
    std::list<std::string>* listaErrores;
    std::list<ElementoTabla*> tabla; // Almacenamiento simulado usando listas

    TablaSimbolos(std::list<std::string>* listaErrores);
    
    // Métodos base solicitados
    void agrega(ElementoTabla *elemento);
    void muestra();
    bool varGlobalDefinida(std::string simbolo);
    bool funcionDefinida(std::string simbolo);
    bool varLocalDefinida(std::string variable, std::string funcion);

    // Los 3 métodos que pedía completar la práctica
    void agrega(DefVar *defVar);
    void agrega(DefFunc *defFunc);
    void agrega(Parametro *parametros);
};

#endif // TABLASIMBOLOS_H