from ejercicios.listasYCondicionales import filtrar_y_modificar
from ejercicios.ciclosAnidados import crear_tablero
from ejercicios.conjuntos import analizar_sets
from ejercicios.decoradores import suma,resta
from ejercicios.clases import Cilindro
from ejercicios.pilaresPOO import respuestas

def main():
    #Ejercicio 1
    lista_nums = [4, 15, 8, 7, 14, 12, 5]
    print(filtrar_y_modificar(lista_nums))
    print("#"*10)
    #Ejercicio 2
    print(crear_tablero(3,2))
    print("#"*10)
    #Ejercicio 3
    print(analizar_sets([1, 2, 3, 4, 8], [3, 4, 5, 8, 12]))
    print("#"*10)
    #Ejercicio 4
    #Menores o iguales
    print(suma(5,3))
    print(resta(13,3))
    #Mayores
    print(suma(10,6))
    print(resta(14,3))
    print("#"*10)
    #Ejercicio 5
    cilindro = Cilindro(22,12)
    print(cilindro.__dict__)
    print(cilindro.area(),cilindro.volumen())
    cilindro.cambiar_dimensiones(10,11)
    print(cilindro.__dict__)
    print("#"*10)
    #Ejercicio 6
    respuestas()
    print("#"*10)
    
if __name__ =='__main__':
    main()
