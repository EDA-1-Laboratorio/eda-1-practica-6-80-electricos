/* playlist.h - Lista de reproducción con estructura de cola circular */
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define    EMPTY    0
#define    FULL     10000
#define    MAX_TITULO 100
#define    MAX_ARTISTA 50

typedef    unsigned int         data;
typedef    enum {FALSO, VERDERO}   boolean;

/* Estructura para una canción (extiende elem con datos de canción y puntero doble) */
struct elem {
    data         d;              /* ID de la canción */
    char         titulo[MAX_TITULO];
    char         artista[MAX_ARTISTA];
    int          duracion;       /* Duración en segundos */
    struct elem  *prev;          /* Puntero al anterior (para lista doble) */
    struct elem  *next;          /* Puntero al siguiente */
};

typedef struct elem elem;

struct circular_queue {
    int         cnt;             /* Conteo de elementos en la playlist */
    elem        *head;           /* Apuntador al inicio de la playlist */
    elem        *tail;           /* Apuntador al final de la playlist */
};

typedef struct circular_queue playlist;

/* Catálogo de canciones */
struct catalogo {
    elem canciones[FULL];
    int total;
};

typedef struct catalogo catalogo;

/* Operaciones básicas de colas (manteniendo la interfaz original) */
void        initialize(playlist *q);
void        enqueue(data d, playlist *q);          /* Agregar al final */
data        deque(playlist *q);                    /* Eliminar del inicio */
data        head(const playlist *q);
data        tail(const playlist *q);
boolean     empty(const playlist *q);
boolean     full(const playlist *q);

/* Operaciones adicionales para playlist (ejercicio 3) */
void        agregar_inicio(data d, playlist *q);   /* Agregar canción al inicio */
void        mostrar(const playlist *q);            /* Mostrar playlist */
void        init_catalogo(catalogo *cat);          /* Inicializar catálogo */
elem*       buscar_cancion(const catalogo *cat, data id); /* Buscar por ID */

#endif
