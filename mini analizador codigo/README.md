# 🧠 Mini analizador sintáctico Código

Este proyecto implementa un **Analizador Sintáctico** basado en una tabla de decisiones LR (Left-to-Right). El programa utiliza una pila para procesar una secuencia de tokens y determinar si la estructura gramatical es válida según las reglas de producción definidas.

---

## 📋 Especificaciones de la Gramática

El analizador está configurado para procesar una gramática recursiva simple definida por las siguientes reglas:

*   **Regla 1 ($R_1$):** $E \rightarrow id + E$ (Longitud: 3 símbolos)
*   **Regla 2 ($R_2$):** $E \rightarrow id$ (Longitud: 1 símbolo)

### Diccionario de Tokens y Símbolos
Para la interpretación de la tabla, se utilizan los siguientes identificadores:
*   **0:** `id` (Identificador)
*   **1:** `+` (Operador suma)
*   **2:** `$` (Símbolo de fin de cadena / Aceptación)
*   **3:** `E` (Símbolo No Terminal)

---

## 🛠️ Funcionamiento del Algoritmo

El núcleo del programa es la función `analizarSintactico`, la cual opera bajo tres estados lógicos dictados por la matriz de transición (`tabla2`):

1.  **Desplazamiento (Shift - Acción > 0):**
    *   Se introduce el token actual en la pila.
    *   Se introduce el nuevo estado (el valor de la tabla) en la pila.
    *   Se avanza al siguiente token de la entrada.
2.  **Reducción (Reduce - Acción < 0):**
    *   **Aceptación:** Si la acción es `-1`, la cadena es válida y el proceso termina.
    *   **Regla Aplicada:** Si es otro valor negativo, se identifica la regla. Por ejemplo, `-3` indica una reducción para volver al No Terminal.
    *   Se eliminan de la pila $n \times 2$ elementos (donde $n$ es la longitud de la regla).
    *   Se realiza un **Salto (Goto)** buscando el nuevo estado según el tope de la pila y el No Terminal.
3.  **Error (Acción = 0):**
    *   Si la tabla devuelve 0, la cadena no pertenece al lenguaje y se reporta un error sintáctico.

---

## 💻 Ejemplo de Ejecución

El código incluye un caso de prueba que analiza la secuencia: `id + id $` (representada como `{0, 1, 0, 2}`).

**Salida esperada en consola:**
```text
Analizando cadena...
Desplazamiento al estado 2
Desplazamiento al estado 3
Desplazamiento al estado 2
Reduccion por regla 2
Reduccion por regla 1
CADENA VALIDA / ACEPTADA