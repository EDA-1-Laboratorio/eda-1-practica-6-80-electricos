/* Una implementación de cola mediante una lista ligada */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define    EMPTY    0
#define    FULL     10000

typedef    unsigned int         data;
typedef    enum {FALSO, VERDERO}   boolean;

struct elem {          // Un elemento en la cola.
    data         d;
    struct elem  *next;
};

typedef    struct elem           elem;
struct circular_queue {
    int         cnt;                            // Conteo de los elementos de la cola.
    elem        *head;                          // Apuntador al 'head' de la cola.
    elem        *tail;                          // Apuntador al 'tail' de la cola.
};

typedef     struct circular_queue          circular_queue;        // Definimos el tipo de dato cola (queue, se pronuncia "quiu").

/* Operaciones básicas de colas */
void        initialize(circular_queue *q);               // Inicializar una cola.
void        enqueue(data d, circular_queue *q);          // Encolar (agregar) un elemento (por tail).
data        deque(circular_queue *q);                    // Desencolar (quitar) un elemento (por head). Lo que se devuelve es el elemento apuntado por 'head'.
data        head(const circular_queue *q);               // ¿Cuál es el elemento al inicio de la cola?
data        tail(const circular_queue *q);               // ¿Cuál es el elemento al final de la cola?
boolean     empty(const circular_queue *q);              // ¿La cola está vacía?
boolean     full(const circular_queue *q);               // ¿La cola está llena (10000 elementos)?
