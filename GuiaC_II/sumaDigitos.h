void sumaDigitos(){
    int number, suma = 0,colector;
    int * numberP = &number;
    printf("Ingrese un numero:\n");
    scanf("%d", numberP);
    colector = *numberP;
    do{
        suma += colector % 10;
        colector /= 10;
    }while(colector  > 0);
    printf("La suma de los digitos de %d es %d", number, suma);
}
