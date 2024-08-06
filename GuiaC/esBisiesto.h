bool checkLeapYear(int year){
    if(year % 400 == 0){
        return true;
    }
    if(year % 4 == 0){
        if(year % 100 != 0){
            return true;
        }
    }
    return false;
}
void esBisiesto(){
    int year;
    printf("Ingrese un anio:\n");
    std::cin >> year;
    if(checkLeapYear(year)){
        printf("El anio %d es bisiesto",year);
        return;
    }
    printf("El anio %d no es bisiesto",year);
    return;
}
