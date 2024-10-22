from abc import abstractmethod, ABC

class Figura(ABC):
    def __init__(self):
        super().__init__()

    @abstractmethod
    def area(self):
        pass