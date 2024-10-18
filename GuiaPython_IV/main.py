from login import *
from abmUsuario import * 
from os.path import join,dirname

def main():
    path_a_db = join(dirname(__file__),"db/mock.txt")
    inicializar_db(path_a_db)
if __name__ == '__main__':
    main()