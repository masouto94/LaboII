//
// Created by matias on 12/09/24.
//

#ifndef EJERCICIOS_MEMORIA_H
#define EJERCICIOS_MEMORIA_H
#include <stdio.h>

#endif //EJERCICIOS_MEMORIA_H

void ejercicio_1() {
    int value;

    printf("Ingrese un valor entero\n");
    scanf("%d", &value);
    int *pval = (int*)malloc(sizeof(value));
    *pval = value;
    printf("El valor de valor de *pval es: %d\n", *pval);
    free(pval);
}

void ejercicio_2() {
    /*Escribe un programa que solicite al usuario ingresar el tama˜no de un vector.
    Luego, utiliza malloc() para asignar memoria din´amica para el vector y permite
    al usuario ingresar los elementos del vector. Despu´es, imprime los elementos del
    vector y libera la memoria asignada.*/
    int vecSize;
    printf("Ingrese el largo del vector\n");
    scanf("%d", &vecSize);
    int * vector = (int *) malloc(vecSize *sizeof(int));
    for (int i = 0; i < vecSize; i++) {
        printf("Ingrese el valor de [%d]\n", i);
        scanf("%d", &vector[i]);
    }
    printf("################\n");
    for (int i = 0; i < vecSize; i++) {
        printf("%d\n", vector[i]);
    }
    free(vector);
}

void ejercicio_3() {
    /*Escribe un programa que solicite al usuario ingresar el tama˜no de dos vectores.
    Luego, utiliza malloc() para asignar memoria din´amica para ambos vectores
    y permite al usuario ingresar los elementos de ambos vectores. Despu´es, suma
    los dos vectores elemento por elemento y almacena el resultado en un tercer
    vector din´amico. Finalmente, imprime el vector resultante y libera la memoria
    asignada*/
    int vecSize;
    printf("Ingrese el largo de los vectores\n");
    scanf("%d", &vecSize);
    int * vectorA = (int *) malloc(vecSize *sizeof(int));
    if(vectorA == NULL) {
        printf("Error al alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    int * vectorB = (int *) malloc(vecSize *sizeof(int));
    if(vectorB  == NULL) {
        printf("Error al alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    int * vectorC = (int *) malloc(vecSize *sizeof(int));
    if(vectorC == NULL) {
        printf("Error al alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < vecSize; i++) {
        printf("Ingrese el valor de [%d] para el vectorA\n", i);
        scanf("%d", &vectorA[i]);
    }
    for (int i = 0; i < vecSize; i++) {
        printf("Ingrese el valor de [%d] para el vectorB\n", i);
        scanf("%d", &vectorB[i]);
    }
    printf("################\n");
    for (int i = 0; i < vecSize; i++) {
        vectorC[i] = vectorA[i] + vectorB[i];
        printf("%d\n", vectorC[i]);
    }
    free(vectorA);
    free(vectorB);
    free(vectorC);
}

void ejercicio_4() {
    /*Escribe un programa que solicite al usuario ingresar el n´umero de filas y colum-
    nas de una matriz. Luego, utiliza malloc() para asignar memoria din´amica para
    la matriz y permite al usuario ingresar los elementos de la misma. Despu´es, cal-
    cula la matriz transpuesta y almacena el resultado en otra matriz din´amica.
    Finalmente, imprime la matriz transpuesta y libera la memoria asignada*/
    int rows,cols;
    printf("Ingrese el numero de filas\n");
    scanf("%d", &rows);
    printf("Ingrese el numero de columnas\n");
    scanf("%d", &cols);
    int ** matrix =  (int **) malloc(rows * sizeof(int *));
    if(matrix == NULL) {
        printf("Error al alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *) calloc(cols, sizeof(cols));
        if(matrix[i] == NULL) {
            printf("Error al alocar memoria\n");
            exit(EXIT_FAILURE);
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Ingrese el valor [%d][%d]\n",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int ** matrix_T =  (int **) malloc(cols * sizeof(int *));
    if(matrix_T == NULL) {
        printf("Error al alocar memoria\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < cols; i++) {
        matrix_T[i] = (int *) calloc(rows, sizeof(rows));
        if(matrix_T[i] == NULL) {
            printf("Error al alocar memoria\n");
            exit(EXIT_FAILURE);
        }
    }
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++) {
            matrix_T[i][j] = matrix[j][i];
            printf("Matrix_T[%d][%d] => %d\n",i,j,matrix_T[i][j]);
        }
    }
    free(matrix);
    free(matrix_T);
    
}