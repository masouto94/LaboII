
int calcularFactorial(int tope){
    int base = 1;
    for(int i = 1; i <= tope;i++){
        base *= i;
    }
    return base;

}
void factorial(){
    int base;
    int * baseP = &base;
    do{
        printf("Ingrese un numero entero no negativo:\n");
        scanf("%d", baseP);
    }while(base < 0);
    printf("El factorial de %d es %d", base, calcularFactorial(base));

}
