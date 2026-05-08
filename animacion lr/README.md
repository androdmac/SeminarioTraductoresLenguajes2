# 🎬 Animación del Analizador Sintáctico LR

Este proyecto es una herramienta didáctica desarrollada en **C++** que visualiza el proceso de análisis sintáctico (parsing) de forma animada. Permite observar cómo interactúan la **Pila**, la **Cadena de Entrada** y las **Acciones** (Shift/Reduce) en tiempo real.

---

## ✨ Características Principales

*   **Animación en Tiempo Real:** Utiliza retardos controlados (`chrono`) para mostrar el flujo paso a paso del análisis.
*   **Gestión Dinámica de Pila:** Simulación visual de cómo se apilan símbolos y estados, y cómo se extraen durante las reducciones.
*   **Multiplataforma:** Incluye una función de limpieza de consola compatible tanto con **Windows** (`cls`) como con **Linux/macOS** (`clear`).
*   **Interfaz Limpia:** Uso de `iomanip` para una visualización tabular organizada en la terminal.

---

## 🛠️ Cómo Funciona

El programa simula el análisis de la cadena clásica `id + id $` siguiendo una gramática de expresiones. Los pasos representados son:

1.  **Shift (Desplazamiento):** Pasa un token de la entrada a la pila.
2.  **Reduce (Reducción):** Aplica una regla gramatical (ej. $E \rightarrow id$) sustituyendo elementos de la pila por un No Terminal.
3.  **Accept (Aceptación):** Estado final donde la cadena se reconoce como válida.

---

## 📊 Visualización de la Consola

Durante la ejecución, verás una interfaz similar a esta, actualizándose cada 1.2 segundos:

```text
====================================================
     ANIMACION ANALIZADOR SINTACTICO LR - 2025B
====================================================
PILA:          0 sym 1 E 2 
ENTRADA:       id + id $
ACCION:        >> Reduce E -> E + E <<
====================================================