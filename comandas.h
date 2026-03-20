#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    HAMBURGUESA = 1,
    CURRY,
    PIZZA,
    PASTA,
    HOTDOG,
    POZOLE
} Platillo;


typedef struct {
    int id_mesa;
    int platillo;   
    int prioridad;
} Pedido;


struct nodo {
    Pedido info;
    struct nodo *siguiente;
};


typedef struct {
    struct nodo *frente;
    struct nodo *final;
} Cola;


void inicializar(Cola *c) {
    c->frente = NULL;
    c->final = NULL;
}


int vacia(Cola *c) {
    return c->frente == NULL;
}


void recibirComanda(Cola *c) {
    struct nodo *nuevo = malloc(sizeof(struct nodo));

    printf("Mesa: ");
    scanf("%d", &nuevo->info.id_mesa);

    printf("Platillo:\n");
    printf("1. Hamburguesa\n2. Curry\n3. Pizza\n4. Pasta\n5. Hotdog\n6. Pozole\n");
    scanf("%d", &nuevo->info.platillo);

    printf("Prioridad: ");
    scanf("%d", &nuevo->info.prioridad);

    nuevo->siguiente = NULL;

    if (vacia(c)) {
        c->frente = c->final = nuevo;
    } else {
        c->final->siguiente = nuevo;
        c->final = nuevo;
    }

    printf("Pedido agregado\n");
}


void servirPlatillo(Cola *c) {
    if (vacia(c)) {
        printf("No hay pedidos\n");
        return;
    }

    struct nodo *temp = c->frente;

    printf("Sirviendo mesa %d (platillo %d)\n",
           temp->info.id_mesa,
           temp->info.platillo);

    c->frente = c->frente->siguiente;

    if (c->frente == NULL)
        c->final = NULL;

    free(temp);
}


void verSiguiente(Cola *c) {
    if (vacia(c)) {
        printf("Cola vacía\n");
        return;
    }

    printf("Siguiente: Mesa %d (platillo %d)\n",
           c->frente->info.id_mesa,
           c->frente->info.platillo);
}


void verUltimo(Cola *c) {
    if (vacia(c)) {
        printf("Cola vacía\n");
        return;
    }

    printf("Último: Mesa %d (platillo %d)\n",
           c->final->info.id_mesa,
           c->final->info.platillo);
}

int main() {
    Cola c;
    int opcion;

    inicializar(&c);

    do {
        printf("\n--- RESTAURANTE ---\n");
        printf("1. Recibir comanda\n");
        printf("2. Servir platillo\n");
        printf("3. Ver siguiente\n");
        printf("4. Ver ultimo\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                recibirComanda(&c);
                break;
            case 2:
                servirPlatillo(&c);
                break;
            case 3:
                verSiguiente(&c);
                break;
            case 4:
                verUltimo(&c);
                break;
        }

    } while(opcion != 5);

    return 0;
}
