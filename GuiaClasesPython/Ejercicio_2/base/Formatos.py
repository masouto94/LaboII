from base.Libro import Libro

class LibroElectronico(Libro):
    def __init__(self, titulo:str, autor:str):
        super().__init__(titulo, autor)
    
    def mostrar_titulo(self):
        print("-"*10)
        print(f"{self.titulo}")
        print("-"*10)

    def mostrar_autor(self):
        print("+"*10)
        print(f"{self.autor}")
        print("+"*10)

class LibroFisico(Libro):
    def __init__(self, titulo:str, autor:str):
        super().__init__(titulo, autor)
    
    def mostrar_titulo(self):
        print("~"*10)
        print(f"{self.titulo}")
        print("~"*10)

    def mostrar_autor(self):
        print("^"*10)
        print(f"{self.autor}")
        print("v"*10)