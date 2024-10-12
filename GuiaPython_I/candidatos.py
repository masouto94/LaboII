from utils import normalizar_input

def votar_candidato() -> str:
    return input("Ingrese el candidato a votar\n")

def abrir_votacion(candidatos:dict)->None:
    """
    Recibe un diccionario `candidatos` cuya clave sera el nombre del candidato y el valor su partido.
    Hasta que no se ingrese solo un enter, va a seguir sumando
    """
    #Inicializa conteo de votos en 0 para cada candidato
    conteo = {}
    for candidato in candidatos.keys():
        candidato_normalizado = normalizar_input(candidato)
        conteo[candidato_normalizado] = 0
    es_horario_votacion = True
    while es_horario_votacion:
        voto = votar_candidato()
        if not voto:
            es_horario_votacion = False
            continue
        voto_normalizado = normalizar_input(voto)
        if voto_normalizado not in conteo.keys():
            print(f"{voto} no es un candidato valido")
            continue
        conteo[voto_normalizado] = conteo.get(voto_normalizado) + 1
    print("#"*10)
    print("Se cerraron las urnas")
    print("#"*10)
    #Retorna la clave del valor maximo
    ganador = max(conteo, key=conteo.get)
    print(f"El ganador es {ganador} del partido {candidatos.get(ganador)} con {conteo.get(ganador)} votos")
    