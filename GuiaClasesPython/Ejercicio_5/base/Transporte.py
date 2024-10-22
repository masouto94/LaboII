from abc import abstractmethod
#######
#Aca se importa la clase Vehiculo del ejercicio 1. Por cómo está armado el repo, hay que meter a mano el path
#en el sys path. Con esto, podemos acceder a Vehiculo y extender su funcionalidad aca
import sys
sys.path.append("GuiaClasesPython/Ejercicio_1")
from vehiculos.base.BaseVehicle import Vehiculo
#########

class VehiculoApagado(Exception):
    pass
class Transporte(Vehiculo):
    def __init__(self, marca:str, modelo:str, capacidad: int):
        super().__init__(marca,modelo)
        self.capacidad = capacidad

    @abstractmethod
    def moverse(self):
        if not self.en_marcha:
            raise VehiculoApagado("Primero hay que arrancar antes de moverse") 