# 2. Ciclos anidados y Diccionarios
# Escribe una funci´on llamada crear tablero valores que:
# • Reciba dos n´umeros enteros n y m (n´umero de filas y columnas).
# • Devuelva un diccionario donde las claves sean las coordenadas (i, j) y los
# valores sean n´umeros enteros consecutivos, comenzando en 1.
# • Adem´as, si la posici´on (i, j) tiene ambos ´ındices pares, el valor se multiplica
# por 2.
# Ejemplo de entrada: n = 3, m = 2
# Ejemplo de salida: {(0,0): 2, (0,1): 2, (1,0): 3, (1,1): 4, (2,0): 10, (2,1): 6}

def crear_tablero(filas:int,columnas:int) -> dict:
    matriz = {}
    valor = 1
    for fila in range(filas):
        for columna in range(columnas):
            if (fila % 2 == 0) and (columna %2 == 0):
                matriz[(fila,columna)] = valor * 2
                valor +=1
                continue
            matriz[(fila,columna)] = valor
            valor +=1
    return matriz
