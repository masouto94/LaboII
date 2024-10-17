# Escribe una funci ́on que reciba una lista y devuelva una nueva lista sin elementos
# duplicados, manteniendo el orden original

def remover_duplicados(lista:list) -> list:
    return list(set(lista))
