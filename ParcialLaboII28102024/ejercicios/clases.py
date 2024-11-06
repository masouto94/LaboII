# Dise˜na una clase llamada Cilindro que tenga los siguientes atributos y m´etodos:
# • Atributos: radio y altura.
# • M´etodos:
# – area superficie(): Calcula y devuelve el ´area de la superficie del
# cilindro.
# – volumen(): Calcula y devuelve el volumen del cilindro.
# – cambiar dimensiones(nuevo radio, nueva altura): Cambia el ra-
# dio y altura del cilindro.
# 2
# Nota: El ´area de la superficie de un cilindro es 2πr(r + h) y el volumen es πr2h.
from math import pi
from abc import ABC,abstractmethod
class Cuerpo(ABC):
    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def volumen(self):
        pass
    
    @abstractmethod
    def cambiar_dimensiones(self):
        pass

class Cilindro(Cuerpo):
    def __init__(self, radio:float, altura:float):
        self.radio = radio
        self.altura = altura

    def area(self):
        return round(2 * pi * self.radio * (self.radio + self.altura),2)
    
    def volumen(self):
        return round(pi * pow(self.radio,2) * self.altura,2)

    def cambiar_dimensiones(self, nuevo_radio:float, nueva_altura:float):
        self.radio = nuevo_radio
        self.altura = nueva_altura
