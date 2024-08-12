void mayorEntreDos(){
    int colector, maximo;
    int * colectorP = &colector;
    printf("Ingrese el numero A:\n");
    scanf("%d", (int*)colectorP);
    maximo = *(int*)colectorP;
    printf("Ingrese el numero B:\n");
    scanf("%d", (int*)colectorP);
    if(maximo > *(int*)colectorP){
        printf("%d es mayor que %d", maximo,*(int*)colectorP);
        return;
    }
    if(maximo < *(int*)colectorP ){
        printf("%d es mayor que %d", *(int*)colectorP, maximo);
        return;
    }
    printf("%d es igual que %d", maximo, *(int*)colectorP);
    return;
}
