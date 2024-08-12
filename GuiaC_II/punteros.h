void punteros(){
    int edad = 10;
    int * edad_p = &edad;
    printf("Valor original %d\n", edad);
    printf("Direccion de la variable %p\n", &edad);
    printf("Valor del puntero %p\n", edad_p);
    printf("Desreferenciando %d\n", *edad_p);
    void * void_p;
    printf("Un void es lo que le pidas. Con char* es: %d. Con double* es: %d\n", sizeof(*(char* )void_p),sizeof(*(double* )void_p));
    printf("Punteros a punteros:\n");
    int x = 22;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;
    printf("X vale %d\n",x);
    printf("El valor al que apunta ptr1 %d\n", *ptr1);
    printf("El valor final al que apunta ptr2 es %d\n", **ptr2);
    printf("El valor intermedio al que apunta ptr2 es %p. Que es el valor que está guardado en ptr1 => %p \n", *ptr2, ptr1);


}

void ejercicioIntegrador(){
    void *cantidad_p;
    int cantidad;
    cantidad_p = &cantidad;
    int numeroActual;
    int * numeroActual_p = &numeroActual;
    int suma=0,producto =1;
    printf("Ingrese la cantidad denumeros que desea procesar\n");
    scanf("%d", (int*)cantidad_p);
    for(int i = 1; i <= *(int * )cantidad_p; i++){
        printf("Ingrese el numero %d\n", i);
        scanf("%d", numeroActual_p);
        suma+= *numeroActual_p;
        producto *= *numeroActual_p;
    }
    printf("La suma es %d\n",suma);
    printf("El producto es es %d\n",producto);
    //Para probar reusar ese puntero para otra cosa
//    char lala = 'P';
//    cantidad_p = &lala;
//    printf("Ahora cantidad_p es un char: %c", *(char*)cantidad_p);

}
