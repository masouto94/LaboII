from typing import Callable
from abc import ABC,abstractmethod

#Creo un error especial que hereda de Exception general
#Hace lo mismo que cualquier error pero da mas informacion para trackear
class MarcaInvalida(Exception):
    pass
class ModeloInvalido(Exception):
    pass
class OperacionInvalida(Exception):
    pass

class Vehiculo(ABC):
    def __init__(self, marca:str, modelo:str) -> None:
        self.marca = marca
        self.modelo = modelo
        #Los vehiculos arrancan sin estar en marcha
        self._en_marcha = False

    #@property es un decorador especial que se usa para getters, setters y deleters
    #https://www.freecodecamp.org/espanol/news/python-decorador-property/
    @property
    def marca(self) -> str:
        return self._marca
    
    @marca.setter
    def marca(self, nueva_marca:str) -> None:
        if not isinstance(nueva_marca, str):
            raise MarcaInvalida("La marca debe ser un string")
        #.title() pone en mayuscula cada primer letra 
        self._marca = nueva_marca.title()
    
    @property
    def modelo(self) -> str:
        return self._modelo
    
    @modelo.setter
    def modelo(self, nuevo_modelo:str) -> None:
        if not isinstance(nuevo_modelo, str):
            raise ModeloInvalido("El modelo debe ser un string")
        self._modelo = nuevo_modelo.title()
    
    @property
    def en_marcha(self) -> str:
        return self._en_marcha
    
    @en_marcha.setter
    def en_marcha(self,value) -> None:
        raise OperacionInvalida("No se puede setear el attributo directamente. Debe usar los metodos de `arrancar` o `frenar`")

    @abstractmethod
    def arrancar(self) -> None:
        self._en_marcha = True

    @abstractmethod
    def frenar(self) -> None:
        self._en_marcha = False
    
    def describir(self) -> None:
        print(f"{self.__class__.__name__}: {self.marca} => {self.modelo}")