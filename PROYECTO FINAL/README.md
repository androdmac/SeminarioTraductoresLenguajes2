# 🚀 PROYECTO FINAL: TRADUCTOR DE LENGUAJES (MINI-C)
**Materia:** Seminario de Solución de Problemas de Traductores de Lenguajes II  
**Centro Universitario de Ciencias Exactas e Ingenierías (CUCEI)**

---

## 📝 DESCRIPCIÓN
Este proyecto implementa un compilador funcional que integra las fases léxica, sintáctica y semántica. El sistema procesa un subconjunto de C++, construye un Árbol de Sintaxis Abstracta (AST) y valida la integridad de los tipos de datos y los ámbitos de las variables.

## 📁 ESTRUCTURA DE ARCHIVOS
El proyecto es modular para garantizar un diseño de ingeniería limpio:
- `lexico.h`: Analizador Léxico (Scanner) que identifica tokens y palabras reservadas.
- `nodos.h`: Definición de los nodos del Árbol Sintáctico (AST) con lógica de validación semántica.
- `tablasimbolos.h`: Gestión de variables, tipos de datos ('i', 'f') y ámbitos (Global/Local).
- `sintactico.h`: Implementación de la Pila de Estados LR(1) (Validado previamente en Excel).
- `semantico.h`: Motor de validación que recorre el árbol para detectar errores lógicos.
- `principal.cpp`: Punto de entrada que coordina todas las fases del traductor.

## 🌳 REPRESENTACIÓN DEL ÁRBOL SINTÁCTICO
Estructura generada para el código de prueba:

```text
PROGRAMA
├── DEFINICIÓN GLOBAL (int a)
├── FUNCIÓN: suma(int, int)
└── FUNCIÓN: main()
    ├── DECLARACIONES LOCALES (float a, int b, int c)
    └── SENTENCIA: ASIGNACIÓN (c = a + b)
        ├── VARIABLE: c (int)
        └── EXPRESIÓN: SUMA (float + int)
            └── RESULTADO: float --> ¡ERROR SEMÁNTICO!

## 💻 COMPILACIÓN Y EJECUCIÓN
Para ejecutar el proyecto en Windows

Abrir la terminal en la carpeta del proyecto.
Compilar el código fuente:

```Bash
g++ principal.cpp -o traductor.exe
Ejecutar el programa:

```Bash
./traductor.exe

## 🧪 CASO DE PRUEBA
El programa valida el siguiente código:

```C++
int a;
int suma(int a, int b){ return a+b; }
int main(){
    float a;
    int b;
    int c;
    c = a + b; // Aquí se dispara el error semántico
}
---

## 🧠 Fundamentos Técnicos y Análisis del Sistema

El desarrollo de este traductor se fundamenta en la teoría de lenguajes y autómatas, aplicando un enfoque de **análisis sintáctico ascendente (Bottom-Up)** y una validación semántica basada en atributos.

### 1. Análisis Sintáctico LR(1) y Dinámica de Pila
El motor sintáctico opera mediante un autómata de estados finitos que utiliza una **Pila de Estados (Stack-based Parsing)**. Este mecanismo permite procesar gramáticas libres de contexto complejas.
* **Mecánica de Reducción:** Al identificar un mango (handle) en el tope de la pila, el sistema realiza una reducción gramatical, lo que desencadena la instanciación de objetos en el **Árbol de Sintaxis Abstracta (AST)**.
* **Determinismo:** El uso de la tabla de transiciones LR asegura un análisis lineal $O(n)$, garantizando eficiencia en el reconocimiento de estructuras.

### 2. Gestión de Contexto y Ámbitos (Scope Management)
El sistema implementa un modelo de **Tablas de Símbolos Jerárquicas**. 
* **Sombreado de Identificadores (Variable Shadowing):** El traductor es capaz de diferenciar identificadores homónimos basándose en su profundidad de anidamiento (Global vs. Local), permitiendo la coexistencia de variables con distintos tipos de datos en contextos aislados.

### 3. Validación Semántica e Inferencia de Tipos
La fase semántica emplea un **recorrido de árbol (Tree Traversal)** para aplicar reglas de tipado:
* **Coerción y Verificación:** El sistema evalúa la compatibilidad de tipos en expresiones aritméticas. El análisis detecta discrepancias de precisión (como la asignación de tipos de punto flotante a tipos enteros), asegurando la integridad del flujo de datos y la prevención de errores en tiempo de ejecución.
* **Persistencia:** La validación se realiza mediante la propagación de atributos sintetizados a través de los nodos del AST.