void verificarParidad(){
    int num;
    printf("Ingrese un numero:\n");
    std::cin >> num;
    if(num % 2){
        printf("%d es impar", num);
        return;
    }
    printf("%d es par", num);
    return;
}
