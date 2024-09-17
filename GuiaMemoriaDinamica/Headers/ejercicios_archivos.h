//
// Created by matias on 16/09/24.
//

#ifndef EJERCICIOS_ARCHIVOS_H
#define EJERCICIOS_ARCHIVOS_H

#endif //EJERCICIOS_ARCHIVOS_H

void archivos_ejercicio_1() {
    char nombre[100];
    FILE * archivo = fopen("../Headers/archivos/prueba.txt","w");
    if (archivo != NULL) {
        for (int i = 0; i < 2; i++) {
        printf("Ingrese el nombre para el archivo:\n");
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strcspn(nombre,"\n")] = '\0';
        fputs(nombre, archivo);
        fputs("\n", archivo);

        }
        fclose(archivo);
    }
}

void read_file(FILE * file_path) {
    if (file_path != NULL) {
        char cursor = getc(file_path);
        while (cursor != EOF) {
            printf("%c", cursor);
            cursor = getc(file_path);
        }
        if(feof(file_path)) {
            fclose(file_path);
        }
    }
}
int search_in_file(FILE * file_path, char * nombre) {
    int nombreSize = strlen(nombre);
    int hits=0;
    int ocurrences = 0;
    if (file_path != NULL) {
        char cursor = getc(file_path);
        while (cursor != EOF) {
            if (cursor == nombre[0]) {
                for (int i = 0; i < nombreSize; i++) {
                    if (cursor != nombre[i]) {
                        hits = 0;
                        break;
                    }
                    hits++;
                    if( hits == nombreSize){
                        ocurrences++;
                        hits=0;
                    };
                    cursor = getc(file_path);
                }
            }
        cursor = getc(file_path);
        }
    }
    return ocurrences;
}
void archivos_ejercicio_2() {
    FILE * archivo = fopen("../Headers/archivos/prueba.txt","r");
    char * v = "hola";
    printf("%s aparece %d veces", v, search_in_file(archivo, v));
}

void archivos_ejercicio_3() {
    int num;
FILE *pArchivo;

pArchivo=fopen("../Headers/archivos/prueba.dat","wb");

if(pArchivo!=NULL){
    do{
        printf("Ingrese un numero de dni, para terminar 0 (cero):");
        scanf("%d",&num);
        fflush(stdin);
        if(num!=0)
            fwrite(&num,sizeof(int),1,pArchivo);
    }while (num > 0);
    fclose(pArchivo);
}else{printf("Error en la apertura del archivo");}
    getchar();

}
void archivos_ejercicio_4() {
    FILE *pArchivo = fopen("../Headers/archivosBinarios/prueba.dat","rb");;
    int num;
    void * reader = &num;
    if(pArchivo!=NULL){
        fread((int*)reader,sizeof(int),1,pArchivo);
        while(!feof(pArchivo)){
            printf("%d\n", *(int*) reader);
            fread((int*)reader,sizeof(int),1,pArchivo);
        }
        fclose(pArchivo);
    }
    else{printf("Error en la apertura del archivo");}
    getchar();
}

typedef struct Cat {
    char name[10];
    int age;
} Cat;
void archivos_ejercicio_5() {
    int size,edad;
    char nombre[10];
    FILE *pArchivo=fopen("../Headers/archivosBinarios/catprueba.dat","wb");
    Cat * reader;

    printf("Ingrese el tamano del vector\n");
    scanf("%d", &size);
    while(getchar()!='\n');
    Cat * catVector = (Cat *) malloc(size * sizeof(Cat));
    for(int i = 0; i < size; i++) {
        printf("Ingrese el nombre de [%d]\n", i);
        fgets(nombre,10,stdin);
        nombre[strcspn(nombre,"\n")] = '\0';
        strcpy(catVector[i].name, nombre);
        printf("Ingese la edad de [%d]", i);
        scanf("%d", &edad);
        while(getchar()!='\n');
        catVector[i].age = edad;
    }
    for(int i = 0; i < size; i++) {
        fwrite(&catVector[i],sizeof(Cat),1,pArchivo);
    }
    free(catVector);
    fclose(pArchivo);

    pArchivo = fopen("../Headers/archivosBinarios/catprueba.dat","rb");
    if(pArchivo!=NULL){
        fread(reader,sizeof(Cat),1,pArchivo);
        while(!feof(pArchivo)){
            printf("%s => %d\n", reader->name,reader->age);
            fread(reader,sizeof(Cat),1,pArchivo);
        }
        fclose(pArchivo);
    }

}

void vector_from_file() {
    FILE * pArchivo = fopen("../Headers/archivos/data.txt","r");
    int cursor = fgetc(pArchivo);
    while(!feof(pArchivo)) {
        printf("%c", cursor);
        cursor = fgetc(pArchivo);
    }
    //fscanf(pArchivo,"%d\n",)
}