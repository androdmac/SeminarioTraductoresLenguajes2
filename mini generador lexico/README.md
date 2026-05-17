# 🔍 Mini generador léxico (C++)

Este proyecto es una herramienta sencilla diseñada para realizar el **análisis léxico** de una cadena de entrada. Su función principal es descomponer el texto en componentes básicos denominados **tokens**, siguiendo reglas gramaticales específicas.

---

## 🚀 Funcionalidades

El analizador identifica y clasifica la entrada en tres categorías:

* **Identificadores (`IDENTIFICADOR`):** Palabras que comienzan con una letra y pueden seguir con letras o números. 
    * *Ejemplo:* `variable1`, `aux`, `suma`.
* **Números Reales (`REAL`):** Valores numéricos que incluyen un punto decimal y al menos un dígito después de este.
    * *Ejemplo:* `10.5`, `3.1416`, `0.1`.
* **Errores Léxicos (`ERROR`):** Cualquier símbolo o secuencia que no encaje en las reglas anteriores o números reales mal formados (como `10.`).

---

## 🛠️ Estructura del Proyecto

El código está organizado de forma orientada a objetos para facilitar su comprensión:

1.  **`Token` (Estructura):** Almacena el tipo de token y su valor real (lexema).
2.  **`AnalizadorLexico` (Clase):** Contiene la lógica principal. Utiliza un puntero de posición para recorrer la cadena, ignorando espacios en blanco y aplicando las reglas de transición.
3.  **`main`:** Interfaz de consola que permite al usuario ingresar una cadena y visualizar la lista de tokens generada.

---

## 💻 Ejemplo de Ejecución

Al ingresar la cadena: `dato 12.5 error# 7.` el programa responderá:

| Entrada | Clasificación |
| :--- | :--- |
| `dato` | **ID** |
| `12.5` | **Real** |
| `error` | **ID** |
| `#` | **Error Lexico** |
| `7.` | **Error Lexico** |

---

## ⚙️ Compilación y Uso

Para ejecutar este analizador en tu entorno local:

1.  **Compilar:**
    ```bash
    g++ -o analizador main.cpp
    ```
2.  **Ejecutar:**
    ```bash
    ./analizador
    ```

---
> **Nota Académica:** Este proyecto sirve como base para entender la primera fase de la construcción de un compilador o traductor.