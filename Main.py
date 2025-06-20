## Árbol AVL ( Adelson-Velsky y Landis) para la gestión de usuarios

from tabulate import tabulate
from SistemaGestionUsuarios import SistemaGestionUsuarios

def menu(self):
    
    while True:
        Tabla_Menu = [
        ["1", "Agregar Usuario"],
        ["2", "Eliminar Usuario"],
        ["3", "Mostrar Usuario con ID mayor"],
        ["4", "Mostrar Usuario con ID menor"],
        ["5", "Busqueda de Usuario por ID"],
        ["6", "Mostrar Usuarios Activos"],
        ["7", "Registar mediante archivo de texto"],
        ["0", "Salir"]]
        
        print(tabulate(Tabla_Menu, headers=["Opción", "Descripción"], tablefmt="rounded_outline"))
        try:
            opc = int(input("Seleccione una opción: "))
            match opc:
                case 1:
                    self.insertar_usuario()
                case 2:
                    self.eliminar_usuario()
                case 3:
                    pass
                    self.maximo_nodo()
                case 4:
                    pass
                    self.minimo_nodo()
                case 5:
                    pass
                    self.buscar_usuario()
                case 6:
                    pass
                    self.listar_usuarios()
                case 7:
                    self.leer_txt()
                case 0:
                    print("chauu...")
                    break
                case _:
                    print("Opción no válida. Intente de nuevo.")
        except ValueError:
            print("Entrada no válida. Por favor, ingrese un número entero.")

                

if __name__ == "__main__":
    sistema = SistemaGestionUsuarios()
    menu(sistema)