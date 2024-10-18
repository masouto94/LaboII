# Desarrolla un sistema de autenticaci ́on que gestione el inicio de sesi ́on de usuar-
# ios. Usa un decorador para verificar las credenciales del usuario antes de per-
# mitirle acceder a una funci ́on protegida (por ejemplo, una funci ́on que muestre
# un mensaje de bienvenida). Implementa un decorador adicional para limitar el
# n ́umero de intentos fallidos de inicio de sesi ́on.
from typing import Callable
from os.path import isfile
from csv import reader,writer

def validar_existe(intento_login:Callable):
    def usuario_existe(*args):
        user,*_,db = args
        if user in obtener_usuarios(db).keys():
            intento_login(*args)
            return 
        print(f"ERROR: El usuario {user} ya existe")
    return usuario_existe

def validar_credenciales(intento_login:Callable):
    def credenciales_correctas(*args):
        user,password,db = args
        if obtener_usuarios(db).get(user).get("password") == password:
            intento_login(*args)
            return 
        print(f"ERROR: Las credenciales son incorrectas")
    return credenciales_correctas

def esta_logueado(intento_logueo:Callable):
    def verificar_estado_login(*args):
        user,*_,db = args
        if obtener_usuarios(db).get(user).get("isLoggedIn") == 'False':
            intento_logueo(*args)
            return
        print(f"El usuario {user} ya está logueado") 
    return verificar_estado_login

def generar_admin() -> tuple:
    user = input("Ingrese el user admin\n")
    password = input("Ingrese la contraseña\n")
    print(f"Se va a crear el admin como user:'{user}' password:'{password}'\n")
    confirmar = input(f"Confirma? [y/n]\n")
    if confirmar.lower() == "n":
        return generar_admin()
    return tuple([user,password,False,True])

def obtener_usuarios(db) -> dict:
    with open(db, "r") as readFile:
        csvreader = reader(readFile)
        saltar_encabezado = False
        usuarios = {}
        for fila in csvreader:
            if not saltar_encabezado:
                saltar_encabezado = True
                continue
            usuarios[fila[0]] = {"password": fila[1],"isLoggedIn": fila[2],"isAdmin": fila[3]}
    return usuarios

def inicializar_db(path:str):
    if not isfile(path):
        with open(path, "w") as createFile:
            csvwriter = writer(createFile)    
            csvwriter.writerow(["user","password","loggedIn","isAdmin"])
            csvwriter.writerow(generar_admin())

@validar_existe
@validar_credenciales
@esta_logueado
def login_usuario(user:str,password:str,db):
    data = []
    with open(db, "r") as db_:
        csvreader = reader(db_)
        for row in csvreader:
            if row[0] == user:
                data.append([row[0],row[1],True,False])
                continue
            data.append(row)
    with open(db, "w") as db_:
        csvwriter = writer(db_)
        csvwriter.writerows(data)

@validar_existe
@validar_credenciales
def logout_usuario(user:str,password:str,db):
    data = []
    with open(db, "r") as db_:
        csvreader = reader(db_)
        for row in csvreader:
            if row[0] == user:
                data.append([row[0],row[1],False,False])
                continue
            data.append(row)
    with open(db, "w") as db_:
        csvwriter = writer(db_)
        csvwriter.writerows(data)
