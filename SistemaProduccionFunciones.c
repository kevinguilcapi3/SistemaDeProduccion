#include <stdio.h>
#include <string.h>
#include "SistemaProduccion.h"

void ingresarProductos(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int *n) {

    int i;

    printf("\nCuantos productos desea ingresar? Maximo 5: ");
    scanf("%d", n);

    if (*n > MAX) {
        *n = MAX;
    }

    for (i = 0; i < *n; i++) {

        printf("\nProducto %d\n", i + 1);

        printf("Nombre: ");
        scanf("%s", nombres[i]);

        printf("Cantidad demandada: ");
        scanf("%d", &cantidades[i]);

        printf("Tiempo por unidad: ");
        scanf("%f", &tiempos[i]);

        printf("Recursos por unidad: ");
        scanf("%f", &recursos[i]);
    }
}

int buscarProducto(char nombres[MAX][50], int n, char nombreBuscar[]) {

    int i;

    for (i = 0; i < n; i++) {

        if (strcmp(nombres[i], nombreBuscar) == 0) {
            return i;
        }
    }

    return -1;
}

void editarProducto(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int n) {

    char nombreBuscar[50];
    int posicion;

    printf("\nIngrese el nombre del producto a editar: ");
    scanf("%s", nombreBuscar);

    posicion = buscarProducto(nombres, n, nombreBuscar);

    if (posicion == -1) {

        printf("Producto no encontrado.\n");

    } else {

        printf("Nuevo nombre: ");
        scanf("%s", nombres[posicion]);

        printf("Nueva cantidad: ");
        scanf("%d", &cantidades[posicion]);

        printf("Nuevo tiempo por unidad: ");
        scanf("%f", &tiempos[posicion]);

        printf("Nuevo recurso por unidad: ");
        scanf("%f", &recursos[posicion]);

        printf("Producto editado correctamente.\n");
    }
}

void eliminarProducto(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int *n) {

    char nombreBuscar[50];
    int posicion;
    int i;

    printf("\nIngrese el nombre del producto a eliminar: ");
    scanf("%s", nombreBuscar);

    posicion = buscarProducto(nombres, *n, nombreBuscar);

    if (posicion == -1) {

        printf("Producto no encontrado.\n");

    } else {

        for (i = posicion; i < *n - 1; i++) {

            strcpy(nombres[i], nombres[i + 1]);

            cantidades[i] = cantidades[i + 1];

            tiempos[i] = tiempos[i + 1];

            recursos[i] = recursos[i + 1];
        }

        (*n)--;

        printf("Producto eliminado correctamente.\n");
    }
}

void calcularProduccion(int cantidades[], float tiempos[], float recursos[], int n) {

    int i;

    float tiempoTotal = 0;
    float recursosTotal = 0;

    float tiempoDisponible;
    float recursosDisponible;

    for (i = 0; i < n; i++) {

        tiempoTotal = tiempoTotal + cantidades[i] * tiempos[i];

        recursosTotal = recursosTotal + cantidades[i] * recursos[i];
    }

    printf("\nTiempo total requerido: %.2f\n", tiempoTotal);

    printf("Recursos totales requeridos: %.2f\n", recursosTotal);

    printf("Ingrese tiempo disponible: ");
    scanf("%f", &tiempoDisponible);

    printf("Ingrese recursos disponibles: ");
    scanf("%f", &recursosDisponible);

    if (tiempoTotal <= tiempoDisponible && recursosTotal <= recursosDisponible) {

        printf("La fabrica SI puede cumplir con la demanda.\n");

    } else {

        printf("La fabrica NO puede cumplir con la demanda.\n");
    }
}