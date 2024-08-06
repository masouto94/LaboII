
void ordenarNumeros(){
    int a,b,c;
    printf("Ingrese el primer numero:\n");
    std::cin >> a;
    printf("Ingrese el segundo numero:\n");
    std::cin >> b;
    printf("Ingrese el tercer numero:\n");
    std::cin >> c;
    int aOrdenar[3] = {a,b,c};
    int ordenado[3]= {a,b,c};
    for(int i = 0; i < 3; i++){

        for(int j=0; j < 3;j++){
            if(ordenado[i] < aOrdenar[i]){
                ordenado[i] = aOrdenar[i];
            }
        }
    }
    for (auto x: ordenado){
        printf("%d\n", x);
    }
}
