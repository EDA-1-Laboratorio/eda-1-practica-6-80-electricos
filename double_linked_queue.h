/* Una implementación de cola mediante una lista ligada */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define    EMPTY    0
#define    FULL     10000

typedef    unsigned int         data;
typedef    enum {FALSO, VERDERO}   boolean;

struct node{
    data d;
    struct node *next; //Un apuntador al siguiente nodo
    struct node *prev; //Un apuntador al anterior nodo
};

typedef struct node node;

struct double_linked_queue{
    int cnt;
    node *head;
    node *tail;
}

typedef     struct double_linked_queue          double_linked_queue;        // Definimos el tipo de dato cola (queue, se pronuncia "quiu").

/* Operaciones básicas de colas */
void        initialize(double_linked_queue *q);               // Inicializar una cola.
void        enqueue(data d, double_linked_queue *q);          // Encolar (agregar) un elemento (por tail).
data        deque(double_linked_queue *q);                    // Desencolar (quitar) un elemento (por head). Lo que se devuelve es el elemento apuntado por 'head'.
data        head(const double_linked_queue *q);               // ¿Cuál es el elemento al inicio de la cola?
data        tail(const double_linked_queue *q);               // ¿Cuál es el elemento al final de la cola?
boolean     empty(const double_linked_queue *q);              // ¿La cola está vacía?
boolean     full(const double_linked_queue *q);               // ¿La cola está llena (10000 elementos)?
