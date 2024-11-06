# 1. Listas y Condicionales
# Dada una lista de n´umeros enteros, escribe una funci´on llamada modificar numeros
# que:
# • Remueva todos los n´umeros impares que est´en en posiciones impares de
# la lista (basado en el ´ındice).
# • Devuelva una lista donde cada n´umero par en posici´on par sea dividido
# entre 2 si es mayor a 10, o multiplicado por 3 si es menor o igual a 10.
# Ejemplo de entrada: [4, 15, 8, 7, 14, 12, 5]
# Ejemplo de salida: [6, 4, 7]

def filtrar_y_modificar(lista:list) -> list:
    transformado = []
    es_par = lambda num: num %2 == 0
    es_impar=lambda num: num %2 != 0
    
    filtrado = filter(lambda num: (es_impar(num) and lista.index(num) % 2 == 0) or es_par(num), lista)

    for index, num in enumerate(filtrado):
        if es_par(index) :
            if es_par(num) :
                if num <= 10:
                    transformado.append(num * 3)
                elif num > 10:
                    transformado.append(int(num/2))
                continue
        transformado.append(num)
    return transformado
