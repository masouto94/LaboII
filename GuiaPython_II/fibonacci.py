def fibonacci(tope:int) -> int:
    """Funcion recursiva que devuelve el numero de fibonacci para cada posicion"""
    if tope < 2:
        return tope
    else:
        return fibonacci(tope-1) + fibonacci(tope-2)

def fibonacci_a_lista(tope:int) -> list:
    """Funcion que retorna la lista con cada uno de los numeros de fibonacci"""
    return [fibonacci(i) for i in range(tope)]
