void tablasMultiplicar(){
    int baseTabla;
    printf("Ingrese un numero para calcular la tabla:\n");
    std::cin >> baseTabla;
    printf("#########################\n");
    for(int i = 1; i <= 10; i++){
    printf("%d x %d = %d\n", baseTabla, i, i*baseTabla);
    }
    return;
}
