from base.Cuenta import CuentaBancaria

class CajaDeAhorro(CuentaBancaria):
    def __init__(self, interes:float):
        """Interes debe ser el interes dividido 100"""
        super().__init__()
        self.interes = interes

    def plazo_fijo(self, plazo:int):
        saldo_compuesto = self.saldo * ( (1+self.interes) ** plazo )
        return round(saldo_compuesto,2)