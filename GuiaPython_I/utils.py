from typing import Tuple
import re
from unidecode import unidecode

def pedir_numeros_enteros(cantidad:int) -> Tuple[int]:
    """
    Pide al usuario ingresar `cantidad` de numeros y devuelve una tupla con los numeros casteados a `int`
    """
    numeros_a_devolver = []
    for i in range(cantidad):
        try:
            numero_ingresado = input(f"Ingrese el numero {i+1}:\n")
            numeros_a_devolver.append(int(numero_ingresado))
        except ValueError as e:
            print(f"'{numero_ingresado}' no puede interpretarse como entero...ignorando")
            continue
    return tuple(numeros_a_devolver)

def normalizar_input(input_crudo:str) -> str:
    """
    Devuelve un string en minuscula y sin caracteres especiales.
    Unidecode transforma las letras con acentos a las basicas `casi` a la perfeccion.`re.sub` borra todo lo que matchea con el patron y `.lower()` al final pasa todo a minuscula
    """
    remover_no_alfanumericos = r"\W+"
    return unidecode(
        re.sub(remover_no_alfanumericos,"",input_crudo)
        ).lower()