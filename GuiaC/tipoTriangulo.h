void calcularTipoTriangulo(){
    float A,B,C;
    char* tipoTirangulo;
    printf("El programa devuelve que tipo de triangulo es segun sus lados.\n");
    printf("Ingrese el largo del lado A.\n");
    std::cin >> A;
    printf("Ingrese el largo del lado B.\n");
    std::cin >> B;
    printf("Ingrese el largo del lado C.\n");
    std::cin >> C;
    if( (A == B) && (B == C)){
        tipoTirangulo = "equilatero";
    }
    else if((A == B) || (B == C) || (A == C)){
        tipoTirangulo = "isoceles";
    }
    else{
        tipoTirangulo = "escaleno";
    }
    printf("El triangulo con lados A:%.3f, B:%.3f, C:%.3f es %s",A,B,C,tipoTirangulo);
}
