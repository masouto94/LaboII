void calcularGastos(){
    float gastos;
    float item;
    printf("Ingrese montos:\n");
    printf("Ingrese '0' para terminar:\n");
    do{
        std::cin >> item;
        gastos += item;

    }while(item != 0);
    printf("El total de gastos es %.2f", gastos);
}
