from base.Figura import Figura
from math import pi
class Circulo(Figura):
    def __init__(self,radio:float):
        super().__init__()
        self.radio = radio
    
    def area(self):
        return (pi * self.radio) ** 2