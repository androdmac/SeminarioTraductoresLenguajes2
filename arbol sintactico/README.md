# 🏗️ Analizador Sintáctico LR y Generación de AST

Este proyecto implementa un compilador modular en **C++** que integra un analizador léxico, un motor sintáctico LR y la generación dinámica de un **Árbol de Sintaxis Abstracta (AST)**. Es una herramienta diseñada para procesar lenguajes de programación siguiendo los estándares del Seminario de Traductores II.

---

## 1. Descripción de la Etapa
En esta fase se implementó la estructura y generación del **Árbol de Sintaxis Abstracta (AST)**. El AST es una representación jerárquica simplificada del código fuente que captura la estructura lógica del programa, eliminando elementos sintácticos redundantes. Esta estructura es fundamental para las etapas posteriores de análisis semántico y generación de código intermedio.

## 2. Código de Prueba Analizado
Se utiliza un fragmento de código con funciones y asignaciones para validar la construcción del árbol:
```cpp
int a;
int suma(int a, int b){
    return a+b;
}

int main(){
    c = a+b;
    c = suma(8,9);
}

## 3. Representación Estructural (AST)
Jerarquía generada por el analizador para el código de prueba:
```cpp
[PROGRAMA]
 |
 |-- [DECLARACIÓN GLOBAL]
 |    |-- Tipo: int
 |    |-- ID: a
 |
 |-- [DEFINICIÓN FUNCIÓN: suma]
 |    |-- Tipo Retorno: int
 |    |-- PARÁMETROS
 |    |    |-- Parám: int a
 |    |    |-- Parám: int b
 |    |-- CUERPO (BLOQUE)
 |         |-- SENTENCIA: RETURN
 |              |-- EXPRESIÓN (+)
 |                   |-- ID: a
 |                   |-- ID: b

 ## 4. Implementación Técnica en C++
La construcción del árbol se realiza de forma dinámica mediante una estructura de nodos que almacenan punteros a sus dependientes.

Estructura de la Clase Nodo:
```cpp
struct Nodo {
    string tipo;          // Identificador del tipo de nodo (PROGRAMA, ASIGNACION, etc.)
    string valor;         // Lexema asociado (ID, operador, valor)
    vector<Nodo*> hijos;  // Punteros a los nodos dependientes

    Nodo(string t, string v = "") : tipo(t), valor(v) {}
};

## 5. Proceso de Construcción (Reducción):
Reducción Sintáctica: Cada vez que el analizador LR realiza una reducción, se instancia un nuevo objeto Nodo padre que representa la regla gramatical.

Enlace Dinámico: Los símbolos que se encuentran a la derecha de la regla en la pila se enlazan como hijos del nuevo nodo padre.

Gestión de Pila: La pila no solo almacena estados, sino también los punteros a los nodos del AST en construcción, asegurando que el árbol crezca desde las hojas hacia la raíz.

---

## ⚙️ Compilación y Uso
Compilar:
```cpp
g++ arbol.cpp
Ejecutar:
./a.exe