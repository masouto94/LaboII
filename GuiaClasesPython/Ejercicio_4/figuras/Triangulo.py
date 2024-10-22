from base.Figura import Figura

class Triangulo(Figura):
    def __init__(self,base:float,altura:float):
        super().__init__()
        self.base = base
        self.altura = altura
    
    def area(self):
        return (self.base * self.altura) / 2