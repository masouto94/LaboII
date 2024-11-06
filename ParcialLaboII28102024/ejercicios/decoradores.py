# Escribe un decorador llamado multiplicar si mayor que reciba un n´umero
# como par´ametro. Este decorador debe aplicarse a dos funciones:
# • Una funci´on suma(a, b) que sume dos n´umeros.
# • Una funci´on resta(a, b) que reste dos n´umeros.
# El decorador debe verificar si el resultado de la funci´on es mayor a 10 y, si es as´ı,
# multiplicarlo por el valor proporcionado al decorador. Implementa el decorador
# y aplica ambas funciones.
# Ejemplo de uso:
# @multiplicar_si_mayor(4)
# def suma(a, b):
# return a + b
# @multiplicar_si_mayor(3)
# def resta(a, b):
# return a - b
# Si se llama a suma(5, 8), el resultado deber´ıa ser 52, ya que el decorador
# multiplica el resultado original 13 por 4

def multiplicar_si_mayor(factor):
    def decorador(func):
        def wrapper(*args, **kwargs):
            resultado = func(*args, **kwargs)
            if resultado > 10:
                return resultado * factor
            return resultado
        return wrapper
    return decorador


@multiplicar_si_mayor(4)
def suma(a:int,b:int) -> int:
    return a+b

@multiplicar_si_mayor(4)
def resta(a:int,b:int) -> int:
    return a-b
