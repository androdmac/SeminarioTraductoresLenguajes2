# 🏛️ Avances en la Construcción del Traductor

Este proyecto implementa un **Traductor** modular diseñado en C++, el cual integra un **Scanner** (Analizador Léxico) y un **Parser** (Analizador Sintáctico) basado en una tabla de decisiones LR. Es capaz de reconocer identificadores, números reales, enteros y palabras reservadas, validando su estructura gramatical mediante una pila de estados.

---

## 🚀 Funcionalidades Principales

* **Analizador Léxico (Scanner):** Identifica tokens como palabras reservadas (`if`, `while`, `int`), números reales, enteros y operadores.
* **Analizador Sintáctico (Parser):** Implementa el algoritmo de **Desplazamiento (Shift)** y **Reducción (Reduce)** utilizando una tabla LR de estados.
* **Gestión de Gramática:** Soporta reglas recursivas para expresiones (ej. $E \rightarrow id + E$).
* **Manejo de Errores:** Detecta y reporta errores léxicos (caracteres no reconocidos) y errores sintácticos durante el análisis.

---

## 📋 Arquitectura del Código

El sistema se encapsula en la clase `Traductor`, la cual gestiona los siguientes componentes:

### 1. Definición de Tokens
Utiliza una estructura de datos `Token` para mapear el flujo de entrada según la tabla de tipos estándar:
* **Enteros (Tipo 1):** Secuencias numéricas simples.
* **Reales (Tipo 2):** Números con punto decimal.
* **Identificadores/Reservadas:** Mapeados mediante un diccionario interno (ej. `int` = 4, `while` = 20).
* **Fin de Cadena:** Representado por el símbolo `$` (Tipo 23).

### 2. Tabla de Análisis LR
El motor sintáctico se rige por una matriz de estados (`tablaLR`) que determina la acción a seguir basándose en el estado actual de la pila y el token entrante:
* **Acción > 0:** Realiza un desplazamiento al estado indicado.
* **Acción < 0:** Ejecuta una reducción por una regla gramatical o indica la aceptación de la cadena (`-1`).

### 3. Sistema de Reglas
El analizador aplica las siguientes producciones gramaticales durante las reducciones:
1.  **Regla 1 ($R_1$):** $E \rightarrow id + E$ (Longitud 3).
2.  **Regla 2 ($R_2$):** $E \rightarrow id$ (Longitud 1).

---

## 🛠️ Lógica de la Pila

Para mantener la integridad del análisis sintáctico, la pila almacena pares de **(Símbolo/Estado)**:
* **En Desplazamiento:** Se introduce el tipo del token y el nuevo estado.
* **En Reducción:** Se eliminan de la pila $n \times 2$ elementos (donde $n$ es la longitud de la regla aplicada). Posteriormente, se realiza un salto (**Goto**) consultando la tabla con el nuevo tope de la pila y el No Terminal resultante.

---

## 💻 Compilación y Ejecución

Puedes compilar el proyecto utilizando cualquier compilador de C++ estándar (GCC recomendado):

1.  **Compilar:**
    ```bash
    g++ -o traductor main.cpp
    ```

2.  **Ejecutar:**
    ```bash
    ./traductor
    ```

---
> **Nota Académica:** Este traductor ha sido diseñado siguiendo los lineamientos de la carrera de Ingeniería en Computación de la Universidad de Guadalajara, integrando las tablas de símbolos y estados proporcionadas en la práctica.