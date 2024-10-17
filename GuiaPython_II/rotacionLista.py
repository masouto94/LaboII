def rotar_lista_izq(lista:list, posiciones:int) -> list:
    normalizar_offset = posiciones % len(lista)
    return lista[normalizar_offset:] + lista[:normalizar_offset]

#Mejor sería usar deques directamente
from collections import deque
def rotar_lista_izq_alt(lista:list, posiciones:int) -> list:
    lista_como_deque = deque(lista)
    #Se rota a la izquierda al rotar las posiciones en negativo
    lista_como_deque.rotate(-posiciones)
    #Castea a lista para devolver el mismo tipo de dato
    return list(lista_como_deque)
