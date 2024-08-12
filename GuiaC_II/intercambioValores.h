
void swapper(){
    int numA, numB, collector;
    int *numA_p = &numA,*numB_p = &numB;
    printf("Ingrese el primer numero:\n");
    scanf("%d", numA_p);
    printf("Ingrese el segundo numero:\n");
    scanf("%d", numB_p);
    printf("La variable numA tiene el valor: %d\n", numA);
    printf("La variable numB tiene el valor: %d\n", numB);
    collector = *numA_p;
    *numA_p = *numB_p;
    *numB_p= collector;
    printf("Ahora las swapeamos y quedan:\n");
    printf("numA: %d\n", numA);
    printf("numB: %d\n", numB);
}
