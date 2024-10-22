from vehiculos.base.BaseVehicle import Vehiculo

class Motocicleta(Vehiculo):
    def __init__(self, marca:str, modelo:str):
        super().__init__(marca, modelo)

    def arrancar(self):
        print("TUTUTUTUM")
        super().arrancar()

    def frenar(self):
        print("SHHHHHH")
        super().frenar()

class MotocicletaEspecial(Vehiculo):
    def __init__(self, marca:str, modelo:str):
        super().__init__(marca, modelo)

    def arrancar(self):
        print("##########")
        print("SHHHHRUUUM")
        print("##########")
        super().arrancar()

    def frenar(self):
        print("PFFFFFFFFFFFF")
        super().frenar()