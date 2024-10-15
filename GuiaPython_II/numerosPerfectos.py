# Crea un programa que encuentre todos los n ́umeros perfectos en un rango dado.
# Un n ́umero perfecto es un n ́umero que es igual a la suma de sus divisores propios
# positivos (excluyendo el n ́umero mismo)
from typing import List
EXPONENTES = [2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583, 25964951, 30402457, 32582657, 37156667, 42643801, 43112609, 57885161]
def formula_euclideana(exponente:int) -> int:
    return pow(2,exponente-1) * (pow(2,exponente) - 1)

def obtener_numeros_perfectos(numero:int) -> List[int]:
    """Retorna una lista con hasta 48 numeros perfectos dado el numero de techo"""
    numeros_perfectos= []
    for num in range(1,numero+1):
        if num in EXPONENTES:
            numeros_perfectos.append(formula_euclideana(num))
    return numeros_perfectos
