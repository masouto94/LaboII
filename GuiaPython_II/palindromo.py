# Escribe un programa que verifique si una cadena es un pal ́ındromo, es decir, si
# se lee igual de adelante hacia atr ́as como de atr ́as hacia adelante.
from preprocesarCadena import preprocesar_cadena
def es_palindromo(cadena:str) -> bool:
    if not cadena:
        return False
    head= 0
    tail = len(cadena) -1
    while head < tail:
        if cadena[head] != cadena[tail]:
            return False
        head += 1
        tail -= 1
    return True

def comprobar_palindromo():
    cadena = input("Ingrese una cadena\n")
    procesada = preprocesar_cadena(cadena)
    unificado = "".join(procesada)
    print(f"{cadena} es palindromo: {es_palindromo(unificado)}")
