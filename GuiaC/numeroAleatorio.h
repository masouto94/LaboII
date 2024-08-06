#include <time.h>

int randomNumber(int threshold){
    srand(time(NULL));
    return rand() % threshold +1;
}

void numeroAleatorio(){
    int threshold;
    int maxIntentos;
    int intento;
    printf("Ingrese el numero maximo para calcular\n");
    std::cin >> threshold;
    printf("Ingrese el numero maximo de intentos para jugar\n");
    std::cin >> maxIntentos;
    int numeroAdivinar = randomNumber(threshold);
    printf("#######################\n");
    while(intento != numeroAdivinar && maxIntentos > 0){
        printf("Elija el numero. Quedan %d intentos\n", maxIntentos);
        std::cin >> intento;
        maxIntentos -= 1;
    }
    if(intento == numeroAdivinar){
        printf("Ganaste!\n");
        return;
    }
    printf("Perdiste! El numero era %d", numeroAdivinar);
    return;



}
