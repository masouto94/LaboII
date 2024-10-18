from typing import Callable
from csv import reader,writer
from login import obtener_usuarios, validar_existe,validar_credenciales,esta_logueado

def validar_unico(intento_insert:Callable):
    def usuario_es_unico(*args):
        user,*_,db = args
        if user in obtener_usuarios(db).keys():
            print(f"ERROR: El usuario {user} ya existe")
            return 
        intento_insert(*args)
    return usuario_es_unico

@validar_unico
def insertar_usuario(user:str,password:str,session:bool,db):
    session_row = (user,password,session,False,)
    with open(db, "a+") as db_:
        csvwriter = writer(db_)
        csvwriter.writerow(session_row)

@validar_existe
def modificar_password(user:str,password_nueva:str,db):
    data = []
    with open(db, "r") as db_:
        csvreader = reader(db_)
        for row in csvreader:
            if row[0] == user:
                data.append([user,password_nueva,True,False])
                continue
            data.append(row)
    with open(db, "w") as db_:
        csvwriter = writer(db_)
        csvwriter.writerows(data)