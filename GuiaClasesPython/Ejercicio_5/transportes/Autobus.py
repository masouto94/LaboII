from base.Transporte import Transporte

class Autobus(Transporte):
    def __init__(self, marca, modelo,capacidad):
        super().__init__(marca, modelo,capacidad)

    def moverse(self):
        super().moverse()
        print(f"Andando por la ruta. Transportando a {self.capacidad} personas")

    def arrancar(self):
        super().arrancar()
        print("Acelerando...")
    
    def frenar(self):
        super().frenar()
        print("...parando")