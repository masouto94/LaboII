def esBisiesto(anio:int) -> None:
    if (anio % 400 == 0) or ( (anio % 4 == 0) & (anio % 10 != 0) ):
        print(f"{anio} es bisiesto")
        return
    print(f"{anio} no es bisiesto")
