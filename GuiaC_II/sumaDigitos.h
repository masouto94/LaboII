int sumDigits(std::string &numberString, int lenNumberString){
    int sum = 0;
    for(int i = 0; i < lenNumberString; i++){
        sum += (int) numberString[i];
    }
    return sum;
}
void sumaDigitos(){
    std::string numberString;
    const char * numberStringP = numberString.data();
    printf("Ingrese un numero:\n");
    scanf("%s", numberStringP);
    printf("%s", numberString);
    printf("La suma de los digitos de %s es %d", numberString, sumDigits(numberString, numberString.length()));
}
