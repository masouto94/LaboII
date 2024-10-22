from transportes.Avion import Avion
from transportes.Autobus import Autobus

def main():
    transportes = [
        Avion("Boeing","747",12000),
        Avion("Boeing","737",15000),
        Autobus("Chevallier", "CDN", 500),
        Autobus("Flechabus", "frontier", 450)
        ]
    for transporte in transportes:
        transporte.describir()
        transporte.arrancar()
        transporte.moverse()
        print(f"{transporte.modelo} llego a destino")
        transporte.frenar()
        print()

if __name__ == '__main__':
    main()