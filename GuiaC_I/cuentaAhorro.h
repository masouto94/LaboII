float interesCompuesto(int plazoEnMeses, float montoInicial){
    float montoFinal;
    for(int mes=0; mes < plazoEnMeses; mes++){
        montoFinal += montoInicial;
        montoFinal *= 1.35;
    }
    return montoFinal;
}

void ahorroAnual(){
    float monto;
    printf("Ingrese el monto promedio que se va a ahorrar por mes:\n");
    std::cin >> monto;
    printf("En 12 meses, con un interes fijo de 35 porciento por mes, al ingresar %.2f por mes tendras:\n", monto);
    printf("%.2f", interesCompuesto(12,monto));
    return;
}
