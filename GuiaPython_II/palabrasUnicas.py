# Crea un programa que cuente la cantidad de palabras  ́unicas en un texto ingre-
# sado por el usuario. Ignora las may ́usculas y min ́usculas
from typing import List
from collections import Counter
from preprocesarCadena import preprocesar_cadena

def palabras_unicas():
    cadena = input("Ingrese una cadena de caracteres\n")
    procesado = preprocesar_cadena(cadena)
    contador = Counter(procesado)
    print(f"Los 5 mas repetidos son {contador.most_common(5)}")

def palabras_totales():
    cadena = input("Ingrese una cadena de caracteres\n")
    procesado = preprocesar_cadena(cadena)
    print(f"En total son {len(procesado)} palabras")
