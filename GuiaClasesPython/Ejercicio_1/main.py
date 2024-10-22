from vehiculos.Motocicleta import *
from vehiculos.Bicicleta import *
from vehiculos.Automovil import *

def main():
    motos = [
    Motocicleta("yamaha", "XTR"),
    MotocicletaEspecial("kawasaki", "ninja")
    ]

    autos = [
        Auto("renault", "12"),
        Auto("renault", "megane")
    ]

    bicis = [
        Bicicleta("vairo", "mountain bike"),
        Bicicleta("generica", "playera")
    ]

    vehiculos = []
    vehiculos.extend(motos)
    vehiculos.extend(autos)
    vehiculos.extend(bicis)

    for vehiculo in vehiculos:
        vehiculo.describir()
        vehiculo.arrancar()
        vehiculo.frenar()
        print()

if __name__ == "__main__":
    main()
