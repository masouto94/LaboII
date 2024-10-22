from base.Formatos import *

def main():
    ebooks = [
        LibroElectronico("Mi perro dinamita", "PR y los redondos"),
        LibroElectronico("La guerra y la paz", "Lev Tolstoi")
    ]

    fisicos = [
        LibroFisico("Cien años de soledad", "Gabriel Garcia Marquez"),
        LibroFisico("Nuestra parte de la noche", "Mariana Enriquez")
    ]

    libros = []
    libros.extend(ebooks)
    libros.extend(fisicos)

    for libro in libros:
        libro.mostrar_titulo()
        libro.mostrar_autor()
        print()

if __name__ == '__main__':
    main()