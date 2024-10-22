from vehiculos.base.BaseVehicle import Vehiculo

class Bicicleta(Vehiculo):
    def __init__(self, marca:str, modelo:str):
        super().__init__(marca, modelo)

    def arrancar(self):
        print("Esquivando balas con mi bicicleta")
        super().arrancar()

    def frenar(self):
        print("Crick")
        super().frenar()