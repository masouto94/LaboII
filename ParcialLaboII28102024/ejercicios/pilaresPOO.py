# 6. Pilares de la Programaci´on Orientada a Objetos
# En base al siguiente c´odigo:

# Explica:
# • ¿C´omo se implementa la abstracci´on en el c´odigo? ¿Qu´e ventaja ofrece
# este enfoque?
# • ¿Qu´e ventaja tiene el polimorfismo en este caso?
# • Explica c´omo se podr´ıa aplicar la herencia para agregar una clase Camion
# que extienda la funcionalidad de la clase base Vehiculo, a˜nadiendo un
# atributo propio como carga maxima.

from abc import ABC, abstractmethod

class Vehiculo(ABC):
    @abstractmethod
    def tipo(self):
        pass
class Auto(Vehiculo):
    def tipo(self):
        return "Automóvil"

class Bicicleta(Vehiculo):
    def tipo(self):
        return "Bicicleta"  
    
def respuestas():
    print("-"*10)
    print("""
1) En este código, la abstracción se implementa al crear una clase padre abstracta y definiéndole métodos abstractos.\
Tanto la clase como el método marcado como abstracto no pueden instanciarse directamente sino que deben hacerlo a través de sus hijas.\
Este enfoque permite definir de antemano cierta responsabilidad e inteligencia de todos los miembros de esa clase y nos asegura que toda instancia de Vehiculo pueda llamar al método 'tipo'
""")
    print("""
2) El polimorfismo acá está en que podemos llamar a 'tipo' de cualquier instancia de Vehiculo o hijas de ella o sus clases hijas de la misma manera
""")
    print("""
3) En caso de que se quisiera agregar Camion como hija de Vehiculo sería tan sencillo como hacer:
    class Camion(Vehiculo):
    def __init__(self, carga_maxima):
        super().__init__()
        self.carga_maxima = carga_maxima
    
    def tipo(self):
        return "Camion"
    
camion = Camion(1222)
print(camion.__dict__,camion.tipo(), isinstance(camion,Vehiculo))

>>>{'carga_maxima': 1222} Camion True
          
En este caso, puedo instanciar Camion con un atributo especial pero respetando la herencia de tipo y la pertenencia a Vehiculo
""")
    print("-"*10)
    