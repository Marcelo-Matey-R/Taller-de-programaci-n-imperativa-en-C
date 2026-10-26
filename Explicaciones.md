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

# Ejercicio 5 Dos valores que suman un objetivo.

## Pregunta 1: Explique por qué puede descartarse un extremo después de comparar la suma.

Esto se debe a que la lista está ordenada ascendentemente.

Sean `left` y `right` los índices actuales del arreglo, donde `left < right`. Debido al ordenamiento, se cumple estrictamente que:

> `values[left] <= values[right]`

Esto nos permite descartar un extremo bajo las siguientes reglas:

* **Si la suma actual es mayor que el `target`:** Dado que `values[right]` es el valor más grande disponible en ese rango, sumarlo con cualquier otro elemento hacia la derecha de `left` seguirá dando un resultado demasiado alto. Por lo tanto, podemos descartar el extremo derecho de forma segura reduciendo el índice (`right--`) para buscar una suma más pequeña.

* **Si la suma actual es menor que el `target`:** Por el caso inverso, sumarle al elemento más pequeño (`values[left]`) cualquier valor menor a `values[right]` nunca alcanzará el objetivo. Por ende,  descartamos el extremo izquierdo aumentando el índice (`left++`).