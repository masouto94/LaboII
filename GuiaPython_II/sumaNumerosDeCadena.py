import re

def sumar_numeros_de_cadena(cadena: str) -> int:
    numeros = r"(?P<numero>\d+)"
    matches = re.findall(numeros, cadena)
    if matches:
        return sum([int(match) for match in matches])
    return 0
