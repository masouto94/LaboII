//Basado en https://www.geeksforgeeks.org/bubble-sort-in-cpp/

void bubbleSort(int unsortedArr[], int arrSize)
{
    //Recorre el array N veces hasta la penultima posicion
    for (int globalIteration = 0; globalIteration < arrSize - 1; globalIteration++)
        //Para cada elemento del array hasta el global -1
        //cada vez que corre, se fija si el elemento X y el X+1 cumplen la condicion
        for (int position = 0; position < arrSize - globalIteration - 1; position++)
            if (unsortedArr[position] > unsortedArr[position + 1])
            //Si se cumple que el de la izquierda es mayor que el de la derecha, los swapea
                std::swap(unsortedArr[position], unsortedArr[position + 1]);
}
void ordenarNumeros(){
    int a,b,c;
    printf("Ingrese el primer numero:\n");
    std::cin >> a;
    printf("Ingrese el segundo numero:\n");
    std::cin >> b;
    printf("Ingrese el tercer numero:\n");
    std::cin >> c;
    //Se guardan
    int aOrdenar[3] = {a,b,c};
    int aOrdenarSize= sizeof(aOrdenar) / sizeof(aOrdenar[0]);

    bubbleSort(aOrdenar, aOrdenarSize);
    for(auto x: aOrdenar){
        printf("%d\n", x);
    }
}
