#ifndef _TABLASIMBOLOS
#define _TABLASIMBOLOS
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Elemento {
    string id;
    char tipo; // 'i' para int, 'f' para float
    string ambito;
};

class TablaSimbolos {
public:
    vector<Elemento> tabla;
    list<string> errores;

    void agrega(string id, char tipo, string ambito) {
        for(auto &e : tabla) {
            if(e.id == id && e.ambito == ambito) {
                errores.push_back("Error: Variable '" + id + "' ya definida en ambito " + ambito);
                return;
            }
        }
        tabla.push_back({id, tipo, ambito});
    }

    char buscaTipo(string id) {
        // Busca de local a global
        for(int i = tabla.size()-1; i >= 0; i--) {
            if(tabla[i].id == id) return tabla[i].tipo;
        }
        return 'v'; // No encontrado
    }
};
#endif