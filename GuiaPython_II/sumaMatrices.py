# Implementa una funci ́on que reciba dos matrices (listas de listas) de igual
# tama ̃no y devuelva su suma
from typing import List
from funcionesAuxMatriz import validar_matriz

def sumar_matrices(matrizA: List[list],matrizB: List[list]) -> List[list]:
    validar_matriz(matrizA)
    validar_matriz(matrizB)
    matriz_sumada = []
    for matriz_l, matriz_r in zip(matrizA,matrizB):
        matriz_sumada.append([matriz_l[i] + matriz_r[i] for i in range(len(matriz_l))])
    return matriz_sumada
