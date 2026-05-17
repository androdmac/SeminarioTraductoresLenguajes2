# 🏗️ Gramatica Compilador

Este proyecto implementa un **Analizador Sintáctico** basado en el algoritmo de análisis **LR**. Es capaz de procesar una cadena de tokens generada por un lexer y determinar si la estructura gramatical es correcta utilizando una tabla de análisis de estados y una pila.

---

## 🚀 Características Principales

* **Motor de Análisis LR:** Implementación completa de las acciones de **Desplazamiento (Shift)** y **Reducción (Reduce)**.
* **Gestión de Reglas de Producción:** Sistema basado en estructuras para manejar el ID del No Terminal y la longitud de la regla para el manejo preciso de la pila.
* **Tabla de Estados a Gran Escala:** Soporte para una matriz de transición de hasta 95 estados y 40 columnas de símbolos.
* **Seguimiento de Pasos:** Logs detallados en consola que muestran el estado actual, el lexema procesado y la acción tomada en cada iteración.

---

## 🛠️ Estructura del Proyecto

El código se organiza en tres componentes fundamentales que simulan la arquitectura de un compilador real:

### 1. Lexer (Analizador Léxico)
Clase encargada de la tokenización. Proporciona objetos de tipo `Token` que contienen:
* **Tipo:** El identificador numérico según la tabla de símbolos.
* **Lexema:** El valor textual de la cadena.

### 2. Tabla de Análisis LR (`tablaLR`)
Es la matriz de decisiones del compilador. Coordina el flujo basándose en la intersección entre el **Estado** (Tope de la pila) y el **Símbolo** (Token actual):
* **Acción > 0:** Indica un desplazamiento (Shift) hacia el estado X.
* **Acción < 0:** Indica una reducción (Reduce) mediante una regla gramatical.
* **Acción == -1:** Indica que la cadena ha sido aceptada con éxito.
* **Acción == 0:** Detona un error sintáctico.

### 3. Sistema de Reglas
El analizador utiliza el arreglo `reglasModulo4` para gestionar las reducciones, permitiendo al algoritmo saber exactamente cuántos elementos extraer de la pila (Longitud * 2) y qué No Terminal reinsertar.

---

## 📊 Lógica de Funcionamiento (Pila)

Para garantizar la integridad del análisis, la pila maneja pares de datos (**Símbolo**, **Estado**):
1.  **En Desplazamiento:** Se apila el Tipo del Token y luego el Estado destino.
2.  **En Reducción:** Se extraen $n \times 2$ elementos de la pila, donde $n$ es la longitud de la regla aplicada. Posteriormente, se consulta la tabla con el estado resultante y el No Terminal para realizar el **Salto (Goto)**.

---

## 💻 Ejemplo de Uso

El programa está configurado para validar cadenas como `int principal ;`.

### Salida esperada en consola:
```text
Estado: 0 | Token: int | Accion: 5
Estado: 5 | Token: principal | Accion: 8
...
RESULTADO: Cadena gramaticalmente correcta.