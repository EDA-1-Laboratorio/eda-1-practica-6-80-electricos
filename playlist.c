Playlist.c 
/* Implementación de playlist usando estructura de cola circular */
#include "playlist.h"

/* ========== OPERACIONES BÁSICAS DE COLA ========== */

void initialize(playlist *q) {
    q->cnt = 0;
    q->head = NULL;
    q->tail = NULL;
}

boolean empty(const playlist *q) {
    return (q->cnt == 0) ? VERDERO : FALSO;
}

boolean full(const playlist *q) {
    return (q->cnt >= FULL) ? VERDERO : FALSO;
}

data head(const playlist *q) {
    assert(!empty(q));
    return q->head->d;
}

data tail(const playlist *q) {
    assert(!empty(q));
    return q->tail->d;
}

/* Encolar al final (operación estándar de cola) */
void enqueue(data d, playlist *q) {
    if (full(q)) {
        printf("Error: La playlist esta llena :(\n");
        return;
    }
    
    /* Nota: Esta función espera que 'd' sea el ID de una canción */
    /* En una implementación real, necesitarías tener acceso al catálogo */
    printf("Encolando canción ID %u al FINAL\n", d);
    q->cnt++;
}

/* Desencolar del inicio */
data deque(playlist *q) {
    assert(!empty(q));
    
    elem *eliminar = q->head;
    data id = eliminar->d;
    
    q->head = q->head->next;
    
    if (q->head != NULL) {
        q->head->prev = NULL;
    } else {
        q->tail = NULL;
    }
    
    free(eliminar);
    q->cnt--;
    
    printf("Desencolando canción %u del INICIO\n", id);
    return id;
}

/* ========== OPERACIONES PARA PLAYLIST ========== */

/* Agregar canción al inicio */
void agregar_inicio(data d, playlist *q) {
    if (full(q)) {
        printf("Error: La playlist rsta llena\n");
        return;
    }
    
    /* Crear nuevo elemento */
    elem *nuevo = (elem*)malloc(sizeof(elem));
    if (nuevo == NULL) {
        printf("Error: No hay memoria\n");
        return;
    }
    
    /* Datos básicos (en un caso real, se copiarían del catálogo) */
    nuevo->d = d;
    strcpy(nuevo->titulo, "Canción temporal");
    strcpy(nuevo->artista, "Artista temporal");
    nuevo->duracion = 0;
    
    nuevo->prev = NULL;
    nuevo->next = q->head;
    
    if (q->head != NULL) {
        q->head->prev = nuevo;
    }
    
    q->head = nuevo;
    
    if (q->tail == NULL) {
        q->tail = nuevo;
    }
    
    q->cnt++;
    printf(" Canción %u agregada al INICIO\n", d);
}

/* Mostrar todas las canciones de la playlist */
void mostrar(const playlist *q) {
    if (empty(q)) {
        printf("\n-----------------------------\n");
        printf("   PLAYLIST VACÍA\n");
        printf("-----------------------------\n");
        return;
    }
    
    printf("\n-------------------------------------------------------\n");
    printf("   PLAYLIST (%d canciones)\n", q->cnt);
    printf("\n-------------------------------------------------------\n");
    
    elem *actual = q->head;
    int pos = 1;
    
    while (actual != NULL) {
        int minutos = actual->duracion / 60;
        int segundos = actual->duracion % 60;
        printf("%d. [ID:%u] %s - %s (%d:%02d)\n", 
               pos++, actual->d, actual->titulo, actual->artista, minutos, segundos);
        actual = actual->next;
    }
    printf("\n");
}

/* ========== FUNCIONES DEL CATÁLOGO ========== */

void init_catalogo(catalogo *cat) {
    cat->total = 10;
    
    cat->canciones[0].d = 1;
    strcpy(cat->canciones[0].titulo, "Feather");
    strcpy(cat->canciones[0].artista, "Nujabes");
    cat->canciones[0].duracion = 175;
    cat->canciones[0].prev = NULL;
    cat->canciones[0].next = NULL;
    
    cat->canciones[1].d = 2;
    strcpy(cat->canciones[1].titulo, "Mojabi Ghost");
    strcpy(cat->canciones[1].artista, "Bad Bunny");
    cat->canciones[1].duracion = 232;
    cat->canciones[1].prev = NULL;
    cat->canciones[1].next = NULL;
    
    cat->canciones[2].d = 3;
    strcpy(cat->canciones[2].titulo, "Así fue");
    strcpy(cat->canciones[2].artista, "Nelson Díaz");
    cat->canciones[2].duracion = 267;
    cat->canciones[2].prev = NULL;
    cat->canciones[2].next = NULL;
    
    cat->canciones[3].d = 4;
    strcpy(cat->canciones[3].titulo, "Hitchcock");
    strcpy(cat->canciones[3].artista, "Yorushika");
    cat->canciones[3].duracion = 222;
    cat->canciones[3].prev = NULL;
    cat->canciones[3].next = NULL;
    
    cat->canciones[4].d = 5;
    strcpy(cat->canciones[4].titulo, "Only You");
    strcpy(cat->canciones[4].artista, "Oden & Fatzo");
    cat->canciones[4].duracion = 167;
    cat->canciones[4].prev = NULL;
    cat->canciones[4].next = NULL;
    
    cat->canciones[5].d = 6;
    strcpy(cat->canciones[5].titulo, "Me hace daño verte");
    strcpy(cat->canciones[5].artista, "Fresto Music");
    cat->canciones[5].duracion = 300;
    cat->canciones[5].prev = NULL;
    cat->canciones[5].next = NULL;

    cat->canciones[6].d = 7;
    strcpy(cat->canciones[6].titulo, "Airplane Mode");
    strcpy(cat->canciones[6].artista, "Limbo");
    cat->canciones[6].duracion = 164;
    cat->canciones[6].prev = NULL;
    cat->canciones[6].next = NULL;

    cat->canciones[7].d = 8;
    strcpy(cat->canciones[7].titulo, "Koishii Hibi");
    strcpy(cat->canciones[7].artista, "Kaneko Ayano");
    cat->canciones[7].duracion = 202;
    cat->canciones[7].prev = NULL;
    cat->canciones[7].next = NULL;

    cat->canciones[8].d = 9;
    strcpy(cat->canciones[8].titulo, "sorry, I like you");
    strcpy(cat->canciones[8].artista, "Burbank");
    cat->canciones[8].duracion = 122;
    cat->canciones[8].prev = NULL;
    cat->canciones[8].next = NULL;

    cat->canciones[9].d = 10;
    strcpy(cat->canciones[9].titulo, "Ynlpa");
    strcpy(cat->canciones[9].artista, "Charles Ans");
    cat->canciones[9].duracion = 183;
    cat->canciones[9].prev = NULL;
    cat->canciones[9].next = NULL;

}

elem* buscar_cancion(const catalogo *cat, data id) {
    for (int i = 0; i < cat->total; i++) {
        if (cat->canciones[i].d == id) {
            return &(cat->canciones[i]);
        }
    }
    return NULL;
}

/* Función auxiliar para agregar canción con datos reales */
void agregar_cancion_a_playlist(elem *cancion, int al_inicio, playlist *q) {
    if (full(q)) {
        printf("Error: La playlist esta llena\n");
        return;
    }
    
    elem *nuevo = (elem*)malloc(sizeof(elem));
    if (nuevo == NULL) {
        printf("Error: No hay memoria\n");
        return;
    }
    
    /* Copiar todos los datos de la canción */
    nuevo->d = cancion->d;
    strcpy(nuevo->titulo, cancion->titulo);
    strcpy(nuevo->artista, cancion->artista);
    nuevo->duracion = cancion->duracion;
    
    if (al_inicio) {
        /* Agregar al inicio */
        nuevo->prev = NULL;
        nuevo->next = q->head;
        
        if (q->head != NULL) {
            q->head->prev = nuevo;
        }
        
        q->head = nuevo;
        
        if (q->tail == NULL) {
            q->tail = nuevo;
        }
        printf(" '%s' agregada al INICIO\n", cancion->titulo);
    } else {
        /* Agregar al final */
        nuevo->prev = q->tail;
        nuevo->next = NULL;
        
        if (q->tail != NULL) {
            q->tail->next = nuevo;
        }
        
        q->tail = nuevo;
        
        if (q->head == NULL) {
            q->head = nuevo;
        }
        printf(" '%s' agregada al FINAL\n", cancion->titulo);
    }
    
    q->cnt++;
}

/* ========== PROGRAMA PRINCIPAL ========== */

int main() {
    playlist mi_playlist;
    catalogo mi_catalogo;
    
    initialize(&mi_playlist);
    init_catalogo(&mi_catalogo);
    
    int opcion;
    data id;
    
    printf("\n-----------------------------------------\n");
    printf("            Mi Playlist ;)                \n");
    printf("-----------------------------------------\n");
    printf("\n");
    
    /* Mostrar catálogo */
    printf("\n=== CATÁLOGO DE CANCIONES ===\n");
    for (int i = 0; i < mi_catalogo.total; i++) {
        int min = mi_catalogo.canciones[i].duracion / 60;
        int seg = mi_catalogo.canciones[i].duracion % 60;
        printf("ID %u: %s - %s (%d:%02d)\n", 
               mi_catalogo.canciones[i].d,
               mi_catalogo.canciones[i].titulo,
               mi_catalogo.canciones[i].artista,
               min, seg);
    }
    
    do {
        printf("\n════════════════════════════════════════\n");
        printf("  MENÚ PRINCIPAL\n");
        printf("════════════════════════════════════════\n");
        printf("1. Agregar canción al INICIO\n");
        printf("2. Agregar canción al FINAL (enqueue)\n");
        printf("3. Eliminar canción del INICIO (deque)\n");
        printf("4. Eliminar canción del FINAL\n");
        printf("5. Mostrar playlist\n");
        printf("6. Ver catálogo\n");
        printf("7. Ver primera canción (head)\n");
        printf("8. Ver última canción (tail)\n");
        printf("0. Salir\n");
        printf("────────────────────────────────────────\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                printf("\n--- AGREGAR AL INICIO ---\n");
                printf("ID de canción: ");
                scanf("%u", &id);
                elem *c1 = buscar_cancion(&mi_catalogo, id);
                if (c1 != NULL) {
                    agregar_cancion_a_playlist(c1, 1, &mi_playlist);
                } else {
                    printf(" ID no válido\n");
                }
                break;
                
            case 2:
                printf("\n--- AGREGAR AL FINAL ---\n");
                printf("ID de canción: ");
                scanf("%u", &id);
                elem *c2 = buscar_cancion(&mi_catalogo, id);
                if (c2 != NULL) {
                    agregar_cancion_a_playlist(c2, 0, &mi_playlist);
                } else {
                    printf(" ID no válido\n");
                }
                break;
                
            case 3:
                printf("\n--- ELIMINAR DEL INICIO ---\n");
                if (!empty(&mi_playlist)) {
                    deque(&mi_playlist);
                } else {
                    printf("Playlist vacía\n");
                }
                break;
                
            case 4:
                printf("\n--- ELIMINAR DEL FINAL ---\n");
                if (!empty(&mi_playlist)) {
                    elem *ultimo = mi_playlist.tail;
                    printf(" '%s' eliminada del FINAL\n", ultimo->titulo);
                    
                    mi_playlist.tail = mi_playlist.tail->prev;
                    if (mi_playlist.tail != NULL) {
                        mi_playlist.tail->next = NULL;
                    } else {
                        mi_playlist.head = NULL;
                    }
                    free(ultimo);
                    mi_playlist.cnt--;
                } else {
                    printf("Playlist vacía\n");
                }
                break;
                
            case 5:
                mostrar(&mi_playlist);
                break;
                
            case 6:
                printf("\n=== CATÁLOGO DE CANCIONES ===\n");
                for (int i = 0; i < mi_catalogo.total; i++) {
                    int min = mi_catalogo.canciones[i].duracion / 60;
                    int seg = mi_catalogo.canciones[i].duracion % 60;
                    printf("ID %u: %s - %s (%d:%02d)\n", 
                           mi_catalogo.canciones[i].d,
                           mi_catalogo.canciones[i].titulo,
                           mi_catalogo.canciones[i].artista,
                           min, seg);
                }
                break;
                
            case 7:
                if (!empty(&mi_playlist)) {
                    data primero = head(&mi_playlist);
                    printf("Primera canción: %u\n", primero);
                } else {
                    printf("Playlist vacía\n");
                }
                break;
                
            case 8:
                if (!empty(&mi_playlist)) {
                    data ultimo = tail(&mi_playlist);
                    printf("Última canción: %u\n", ultimo);
                } else {
                    printf("Playlist vacía\n");
                }
                break;
                
            case 0:
                printf("\nFinalizando..........\n");
                break;
                
            default:
                printf("Opción inválida\n");
        }
        
    } while (opcion != 0);
    
    return 0;
}
