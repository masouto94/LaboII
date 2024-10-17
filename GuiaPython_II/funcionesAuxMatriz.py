from typing import List

class MatrizVacia(Exception):
    pass
class MatrizInvalida(Exception):
    pass

def validar_matriz(matriz: List[list])->None:
    """Valida que la matriz provista tenga todas las filas iguales y  que no esté vacía"""
    if len(matriz) == 0:
        raise MatrizVacia("La matriz no tiene valores")
    if len(matriz) >= 1:
        if len(matriz[0]) == 0:
            raise MatrizVacia("La matriz tiene una fila vacía")
    cols = len(matriz[0])
    for row in matriz:
        if len(row) != cols:
            raise MatrizInvalida(f"La fila {row} tiene un largo distinto a {cols}")