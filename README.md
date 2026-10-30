# Taller de programación imperativa en C

Curso: CE1106 Paradigmas de Programación — Instituto Tecnológico de Costa Rica

## Integrantes
- Marcelo Matey Rodriguez — Ejercicios 1, 2, 3 y 5
- Josué Pérez Pérez — Ejercicios 4, 6, 7 y 8

## Lenguaje
C (estándar C11)

## Estructura
| Archivo | Contenido |
|---|---|
| `main.c` | Casos de prueba de todos los ejercicios |
| `swap.h` | Ej. 1: intercambio de valores |
| `stats.h` | Ej. 2: estadísticas de un arreglo |
| `independent_copy.h` | Ej. 3: copia independiente |
| `sort.h` | Ej. 4: ordenamiento por inserción |
| `find_pair.h` | Ej. 5: dos valores que suman un objetivo |
| `threesum.h` | Ej. 6: 3Sum |
| `water.h` | Ej. 7: máximos acumulados y Ej. 8: agua atrapada |
| `Explicaciones.md` | Respuestas a las preguntas de cada ejercicio |

## Compilación y ejecución
```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o taller
./taller
```

## Resultados de las pruebas

### Ej. 1 — Intercambio
```
Antes:   a = -3, b = 9
Después: a = 9, b = -3
```
(`swap2`, que recibe valores en lugar de punteros, no modifica las variables.)

### Ej. 2 — Estadísticas de `[4, -2, 0, 7, -5]`
```
Suma: 4   Minimo: -5   Maximo: 7   Negativos: 2
Inverso: [-5, 7, 0, -2, 4]
```

### Ej. 3 — Copia independiente
```
Original: [4, -2, 0, 7, -5]
Copia:    [99, -2, 0, 7, -5]
```

### Ej. 4 — Ordenar una copia
```
Original: [4, -2, 0, 7, -5]
Ordenado: [-5, -2, 0, 4, 7]
```

### Ej. 5 — Búsqueda de pares
| Arreglo | Objetivo | Resultado |
|---|---|---|
| `[-4, -1, 0, 2, 5]` | 1 | (-4, 5) |
| `[-4, -1, 0, 2, 5]` | 8 | No existe |
| `[0, 0]` | 0 | (0, 0) |
| `[3]` | 6 | No existe |

### Ej. 6 — 3Sum
| Entrada | Ternas | Total |
|---|---|---|
| `[-1, 0, 1, 2, -1, -4]` | (-1, -1, 2), (-1, 0, 1) | 2 |
| `[0, 1, 1]` | Ninguna | 0 |
| `[0, 0, 0]` | (0, 0, 0) | 1 |
| `[0, 0, 0, 0]` | (0, 0, 0) | 1 |
| `[-2, 0, 0, 2, 2]` | (-2, 0, 2) | 1 |
| `[1, -1]` (tamaño insuficiente) | Ninguna | 0 |

### Ej. 7 — Máximos acumulados
```
height:   [3, 0, 2, 0, 4]
leftMax:  [3, 3, 3, 3, 4]
rightMax: [4, 4, 4, 4, 4]
```

### Ej. 8 — Agua atrapada
| Alturas | Agua total |
|---|---|
| `[5]` | 0 |
| `[0, 1, 2, 3]` | 0 |
| `[3, 2, 1, 0]` | 0 |
| `[2, 2, 2]` | 0 |
| `[3, 0, 3]` | 3 |
| `[3, 0, 2, 0, 4]` | 7 |
| `[4, 2, 0, 3, 2, 5]` | 9 |
| `[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]` | 6 |
| `[5, 5, 0, 2, 0, 3]` (caso propio) | 7 |

Tabla por posición del caso propio:
```
  i | height | leftMax | rightMax | agua
  0 |      5 |       5 |        5 |    0
  1 |      5 |       5 |        5 |    0
  2 |      0 |       5 |        3 |    3
  3 |      2 |       5 |        3 |    1
  4 |      0 |       5 |        3 |    3
  5 |      3 |       5 |        3 |    0
```