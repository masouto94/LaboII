from typing import List
def transponer_matriz(matriz: List[list]):
    columnas = len(matriz[0])
    return [[fila[i] for fila in matriz] for i in range(columnas)]
