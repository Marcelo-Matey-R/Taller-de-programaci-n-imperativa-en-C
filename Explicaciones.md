# Ejercicio 1 Intercambio de valores 
## Pregunta 1: ¿por qué los parámetros son punteros?

Si hubieramos hecho la funcion de la siguiente forma:
```c
void swap(int a, int b);
```

Entonces C lo que hubiera hecho es hacer copias locales dentro de la funcion, provocando que al hacer el swap esto se haga localmente dentro de la funcion no un cambio del valor real de las variables.

## Pregunta 2: ¿Qué diferencia existe entre modificar a y modificar *a dentro de la función?

La diferencia radica en el hecho que al ser las entradas punteros entonces si modificamos el valor de **_a_** entonces estariamos haciendo cambios en la direccion de memoria y no sobre el valor, sin embargo si modificamos **_*a_** entonces estamos modificando el valor en dicha posicion de memoria.

## Pregunta 3: ¿Cuál es el alcance de una variable auxiliar declarada en swap?
Una variable auxiliar dentro de swap sera una variable temporal creada en el stack que esta viva mientras la funcion **_swap_** este trabajando, por lo que muere cuando la funcion llega al return.

# Ejercicio 3 Copia independiente

## Pregunta 1: Explique por qué asignar un puntero a otro no crea una copia de los elementos. 

Esto sucede ya que al asignar un puntero a otro entonces lo que le estoy dando es la posicion de memoria a la cual esta apuntando el primer puntero.

Por esa razon no duplica valores, sino que ambos terminan apuntanto a la misma direccion de memoria permitiendole a la copia permisos de lectura y escritura en essa direccion.

# Ejercicio 4 Ordenar una copia

## Algoritmo elegido: inserción

Se recorre el arreglo desde la posición 1. En cada paso, la parte izquierda (`values[0..i-1]`) ya está ordenada. Se guarda `values[i]` en `key` y, mientras el elemento de la izquierda sea mayor que `key`, se desplaza una posición a la derecha. Cuando ya no hay mayores, se coloca `key` en el hueco (`values[j+1]`).

Traza con `[4, -2, 0, 7, -5]`:

| i | key | Resultado |
|---|-----|-----------|
| 1 | -2 | `[-2, 4, 0, 7, -5]` |
| 2 | 0 | `[-2, 0, 4, 7, -5]` |
| 3 | 7 | `[-2, 0, 4, 7, -5]` |
| 4 | -5 | `[-5, -2, 0, 4, 7]` |

La condición del ciclo interno es `j >= 0 && values[j] > key`. El orden importa: como `&&` se evalúa de izquierda a derecha y se detiene en el primer falso, primero se verifica el límite y así nunca se lee `values[-1]`.

Complejidad: O(n²) en el peor caso y O(n) si el arreglo ya está ordenado. Este ordenamiento también se reutiliza en 3Sum sin cambiar su complejidad total O(n²).

## ¿Por qué se ordena una copia?

`sortAscending` modifica el arreglo que recibe (ordena *in-place*). Para conservar el original, primero se crea una copia independiente con `copyArray`, se ordena la copia y, al final, se libera con `free`.

# Ejercicio 5 Dos valores que suman un objetivo.

## Pregunta 1: Explique por qué puede descartarse un extremo después de comparar la suma.

Esto se debe a que la lista está ordenada ascendentemente.

Sean `left` y `right` los índices actuales del arreglo, donde `left < right`. Debido al ordenamiento, se cumple estrictamente que:

> `values[left] <= values[right]`

Esto nos permite descartar un extremo bajo las siguientes reglas:

* **Si la suma actual es mayor que el `target`:** Dado que `values[right]` es el valor más grande disponible en ese rango, sumarlo con cualquier otro elemento hacia la derecha de `left` seguirá dando un resultado demasiado alto. Por lo tanto, podemos descartar el extremo derecho de forma segura reduciendo el índice (`right--`) para buscar una suma más pequeña.

* **Si la suma actual es menor que el `target`:** Por el caso inverso, sumarle al elemento más pequeño (`values[left]`) cualquier valor menor a `values[right]` nunca alcanzará el objetivo. Por ende,  descartamos el extremo izquierdo aumentando el índice (`left++`).

# Ejercicio 6 3Sum

## ¿Cómo se evitan las ternas duplicadas?

Primero se crea una copia del arreglo y se ordena ascendentemente. Al estar ordenado, los valores iguales quedan en posiciones contiguas, lo que permite detectarlos comparando con el vecino. Los duplicados se evitan en dos puntos:

1. **En el elemento fijo:** antes de buscar pares para `copia[i]`, si `i > 0` y `copia[i] == copia[i-1]`, se salta esa posición con `continue`. Todas las ternas que podrían formarse con ese valor ya se encontraron en la iteración anterior.

2. **En el par:** al encontrar una terna se mueven ambos índices (`left++`, `right--`) y luego se siguen moviendo mientras el nuevo valor sea igual al anterior:
   - `while (left < right && values[left] == values[left - 1]) left++;`
   - `while (left < right && values[right] == values[right + 1]) right--;`

Además, el par se busca solo a la derecha del elemento fijo (`left = i + 1`). Así cada terna se encuentra una única vez, desde su elemento de menor índice, y nunca se usa la misma posición dos veces.

Esto no prohíbe valores repetidos dentro de una terna: en `[-1, 0, 1, 2, -1, -4]` se obtiene `(-1, -1, 2)` porque los dos `-1` vienen de posiciones distintas. Lo que se evita es imprimir la misma terna más de una vez. Por ejemplo, en `[-2, 0, 0, 2, 2]`, sin el segundo salto se imprimiría `(-2, 0, 2)` dos veces.

# Ejercicio 8 Agua atrapada

## ¿Por qué el agua depende del menor de los dos máximos?

Cada columna `i` funciona como el fondo de un recipiente. La pared más alta a su izquierda mide `leftMax[i]` y la más alta a su derecha mide `rightMax[i]`. El agua sube hasta que se derrama por la pared más baja de las dos, por lo que el nivel del agua sobre esa columna es `min(leftMax[i], rightMax[i])`, y el agua atrapada es ese nivel menos la altura de la columna. Como ambos máximos incluyen la posición actual, el resultado nunca es negativo.

No basta con tomar las dos columnas más altas de todo el arreglo, porque cada columna tiene sus propias paredes limitantes. Caso propio `[5, 5, 0, 2, 0, 3]`:

|  i | height | leftMax | rightMax | agua |
|----|--------|---------|----------|------|
|  0 |      5 |       5 |        5 |    0 |
|  1 |      5 |       5 |        5 |    0 |
|  2 |      0 |       5 |        3 |    3 |
|  3 |      2 |       5 |        3 |    1 |
|  4 |      0 |       5 |        3 |    3 |
|  5 |      3 |       5 |        3 |    0 |

Total: **7**. Las dos columnas más altas son los dos `5`, que están juntas y no encierran agua entre ellas. Sin embargo, en las posiciones 2 a 4 la pared que limita el agua es el `3` de la derecha, que es menor que el `5` de la izquierda.

# Alcance de variables

En `printWaterTable` (`water.h`):

```c
for(int i = 0; i < size; i++){
    int agua = minInt(leftMax[i], rightMax[i]) - height[i];
    printf(...);
}
```

- `i` y `agua` se declaran dentro del `for`, por lo que solo existen dentro de él. `agua` se crea de nuevo en cada iteración y desaparece al terminarla; fuera del ciclo no puede usarse.
- `leftMax` y `rightMax` son variables locales de la función: existen desde su declaración hasta que la función termina. Sin embargo, los bloques a los que apuntan fueron reservados con `malloc` en el heap y no se liberan solos al terminar la función, por eso se llama a `free` antes de salir.
- `height` es un parámetro: también es local a la función, pero apunta al arreglo declarado en `main`, que sigue existiendo después de la llamada.

# Manejo de memoria: C vs C++

| Aspecto | C | C++ |
|---|---|---|
| Reservar | `malloc(n * sizeof(int))`, se calcula el tamaño en bytes | `new int[n]` o, preferiblemente, `std::vector<int> v(n)` |
| Liberar | `free` explícito en todos los caminos de salida | `std::vector` y los punteros inteligentes liberan solos al salir del alcance (RAII, destructores) |
| Fallo de reserva | `malloc` devuelve `NULL` y hay que comprobarlo | `new` lanza la excepción `std::bad_alloc` |
| Tamaño | El arreglo no conoce su tamaño; se pasa `size` como parámetro | `v.size()` |
| Copias | Asignar un puntero no copia; hay que reservar y copiar a mano (`copyArray`) | `std::vector<int> b = a;` hace una copia independiente |

En C toda la responsabilidad es del programador: por cada `malloc` debe haber exactamente un `free`, incluso cuando una reserva posterior falla (como en `trappedWater`, donde si falla `rightMax` se libera `leftMax` antes de devolver `-1`). En C++ con RAII esto lo garantiza el lenguaje, lo que reduce las fugas de memoria pero oculta el costo de las reservas.