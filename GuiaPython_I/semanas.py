# Requerir al usuario que ingrese un d ́ıa de la semana e imprimir un mensaje de-
# pendiendo del d ́ıa ingresado: un mensaje diferente para lunes, otro para viernes,
# otro para s ́abado o domingo. Si el d ́ıa ingresado no es ninguno de esos, imprimir
# un mensaje indicando que el d ́ıa ingresado no es v ́alido

from utils import normalizar_input

def frase_por_dia(dia:str, mensaje:str=None) -> None:
    mensajes = {
        "domingo": "Se casa Peringo",
        "lunes": "Segundo peor dia de la semana",
        "martes": "Peor dia de la semana",
        "miercoles": "Se corta con un after",
        "jueves": "El after tuvo consecuencias",
        "viernes": "Dia de planazos",
        "sabado": "Limpia la casa",
    }
    normalizado = normalizar_input(dia)
    if normalizado not in mensajes.keys():
        print(f"{normalizado} no es un dia valido")
        return
    if mensaje:
        print(f"{normalizado} => {mensaje}")
        return
    print(f"{normalizado} => {mensajes.get(normalizado)}")