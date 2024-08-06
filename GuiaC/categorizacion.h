void categorizarEdad(){
    int edad;
    char* categoria;
    printf("Ingrese una edad:\n");
    std::cin >> edad;
    if(edad >= 18){
        categoria = "adulto";
    }
    else if(edad >= 13 && edad < 18){
        categoria = "adolescente";
    }
    else{
        categoria = "ninio";
    }
    printf("Alguien de %d es un %s", edad, categoria);
    return;
}
