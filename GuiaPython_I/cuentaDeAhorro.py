def calcular_interes_compuesto(capital_inicial:float, interes:float, periodos:int) -> float:
    return capital_inicial * pow((1+interes), periodos)

def interes_compuesto() -> None:
    """
    Crea un programa que simule una cuenta de ahorro. El usuario ingresa la
    cantidad de dinero que quiere ahorrar mensualmente. El programa debe calcular
    cu ́anto dinero habr ́a acumulado en un a ̃no considerando un inter ́es fijo mensual
    del 50%
    """
    capital = input("Ingrese el capital inicial:\n")
    try:
        capital = float(capital)
    except ValueError:
        print("El capital ingresado es invalido")
    interes = input("Ingrese el interes mensual (en porcentaje):\n")
    try:
        interes = float(interes/100)
    except ValueError:
        print("El interes ingresado es invalido")
    periodos = input("Ingrese los periodos:\n")
    try:
        periodos = int(periodos)
    except ValueError:
        print("El periodo ingresado es invalido")
    print(calcular_interes_compuesto(capital,interes,periodos))
