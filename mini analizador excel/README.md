# 📊 Simulación de un analizador sintáctico en Excel

Este repositorio contiene la documentación y el desglose paso a paso de la **Tabla de Análisis Sintáctico** para gramáticas simples y recursivas. El objetivo es simular el comportamiento de un autómata de pila al procesar tokens.

---

## 📋 Estructura de la Tabla de Análisis

Para replicar este ejercicio en Excel, se utiliza una hoja de cálculo con las siguientes columnas:

*   **Paso:** Número de la iteración actual.
*   **Pila:** Representación de los estados y símbolos (como enteros).
*   **Entrada:** Tokens pendientes por procesar.
*   **Acción:** Valor obtenido de la **Tabla LR** (ej. d2, r1, acc).
*   **Descripción:** Explicación técnica de la operación (Desplazamiento, Reducción o Aceptación).

---

## 📝 Ejercicio 1: Entrada `hola+mundo`

**Gramática:** $E \rightarrow id + id$  
**Tokens:** `id` = 0, `+` = 1, `$` = 2.  
**No Terminales:** $E$ = 3.

### Seguimiento de Pila:
| Paso | Pila (Enteros) | Entrada | Acción | Descripción |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 2 0 | 0 1 0 2 | d2 | **Desplazamiento:** mete token 0 y estado 2. |
| 2 | 2 0 0 2 | 1 0 2 | d3 | **Desplazamiento:** mete token 1 (+) y estado 3. |
| 3 | 2 0 0 2 1 3 | 0 2 | d4 | **Desplazamiento:** mete token 0 y estado 4. |
| 4 | 2 0 0 2 1 3 0 4 | 2 | r1 | **Reducción $R_1$:** saca 6 elementos (longitud 3 x 2). |
| 5 | 2 0 3 1 | 2 | -1 | **Aceptación:** Estado 1 con token $ es éxito. |

---

## 🔁 Ejercicio 2: Entrada `a+b+c+d+e+f`

Esta gramática es **recursiva por la derecha**: $E \rightarrow id + E \mid id$.

*   **Regla 1 ($R_1$):** $E \rightarrow id + E$ (Longitud 3).
*   **Regla 2 ($R_2$):** $E \rightarrow id$ (Longitud 1).

### Seguimiento simplificado:
1.  **Desplazamientos sucesivos:** Se introducen los `id` y los símbolos `+` hasta llegar al final de la cadena (`f`).
2.  **Reducción Inicial:** El último `id` ('f') se reduce mediante **$R_2$** para convertirse en $E$.
3.  **Reducciones en Cascada:** Se aplica **$R_1$** sucesivamente (`id + E`) de derecha a izquierda hasta reducir toda la cadena al símbolo inicial $E$.
4.  **Éxito:** La pila finaliza en el estado de aceptación al leer el token `$`.

---

## 🛠️ Guía de Implementación en Excel

Si deseas replicar este proceso manualmente, sigue estas reglas lógicas:

### 1. Preparación de la Tabla LR
Copia la matriz de estados desde tu archivo de referencia (PDF de la Práctica). La tabla debe cruzar **Estados** (filas) con **Terminales/No Terminales** (columnas).

### 2. Manejo de la Pila
*   **Desplazamiento (dX):** Empuja el token actual a la pila y luego el estado **X**.
*   **Reducción (rY):**
    1. Identifica la longitud de la regla **Y**.
    2. Saca de la pila el **doble** de elementos (Símbolo + Estado).
    3. **Salto (Goto):** Mira el nuevo tope de la pila y el No Terminal resultante para decidir qué nuevo estado meter.

### 3. Condición de Aceptación
El proceso termina exitosamente cuando la acción resultante es **-1** (o `acc`), indicando que la cadena pertenece al lenguaje.

---
> **Importante:** Al realizar reducciones, no olvides que por cada símbolo de la regla gramatical, existen dos elementos en la pila (el símbolo y el número de estado).