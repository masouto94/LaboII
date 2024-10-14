# Escribe una funci ́on que reciba una cadena y devuelva un diccionario con la
# frecuencia de cada car ́acter en la cadenafrom typing import List
from collections import Counter

def caracteres_unicos():
    cadena = input("Ingrese una cadena de caracteres\n")
    contador = Counter(list(cadena))
    print(f"Los caracteres son {dict(contador)}")
