from vehiculos.base.BaseVehicle import Vehiculo

class Auto(Vehiculo):
    def __init__(self, marca:str, modelo:str):
        super().__init__(marca, modelo)

    def arrancar(self):
        print("BUMBUMBUM")
        super().arrancar()

    def frenar(self):
        print("Rmmmmmmmmmmmm")
        super().frenar()