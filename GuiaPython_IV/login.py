# Desarrolla un sistema de autenticaci ́on que gestione el inicio de sesi ́on de usuar-
# ios. Usa un decorador para verificar las credenciales del usuario antes de per-
# mitirle acceder a una funci ́on protegida (por ejemplo, una funci ́on que muestre
# un mensaje de bienvenida). Implementa un decorador adicional para limitar el
# n ́umero de intentos fallidos de inicio de sesi ́on.
from typing import Callable
from os.path import isfile, join,dirname
from csv import reader,writer

def generar_admin() -> tuple:
    user = input("Ingrese el user\n")
    password = input("Ingrese la contraseña\n")
    print(f"Se va a crear el admin como user:'{user}' password:'{password}'\n")
    confirmar = input(f"Confirma? [y/n]\n")
    if confirmar.lower() == "n":
        return generar_admin()
    return tuple([user,password,False])

def obtener_usuarios(db) -> dict:
    with open(db, "r") as readFile:
        csvreader = reader(readFile)
        saltar_encabezado = False
        usuarios = {}
        for fila in csvreader:
            if not saltar_encabezado:
                saltar_encabezado = True
                continue
            usuarios[fila[0]] = {"password": fila[1],"isLoggedIn": fila[2]}
    return usuarios

def insertar_usuario(user:str,password:str,session:bool,db):
    if user in obtener_usuarios(db).keys():
        print(f"El usuario {user} ya existe")
        return
    session_row = (user,password,session,)
    with open(db, "a+") as db_:
        csvwriter = writer(db_)
        csvwriter.writerow(session_row)

def inicializar_db(path:str):
    if not isfile(path):
        with open(path, "w") as createFile:
            csvwriter = writer(createFile)    
            csvwriter.writerow(["user","password","loggedIn"])
            csvwriter.writerow(generar_admin())


def esta_logueado(intento_logueo:Callable):
    def verificar_credenciales():
        user, password = intento_logueo

    return verificar_credenciales

path_a_db = join(dirname(__file__),"db/base.txt")
inicializar_db(path_a_db)
insertar_usuario("carlos","memen", False, path_a_db)
users = obtener_usuarios(path_a_db)