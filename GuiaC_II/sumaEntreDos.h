void sumaEntreDos(){
    int collector,suma = 0;
    void * collectorP = &collector;
    printf("Ingrese el numero A:\n");
    scanf("%d",  (int*)collectorP);
    suma += *(int *) collectorP;
    printf("Ingrese el numero B:\n");
    scanf("%d", collectorP);
    suma += *(int *) collectorP;
    printf("La suma es %d", suma);
}
