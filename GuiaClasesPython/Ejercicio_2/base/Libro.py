from abc import abstractmethod, ABC

class AutorInvalido(Exception):
    pass
class TituloInvalido(Exception):
    pass

class Libro(ABC):
    def __init__(self, titulo:str, autor:str):
        self.titulo = titulo
        self.autor = autor
    
    @property
    def titulo(self) -> str:
        return self._titulo
    
    @titulo.setter
    def titulo(self, nuevo_titulo:str) -> None:
        if not isinstance(nuevo_titulo, str):
            raise TituloInvalido("El titulo debe ser un string")
        self._titulo = nuevo_titulo.title()

    @property
    def autor(self) -> str:
        return self._autor
    
    @autor.setter
    def autor(self, nuevo_autor:str) -> None:
        if not isinstance(nuevo_autor, str):
            raise AutorInvalido("El titulo debe ser un string")
        self._autor = nuevo_autor.title()

    @abstractmethod
    def mostrar_titulo(self):
        pass

    @abstractmethod
    def mostrar_autor(self):
        pass