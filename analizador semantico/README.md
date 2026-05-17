# Etapa: Análisis Semántico

---

## 1. Descripción de la Etapa
El **Análisis Semántico** es la fase del compilador que conecta las definiciones con sus usos y verifica que las reglas del lenguaje (que no pueden ser expresadas por la gramática sintáctica) se cumplan. 

En esta implementación, el analizador realiza las siguientes validaciones:
*   **Verificación de Existencia:** Comprobación de que cada variable o función haya sido declarada antes de su uso.
*   **Compatibilidad de Tipos:** Validación de que las asignaciones y operaciones aritméticas sean consistentes entre tipos (int, float).
*   **Firma de Funciones:** Verificación de que el número y tipo de argumentos en una llamada coincidan con la definición original.

---

## 2. Validación Semántica de Ejemplos

### Caso de Prueba 1
**Código Analizado:**
```cpp
int main(){
    float a;
    int b;
    int c;
    c = a + b;
    c = suma(8, 9);
}

### Caso de Prueba 2
**Código Analizado:**
```cpp
int a;
int suma(int a, int b){
    return a + b;
}

int main(){
    float a;
    int b;
    int c;
    c = a + b;
    c = suma(8.5, 9.9);
}



