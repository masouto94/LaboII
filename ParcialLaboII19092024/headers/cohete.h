//
// Created by matias on 19/09/24.
//

#ifndef COHETE_H
#define COHETE_H

#endif //COHETE_H

typedef struct Cohete{
    int id_cohete;
    char nombre[50];
    float capacidad_carga;
    int numero_lanzamientos;
    int misiones_completadas;
}Cohete;

void displayCohete(Cohete *cohete) {
    printf("##########:\n");
    printf("ID: %d\n", cohete->id_cohete);
    printf("Nombre: %s\n", cohete->nombre);
    printf("Capacidad carga: %.2f\n", cohete->capacidad_carga);
    printf("Lanzamientos: %d\n", cohete->numero_lanzamientos);
    printf("Misiones completadas: %d\n", cohete->misiones_completadas);
    printf("##########:\n");
}

Cohete crearCohete(int id_cohete, char nombre[50], float capacidad_carga, int numero_lanzamientos, int misiones_completadas) {
    Cohete newCohete;
    newCohete.id_cohete = id_cohete;
    strcpy(newCohete.nombre, nombre);
    newCohete.capacidad_carga = capacidad_carga;
    newCohete.numero_lanzamientos = numero_lanzamientos;
    newCohete.misiones_completadas = misiones_completadas;
    return newCohete;
}
void borrarCohete(Cohete* coheteArray, int id_cohete, int * size) {
    char confirm;
    for (int i = 0; i < *size; i++) {
        if (coheteArray[i].id_cohete == id_cohete) {
            printf("Queres borrar el cohete?: (y/n)\n");
            displayCohete(&coheteArray[i]);
            scanf("%c", &confirm);
            while(getchar() != '\n');
            if (confirm != 'Y' && confirm != 'y') {
                printf("Cancelado\n");
                return;
            }
            while(i < *size) {
                coheteArray[i] = coheteArray[i + 1];
                i++;
            };
            *size -=1;
            return;
        }
    }
}
void modificarCohete(Cohete *cohetesArray, int size, int id_cohete) {
    char nombre[50];
    float capacidad_carga;
    int numero_lanzamientos;
    int misiones_completadas;
    char modify = 'n';
    for (int i = 0; i < size; i++) {
        if (cohetesArray[i].id_cohete == id_cohete) {
            printf("Modificando cohete con id %d\n", cohetesArray[i].id_cohete);
            printf("Modificar nombre? (y/n)\n");
            scanf("%c", &modify);
            while (getchar() != '\n');
            if (modify == 'y' || modify == 'Y') {
                printf("Ingrese nuevo nombre: \n");
                fgets(nombre, sizeof(nombre), stdin);
                strcpy(cohetesArray[i].nombre, nombre);
            }
            printf("Modificar capacidad de carga? (y/n)\n");
            scanf("%c", &modify);
            while (getchar() != '\n');
            if (modify == 'y' || modify == 'Y') {
                printf("Ingrese nueva capacidad de carga: \n");
                scanf("%f", &capacidad_carga);
                cohetesArray[i].capacidad_carga = capacidad_carga;
            }
            printf("Modificar lanzamientos? (y/n)\n");
            scanf("%c", &modify);
            while (getchar() != '\n');
            if (modify == 'y' || modify == 'Y') {
                printf("Ingrese la nueva cantidad de lanzamientos: \n");
                scanf("%d", &numero_lanzamientos);
                cohetesArray[i].numero_lanzamientos = numero_lanzamientos;
            }
            printf("Modificar misiones exitosas? (y/n)\n");
            scanf("%c", &modify);
            while (getchar() != '\n');
            if (modify == 'y' || modify == 'Y') {
                printf("Ingrese la nueva cantidad de misiones exitosas: \n");
                scanf("%d", &misiones_completadas);
                cohetesArray[i].misiones_completadas = misiones_completadas;
            }
            return;
        }
    }
        printf("No existe el cohete con ID %d \n", id_cohete);
}

void leerCohetesDeArchivo(FILE *archivo, Cohete *cursor) {
    fseek(archivo, 0, SEEK_END);
    int size = ftell(archivo);
    int cohetesAmount = size / sizeof(Cohete);
    fseek(archivo, 0, SEEK_SET);
    fread(cursor, sizeof(Cohete), 1, archivo);
    for (int i = 0; i < cohetesAmount; i++) {
        displayCohete(cursor);
        fread(cursor, sizeof(Cohete), 1, archivo);
    }
}

Cohete * cargarCohetesDeArchivo(FILE *archivo, Cohete *cursor, int* total) {
    fseek(archivo, 0, SEEK_END);
    int size = ftell(archivo);
    int cohetesAmount = size / sizeof(Cohete);
    *total = cohetesAmount;
    Cohete * cohetes = (Cohete*)malloc(size);
    fseek(archivo, 0, SEEK_SET);
    fread(cursor, sizeof(Cohete), 1, archivo);
    for (int i = 0; i < cohetesAmount; i++) {
        cohetes[i] = *cursor;
        fread(cursor, sizeof(Cohete), 1, archivo);
    }
    return cohetes;
}


void realizarLanzamiento(Cohete* coheteArray, int size, int id_cohete, float carga) {
    for (int i = 0; i < size; i++) {
        if (coheteArray[i].id_cohete == id_cohete) {
            if (coheteArray[i].capacidad_carga >= carga) {
                printf("Nuevo lanzamiento con: %.2f kgs de carga para %s\n", carga, coheteArray[i].nombre);
                coheteArray[i].numero_lanzamientos += 1;
                printf("Lanzamientos totales para %s: %d\n", coheteArray[i].nombre, coheteArray[i].numero_lanzamientos);
                return;
            }
            printf("El peso %.2f excede la capacidad de carga de %s\n", carga, coheteArray[i].nombre);
            printf("Capacidad de carga %.2f\n", coheteArray[i].capacidad_carga);
            return;
        }
    }
    printf("No existe el cohete con id %d\n", id_cohete);
}

void reportarMisiones(Cohete * cohetesArray, int size) {
    int misionesCompletadas = 0;
    int maxMisionesCompletadas = 0;
    int minMisionesCompletadas = 0;
    int mejorCoheteIndex, peorCoheteIndex;
    for (int i = 0; i < size; i++) {
        if(cohetesArray[i].misiones_completadas > maxMisionesCompletadas) {
            maxMisionesCompletadas = cohetesArray[i].misiones_completadas;
            mejorCoheteIndex = i;
        }
        if((cohetesArray[i].misiones_completadas < minMisionesCompletadas) || minMisionesCompletadas == 0) {
            minMisionesCompletadas = cohetesArray[i].misiones_completadas;
            peorCoheteIndex = i;
        }
        misionesCompletadas += cohetesArray[i].misiones_completadas;
    }
    float promedioMisionesCompletadas = (float)misionesCompletadas / size;
    printf("##########\n");
    printf("REPORTE DE MISIONES\n");
    printf("##########\n");
    printf("Cantidad total de misiones completadas: %d\n", misionesCompletadas);
    printf("Promedio de misiones completadas: %.2f\n", promedioMisionesCompletadas);
    printf("##########\n");
    printf("Mejor desempeno: %s\n", cohetesArray[mejorCoheteIndex].nombre);
    printf("Cantidad de misiones exitosas: %d\n", maxMisionesCompletadas);
    printf("##########\n");
    printf("Peor desempeno: %s\n", cohetesArray[peorCoheteIndex].nombre);
    printf("Cantidad de misiones exitosas: %d\n", minMisionesCompletadas);
    printf("##########\n");
}

void realizarMantenimiento(Cohete * cohetesArray, int size, FILE *archivo) {
    for (int i = 0; i < size; i++) {
        if(cohetesArray[i].numero_lanzamientos > 5) {
            fprintf(archivo,"##########:\n");
            fprintf(archivo,"ID: %d\n", cohetesArray[i].id_cohete);
            fprintf(archivo,"Nombre: %s\n", cohetesArray[i].nombre);
            fprintf(archivo,"Capacidad carga: %.2f\n", cohetesArray[i].capacidad_carga);
            fprintf(archivo,"Lanzamientos: %d\n", cohetesArray[i].numero_lanzamientos);
            fprintf(archivo,"Misiones completadas: %d\n", cohetesArray[i].misiones_completadas);
            fprintf(archivo,"##########:\n");
        }
    }
}