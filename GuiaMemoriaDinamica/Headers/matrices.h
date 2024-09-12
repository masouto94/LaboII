//
// Created by matias on 12/09/24.
//

#ifndef MATRICES_H
#define MATRICES_H

#endif //MATRICES_H
enum  DAYTIME {
    MORNING,
    AFTERNOON,
    NIGHT,
    TOTALTIMES
} DAYTIME;

void populateMatrix(int data,int rows, int cols, int ** matrix) {
    if(matrix == NULL) {
        return;
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
                matrix[r][c] = data;
                data *= 2;
        }
    }
}
void printMatrix(int rows, int cols, int ** matrix) {
    if(matrix == NULL) {
        printf("Matrices are NULL\n");
        return;
    }
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("Fila %d Columna %d => %d\n",r,c,matrix[r][c]);
        }
    }
}
int ** createMatrix(int rows, int cols) {
    int ** matrix = malloc( rows * sizeof(int*));
    if(matrix == NULL) {
        printf("Failed to create matrix\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<rows;i++) {
        matrix[i]= calloc(cols,cols*sizeof(cols));
        if(matrix[i] == NULL) {
            printf("Failed to create row %d\n",i);
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}
void matrix_base() {
    int DAYS = 7;
    int data = 2;

    int ** weekMatrix= createMatrix(DAYS,TOTALTIMES);
    populateMatrix(data,DAYS,TOTALTIMES,weekMatrix);
    printMatrix(DAYS, TOTALTIMES, weekMatrix);
    free(weekMatrix);
}
