# ⚙️ Etapa del proyecto analizador léxico completo.

Este proyecto consiste en un **Analizador Léxico** utilizando todos los simbolos lexicos.

---

## ✨ Características Principales

*   **Palabras Reservadas:** Reconocimiento de sentencias de control (`if`, `while`, `else`, `return`).
*   **Tipos de Datos:** Identificación de palabras clave como `int`, `float` y `void`.
*   **Operadores Compuestos:** Capacidad para procesar símbolos de dos caracteres como `==`, `!=`, `<=`, `>=`, `&&` y `||`.
*   **Mapeo de Tipos:** Clasificación sistemática mediante IDs para facilitar la integración con un Analizador Sintáctico.
*   **Símbolo de Fin:** Reconocimiento del carácter `$` como marcador de fin de cadena.

---

## 📊 Tabla de Clasificación de Tokens

El Lexer utiliza el siguiente esquema de numeración para los componentes encontrados:

| ID | Categoría | Ejemplos |
| :--- | :--- | :--- |
| **0** | Identificador | `suma`, `valor`, `x` |
| **1** | Entero | `10`, `42`, `100` |
| **2** | Real | `3.14`, `5.5`, `0.1` |
| **4** | Tipo de Dato | `int`, `float`, `void` |
| **5, 6** | Operadores Aritméticos | `+`, `-`, `*`, `/` |
| **7, 11** | Operadores Relacionales | `<`, `>`, `==`, `!=`, `<=`, `>=` |
| **8, 9, 10** | Operadores Lógicos | `&&`, `\|\|`, `!` |
| **12 - 17** | Símbolos de Puntuación | `;`, `,`, `(`, `)`, `{`, `}` |
| **18** | Asignación | `=` |
| **19 - 22** | Palabras Reservadas | `if`, `while`, `return`, `else` |
| **23** | Marcador Final | `$` |

---

## 🛠️ Detalles de Implementación

El código destaca por las siguientes soluciones técnicas:

*   **Uso de `std::map`:** Permite una búsqueda eficiente de palabras clave y tipos de datos en tiempo constante.
*   **Función `hacerMatch()`:** Implementa una lógica de anticipación para verificar si un carácter es seguido por otro que cambie su significado (por ejemplo, pasar de `=` a `==`).
*   **Formateo con `iomanip`:** Genera una salida en consola limpia y alineada para una mejor depuración.

---

## 🚀 Ejemplo de Uso

### Entrada de prueba:
`int suma = 10 + 5.5; if (suma > 0) return $`

### Salida generada:
```text
LEXEMA          | VALOR DE TIPO
-----------------------------------
int             | Tipo: 4
suma            | Tipo: 0
=               | Tipo: 18
10              | Tipo: 1
+               | Tipo: 5
5.5             | Tipo: 2
;               | Tipo: 12
if              | Tipo: 19
(               | Tipo: 14
suma            | Tipo: 0
>               | Tipo: 7
0               | Tipo: 1
)               | Tipo: 15
return          | Tipo: 21
$               | Tipo: 23