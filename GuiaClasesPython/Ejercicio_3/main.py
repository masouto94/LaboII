from base.CajaDeAhorro import CajaDeAhorro

def main():
    caja = CajaDeAhorro(0.1)
    caja.depositar(1000)
    print(caja.plazo_fijo(12))

if __name__ == '__main__':
    main()