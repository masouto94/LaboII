int getSize(char charArray[]){
    int arrSize = 0;
    for(int i=0; charArray[i] != '\0';i++){
        arrSize++;
    }
    return arrSize -1;
}
void stringLength(){
    char cadena[STRMAXLEN];
    printf("Ingrese una cadena de texto: (Max= 50)\n");
    fgets(cadena, STRMAXLEN, stdin);
    fflush(stdin);
    printf("La cadena tiene %d elementos\n", getSize(cadena));
    printf("Con strlen es %d", strlen(cadena));
}
