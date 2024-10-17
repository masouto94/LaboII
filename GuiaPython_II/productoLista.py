# Escribe una funci ́on que reciba una lista de n ́umeros y devuelva el producto de
# todos sus elementos.

def producto_lista(lista:list) -> float:
    if len(lista) == 0:
        return 0
    result = lista[0]
    for i in range(1,len(lista)):
        result *= lista[i]
    return result
