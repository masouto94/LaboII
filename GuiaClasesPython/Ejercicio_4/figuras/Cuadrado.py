from base.Figura import Figura

class Cuadrado(Figura):
    def __init__(self,lado:float):
        super().__init__()
        self.lado = lado
    
    def area(self):
        return self.lado ** 2