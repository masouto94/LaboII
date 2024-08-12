void mayorEntreDos(){
    int numA,numB;
    int *numA_p = &numA, *numB_p = &numB;
    printf("Ingrese el numero A:\n");
    scanf("%d", numA_p);
    printf("Ingrese el numero B:\n");
    scanf("%d", numB_p);
    if(*numA_p > *numB_p ){
        printf("%d es mayor que %d", *numA_p,*numB_p);
        return;
    }
    if(*numA_p < *numB_p ){
        printf("%d es mayor que %d", *numB_p,*numA_p);
        return;
    }
    printf("%d es igual que %d", *numA_p,*numB_p);
    return;
}
