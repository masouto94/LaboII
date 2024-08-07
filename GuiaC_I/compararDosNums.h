void compararDosNums(){
    int numA,numB;
    printf("Ingrese el primer numero entero:\n");
    std::cin >> numA;
    printf("Ingrese el segundo numero entero:\n");
    std::cin >> numB;
    if(numA < numB){
        printf("El numero %d es mas grande", numB);
        return;
    }
    else if(numB < numA){
        printf("El numero %d es mas grande", numA);
        return;
    }
    printf("El primer y segundo numero son iguales");
    return;

}
