# Implementa una funci ́on que reciba dos listas y devuelva una nueva lista con los
# elementos que aparecen en ambas listas, sin duplicados.

def interseccion_listas(listaA:list, listaB:list) -> list:
    unicos_listaA = set(listaA)
    unicos_listaB = set(listaB)
    return list(unicos_listaA & unicos_listaB)
