from typing import List
from funcionesAuxMatriz import validar_matriz
def transponer_matriz(matriz: List[list]):
    validar_matriz(matriz)
    columnas = len(matriz[0])
    return [[fila[i] for fila in matriz] for i in range(columnas)]
