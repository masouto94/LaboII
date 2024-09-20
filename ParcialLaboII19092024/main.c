#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/primerParcial.h"
void mostrarOpciones() {
    printf("###############\n");
    printf("0: TERMINAR\n");
    printf("1: CARGAR COHETES\n");
    printf("2: LISTAR COHETES\n");
    printf("3: MODIFICAR COHETES\n");
    printf("4: BORRAR COHETES\n");
    printf("5: REALIZAR LANZAMIENTO\n");
    printf("6: REPORTAR MANTENIMIENTO\n");
    printf("7: REPORTAR MISIONES\n");
    printf("###############\n");
}
int main(void)
{
    Cohete cursor;
    int total=0;
    int * pTotal = &total;
    Cohete * listaCohetes;
    int idCohete;
    float cargaTrabajo;
    char archivoBin[50];
    char archivoMantenimiento[50];

    printf("Iniciando gestion de productos\n");
    int opcion;
    do {
        mostrarOpciones();
        printf("Ingrese una opcion:\n");
        scanf("%d", &opcion);
        while (getchar() != '\n');
        switch (opcion) {
            case 0:
                printf("Programa terminado:\n");
                exit(EXIT_SUCCESS);
            case 1:
                printf("Ingrese la ruta al archivo donde se guardara:\n");
                fgets(archivoBin, sizeof(archivoBin), stdin);
                loadLoop(archivoBin);
                printf("Se cargo todo en %s:\n", archivoBin);
                FILE * p_archivoBin = fopen(archivoBin, "rb");
                if (p_archivoBin == NULL) {
                    printf("Error abriendo archivo %s\n",archivoBin);
                    exit(EXIT_FAILURE);
                }
                listaCohetes = cargarCohetesDeArchivo(p_archivoBin, &cursor, pTotal);
                break;
            case 2:
                for(int i=0; i < total; i++) {
                    displayCohete(&listaCohetes[i]);
                }
                break;
            case 3:
                printf("Ingrese el id a modificar:\n");
                scanf("%d", &idCohete);
                while (getchar() != '\n');
                modificarCohete(listaCohetes, *pTotal, idCohete);
                break;
            case 4:
                printf("Ingrese el ID a borrar:\n");
                scanf("%d", &idCohete);
                while (getchar() != '\n');
                borrarCohete(listaCohetes, idCohete, pTotal);
                break;
            case 5:
                printf("Ingrese el ID del cohete a lanzar:\n");
                scanf("%d", &idCohete);
                while (getchar() != '\n');
                printf("Ingrese la carga a enviar\n");
                scanf("%f", &cargaTrabajo);
                while (getchar() != '\n');
                realizarLanzamiento(listaCohetes,*pTotal, idCohete, cargaTrabajo);
                break;
            case 6:
                printf("Ingrese la ruta al archivo donde se guardara:\n");
                fgets(archivoMantenimiento, sizeof(archivoMantenimiento), stdin);
                FILE * p_mantenimiento = fopen(archivoMantenimiento, "w+");
                if (p_mantenimiento == NULL) {
                    printf("Error abriendo archivo %s\n",archivoMantenimiento);
                    exit(EXIT_FAILURE);
                }
                realizarMantenimiento(listaCohetes, *pTotal, p_mantenimiento);
                printf("Reporte almacenado en %s\n", archivoMantenimiento);
                break;
            case 7:
                reportarMisiones(listaCohetes, *pTotal);
                break;
            default:
                printf("Opcion incorrecta\n");
                break;

        }
    }while(opcion != 0);
    return 0;
}
