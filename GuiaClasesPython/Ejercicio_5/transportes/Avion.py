from base.Transporte import Transporte

class Avion(Transporte):
    def __init__(self, marca, modelo,capacidad):
        super().__init__(marca, modelo,capacidad)

    def moverse(self):
        super().moverse()
        print(f"Volando por el aire. Transportando a {self.capacidad} personas")

    def arrancar(self):
        super().arrancar()
        print("DESPEGANDO........")
    
    def frenar(self):
        super().frenar()
        print("........ATERRIZANDO")
    