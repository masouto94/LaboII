void printVector(char* cadena){
    for (int i=0; cadena[i] != '\0'; i++){
        printf("%c => [index] %d\n", cadena[i],i);
    }
}
void vectorCadena(){
    //mutable
    char cadena[] = "Hola";
    //inmutable
    //char * cadena = "Hola";
    printf("%s\n",cadena);
    printVector(cadena);
}
