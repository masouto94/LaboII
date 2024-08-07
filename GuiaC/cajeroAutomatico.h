
void consultarSaldo(float saldo){
    printf("El saldo es %.2f\n",saldo);
}


void realizarRetiro(float &saldo, float monto){
    if(monto < 0){
        printf("Monto invalido\n");
        return;
    }
    saldo -= monto;
    printf("Se retiraron %.2f correctamente\n",monto);
    printf("El nuevo saldo es %.2f\n",saldo);
}

void realizarDeposito(float &saldo, float monto){
    saldo += monto;
    printf("Se depositaron %.2f correctamente\n",monto);
    printf("El nuevo saldo es %.2f\n",saldo);
}

void resetOpcion(int &opcion){
    opcion = 0;
}

void cajeroAutomatico(){
    int opcion;
    float monto;
    float saldo = 0;

    printf("Iniciando cajero automatico...\n");
    while(
        opcion != 1 &&
        opcion != 2 &&
        opcion != 3 &&
        opcion != 4
    ){
        printf("Elija una opcion:\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Realizar retiro\n");
        printf("3 - Realizar deposito\n");
        printf("4 - Salir\n");
        std::cin >> opcion;

        switch(opcion){
        case 1:
            consultarSaldo(saldo);
            resetOpcion(opcion);
            break;
        case 2:
            printf("Ingrese el monto a retirar:\n");
            std::cin >> monto;
            if((saldo - monto) < 0){
                printf("No tiene saldo suficiente para retirar %.2f\n", monto);
                printf("Su saldo es %.2f\n", saldo);
                resetOpcion(opcion);
                break;
            }
            realizarRetiro(saldo,monto);
            resetOpcion(opcion);
            break;
        case 3:
            printf("Ingrese el monto a depositar:\n");
            std::cin >> monto;
            if(monto <= 0){
                printf("El monto a ingresar debe ser mayor a 0\n");
                resetOpcion(opcion);
                break;
            }
            realizarDeposito(saldo,monto);
            resetOpcion(opcion);
            break;
        case 4:
            printf("Gracias por utilizar el sistema\n");
            return;
        default:
            printf("Opcion invalida\n");
            resetOpcion(opcion);
            break;
        }
    }

}
