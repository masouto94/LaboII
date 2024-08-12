void parOImpar(){
    int num;
    void * numP = &num;
    printf("Ingrese un numero: \n");
    scanf("%d", (int *) numP);
    if (num % 2 == 0){
        printf("%d es par\n",num);
        return;
    }
    printf("%d es impar\n",num);
    return;
}
