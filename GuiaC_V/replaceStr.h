void replaceStr(){
    char cadena[STRMAXLEN];
    char repl;
    char * ptr;
    printf("Ingrese cadena (MAX 50):\n");
    fgets(cadena, STRMAXLEN, stdin);
    printf("Ingrese caracter de reemplazo:\n");
    repl = getchar();

    char nueva[strlen(cadena)];
    ptr = strrchr(cadena, (int) repl);
        if(ptr == NULL){
            strcpy(nueva,cadena);
            printf("%s",nueva);
            return;
        }
    for(int i = 0; i <= strlen(cadena); i++){
        if(cadena[i]==repl){
            nueva[i] = '_';
            continue;
        }
        nueva[i] = cadena[i];
    }
    printf("%s",nueva);
}
