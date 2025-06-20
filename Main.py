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
        ["0", "Salir"]]
        
        print(tabulate(Tabla_Menu, headers=["Opción", "Descripción"], tablefmt="rounded_outline"))
        try:
            opc = int(input("Seleccione una opción: "))
            match opc:
                case 1:
                    pass
                    self.insertar_usuario()
                case 2:
                    pass
                    #eliminar_usuario()
                case 3:
                    pass
                    #buscar_usuario_mayor()
                case 4:
                    pass
                    #mostrar_usuario_menor()
                case 5:
                    pass
                    #busqueda_usuario()
                case 6:
                    pass
                    #mostrar_usuarios_activos()
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
    """sistema.agregar_usuario(50, {"nombre": "Ana"})
    sistema.agregar_usuario(30, {"nombre": "Luis"})
    sistema.agregar_usuario(70, {"nombre": "Marta"})
    sistema.agregar_usuario(20, {"nombre": "Carlos"})
    sistema.agregar_usuario(40, {"nombre": "Laura"})
    sistema.agregar_usuario(60, {"nombre": "Juan"})
    sistema.agregar_usuario(80, {"nombre": "Sofía"})
    print("Usuarios ordenados:", sistema.recorrido_inorden())
    usuario = sistema._buscar_mayor_igual(45)
    if usuario:
        print(f"Usuario con ID >= 45: {usuario.id_usuario}, Datos: {usuario.datos}")

    sistema.eliminar_usuario(40)
    print("----Después de eliminar ID 40:", sistema.recorrido_inorden())

    usuario = sistema._buscar_mayor_igual(45)
    if usuario:
        print(f"Usuario con ID >= 45: {usuario.id_usuario}, Datos: {usuario.datos}")
    
    #funcion para agregar usuari   
    # def insertar():
    #     id = int(input("ingrese el id del nuevo usuario:"))
    #     nombre = input("Ingrese el nombre del usuario")
    #linea para condicional de validación
    #     sistema.agregar_usuario(id, {"nombre": nombre})

    # def eliminar():
    #     id = int(input("Inserte el Id del usuario a eliminar"))
    #     sistema.eliminar_usuario(id)"""