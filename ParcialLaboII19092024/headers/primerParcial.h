//
// Created by matias on 19/09/24.
//

#ifndef PRIMERPARCIAL_H
#define PRIMERPARCIAL_H

#endif //PRIMERPARCIAL_H
#include "index.h"
void loadLoop(char * file_path) {
    int size=1;
    int cohetesCreados =0;
    int id_cohete;
    char nombre[50];
    float capacidad_carga;
    int numero_lanzamientos;
    int misiones_completadas;

    Cohete * cohetesArray = (Cohete *) malloc(sizeof(Cohete) * size);
    if(cohetesArray == NULL) {
        printf("No se pudo alocar memoria para cohetesArray\n");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese el id del cohete: (0 para terminar)\n");
    scanf("%d", &id_cohete);
    while(getchar() != '\n');
    do {
        printf("Ingrese el nombre del cohete\n");
        fgets(nombre,sizeof(nombre),stdin);
        nombre[strcspn(nombre,"\n")] = 0;

        printf("Ingrese el capacidad de carga en kgs\n");
        scanf("%f", &capacidad_carga);
        while(getchar() != '\n');

        printf("Ingrese el numero de lanzamientos\n");
        scanf("%d", &numero_lanzamientos);
        while(getchar() != '\n');

        printf("Ingrese la cantidad de misiones completadas con exito\n");
        scanf("%d", &misiones_completadas);
        while(getchar() != '\n');

        Cohete nuevoCohete = crearCohete(id_cohete,nombre,capacidad_carga,numero_lanzamientos,misiones_completadas);
        cohetesCreados++;
        if(cohetesCreados > size ) {
            size = cohetesCreados;
            cohetesArray= (Cohete *) realloc(cohetesArray, size * sizeof(Cohete));
        }
        cohetesArray[size-1] = nuevoCohete;

        printf("Ingrese el id del cohete: (0 para terminar)\n");
        scanf("%d", &id_cohete);
        while(getchar() != '\n');
    }while(id_cohete !=0);
    FILE *f = fopen(file_path, "wb");
    if (f == NULL) {
        printf("Error abriendo archivo\n");
        exit(EXIT_FAILURE);
    }
    fwrite(cohetesArray, sizeof(Cohete), size, f);
    fclose(f);
    free(cohetesArray);
}
