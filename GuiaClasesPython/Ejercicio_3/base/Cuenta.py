from abc import abstractmethod, ABC

class OperacionInvalida(Exception):
    pass
class SaldoInsuficiente(Exception):
    pass

class CuentaBancaria(ABC):
    def __init__(self):
        self.__saldo = 0
    
    @property
    def saldo(self) -> float:
        return round(self.__saldo,2)
    
    @saldo.setter
    def saldo(self, valor):
        raise OperacionInvalida("No se puede setear el saldo directamente")
    
    def depositar(self, monto:float) -> None:
        self.__saldo += monto

    def retirar(self, monto:float) -> None:
        if self.saldo < monto:
            raise SaldoInsuficiente(f"El saldo {self.saldo} no alcanza para retirar {monto}")
        self.__saldo -= monto