from figuras.Circulo import Circulo
from figuras.Cuadrado import Cuadrado
from figuras.Triangulo import Triangulo

def main():
    figuras = [
        Circulo(12.5),
        Circulo(5),
        Cuadrado(10),
        Cuadrado(2.5),
        Triangulo(10,20),
        Triangulo(110,220),
        Triangulo(90,21.10)
    ]

    for figura in figuras:
        print(figura.__class__.__name__, round(figura.area(),2))

if __name__ == '__main__':
    main()