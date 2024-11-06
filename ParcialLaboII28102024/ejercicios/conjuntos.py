# Crea una funci´on llamada analizar sets que reciba dos listas de n´umeros en-
# teros. Convierte ambas listas en conjuntos y realiza lo siguiente:
# • Devuelve el conjunto que contiene los elementos comunes entre las dos
# listas.
# 1
# • Luego, devuelve el conjunto resultante de la diferencia sim´etrica entre los
# dos conjuntos.
# • Finalmente, crea un conjunto con los valores ´unicos de los conjuntos orig-
# inales que sean m´ultiplos de 4 y que no est´en en la intersecci´on.
# • Todos los resultados deben ser devueltos como una tupla de conjuntos.
# Ejemplo de entrada: [1, 2, 3, 4, 8], [3, 4, 5, 8, 12]
# Ejemplo de salida: ({3, 4, 8}, {1, 2, 5, 12}, {12})

def analizar_sets(lista_izq:list, lista_der:list) -> set:
    set_izq,set_der = set(lista_izq), set(lista_der)
    interseccion = set_izq & set_der
    diferencia_simetrica = set_izq ^ set_der
    subset = {num for num in diferencia_simetrica if num %4 ==0}
    return tuple([interseccion,diferencia_simetrica,subset])
