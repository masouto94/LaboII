void validarEdad(){
    int edad;
    printf("Ingrese su edad:\n");
    std::cin >> edad;
    if(edad >= 18){
        printf("Bienvenido/a");
        return;
    }
    printf("Acceso denegado");
}
