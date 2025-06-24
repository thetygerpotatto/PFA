from NodoUsuario import NodoUsuario
from tabulate import tabulate

class SistemaGestionUsuarios(NodoUsuario):
    def __init__(self):
        self.raiz = None

    def altura(self, nodo):
        if not nodo:
            return 0
        else:
            return nodo.altura

    def factor_de_balanceo(self, nodo):
        if nodo:
            f_balance = self.altura(nodo.izquierdo) - self.altura(nodo.derecho)
            return f_balance
        else:
            return 0
            

    def actualizar_altura(self, nodo):
        if nodo:
            altura_izq = self.altura(nodo.izquierdo)
            altura_der = self.altura(nodo.derecho)
            nodo.altura = 1 + max(altura_izq, altura_der)

    def rotar_derecha(self, y):
        izq = y.izquierdo
        der = izq.derecho

        izq.derecho = y
        y.izquierdo = der

        self.actualizar_altura(y)
        self.actualizar_altura(izq)

        return izq

    def rotar_izquierda(self, x):
        der = x.derecho
        izq = der.izquierdo

        der.izquierdo = x
        x.derecho = izq

        self.actualizar_altura(x)
        self.actualizar_altura(der)

        return der

    def balancear(self, nodo):
        self.actualizar_altura(nodo)
        f_balance = self.factor_de_balanceo(nodo)

        if f_balance > 1:
            if self.factor_de_balanceo(nodo.izquierdo) < 0:
                nodo.izquierdo = self.rotar_izquierda(nodo.izquierdo)
            return self.rotar_derecha(nodo)

        if f_balance < -1:
            if self.factor_de_balanceo(nodo.derecho) > 0:
                nodo.derecho = self.rotar_derecha(nodo.derecho)
            return self.rotar_izquierda(nodo)

        return nodo

    # funcion para agregar usuario
    def insertar_usuario(self):
        while True:
            try:
                id = int(input("Ingrese el ID del nuevo usuario: "))   
                if id <= 0:
                    print("El ID debe ser un número entero positivo.")
                    continue
                else:      
                    break  
            except ValueError:
                print("Se desubicó pa, ingrese un número entero egh.")
                continue
        datos = input("Ingrese el nombre del usuario: ")
        self.raiz = self.insertar_aux(self.raiz, id, datos)


    def insertar_aux(self, nodo, id_usuario, datos):
        if not nodo:
            nuevo_nodo = NodoUsuario(id_usuario, datos)

            print("Se ha agregado el usuario:")
            print(f"ID: {nuevo_nodo.id_usuario} | Nombre: {nuevo_nodo.datos}")
            
            return nuevo_nodo

        if id_usuario < nodo.id_usuario:
            nodo.izquierdo = self.insertar_aux(nodo.izquierdo, id_usuario, datos)
        elif id_usuario > nodo.id_usuario:
            nodo.derecho = self.insertar_aux(nodo.derecho, id_usuario, datos)
        else:
            print(f"El usuario con ID {id_usuario} ya existe.")
            return nodo

        return self.balancear(nodo)

    def eliminar_usuario(self):
        while True:
            try:
                id = int(input("Ingrese el ID del usuario a eliminar: "))   
                if id <= 0:
                    print("El ID debe ser un número entero positivo.")
                    continue
                else:      
                    break  
            except ValueError:
                print("Se desubicó pa, ingrese un número entero egh.")
                continue
        self.raiz = self.eliminar(self.raiz, id)


    def eliminar(self, nodo, id_buscar):
        if not nodo:
            print(f"El usuario con ID {id_buscar} no existe.")
            return nodo

        if id_buscar < nodo.id_usuario:
            nodo.izquierdo = self.eliminar(nodo.izquierdo, id_buscar)
        elif id_buscar > nodo.id_usuario:
            nodo.derecho = self.eliminar(nodo.derecho, id_buscar)
        elif id_buscar == nodo.id_usuario:
            if not nodo.izquierdo:
                print("Se ha eliminado el ID")
                return nodo.derecho
            elif not nodo.derecho:
                print("Se ha eliminado el ID")
                return nodo.izquierdo
            
            temp = self.ultimo_izquierdo(nodo.derecho)
            nodo.id_usuario = temp.id_usuario
            nodo.datos = temp.datos
            nodo.derecho = self.eliminar(nodo.derecho, temp.id_usuario)

        return self.balancear(nodo)

    def ultimo_derecho(self, nodo):
        actual = nodo
        while actual.derecho:
            actual = actual.derecho

        return actual
    
    def ultimo_izquierdo(self, nodo):
        actual = nodo
        while actual.izquierdo:
            actual = actual.izquierdo

        return actual

    def minimo_nodo(self):
        nodo = self.raiz
        minimo = self.ultimo_izquierdo(nodo)
        print(f"ID: {minimo.id_usuario} | Nombre: {minimo.datos}")

    def maximo_nodo(self):
        nodo = self.raiz
        maximo = self.ultimo_derecho(nodo)
        print(f"ID: {maximo.id_usuario} | Nombre: {maximo.datos}")

    def buscar_usuario(self):
        while True:
            try:
                id = int(input("Ingrese el ID del usuario que desea buscar: "))   
                if id <= 0:
                    print("El ID debe ser un número entero positivo.")
                    continue
                else:      
                    break  
            except ValueError:
                print("Se desubicó pa, ingrese un número entero egh.")
                continue
        resultado = self.buscar_usuario_aux(self.raiz, id)
        print(resultado)

    def buscar_usuario_aux(self, nodo, id_buscar):
        if not nodo:
            return "No se encontró al sujeto con ese ID."
         
        if nodo.id_usuario == id_buscar:
            return f"ID: {nodo.id_usuario} | Nombre: {nodo.datos}"
        elif nodo.id_usuario > id_buscar:
            return self.buscar_usuario_aux(nodo.izquierdo, id_buscar)
        elif nodo.id_usuario < id_buscar:
            return self.buscar_usuario_aux(nodo.derecho, id_buscar)
        else:
            return "com carajos llegó usted acá"

    def listar_usuarios(self):
        resultado = []
        self.listar_usuarios_aux(self.raiz, resultado)
        print(tabulate(resultado, headers=["ID Usuario", "Datos"], tablefmt="rounded_outline"))

    def listar_usuarios_aux(self, nodo, resultado):
        if nodo:
            self.listar_usuarios_aux(nodo.izquierdo, resultado)
            nuevos_datos = [nodo.id_usuario, nodo.datos]
            resultado.append(nuevos_datos)
            self.listar_usuarios_aux(nodo.derecho, resultado)

    def leer_txt(self):
        archivo = input("Ingrese la ubicación del archivo de texto que desea registrar: ")
        try:
            with open(archivo, "r", encoding="utf-8") as file:
                for linea in file:
                    linea = linea.strip()
                    if not linea:
                        continue  # Ignora líneas vacías

                    partes = linea.split(",")
                    if len(partes) != 2:
                        print(f"Formato incorrecto en línea: '{linea}'")
                        continue

                    id_usuario_str, nombre = partes
                    try:
                        id_usuario = int(id_usuario_str.strip())
                        nombre = nombre.strip()
                        self.raiz = self.insertar_aux(self.raiz, id_usuario, nombre)
                    except ValueError:
                        print(f"ID inválido en línea: '{linea}'")
        except FileNotFoundError:
            print(f"El archivo '{archivo}' no se encontró.")
        except Exception as e:
            print(f"Error al leer el archivo: {e}")

# C:\Users\dilan\OneDrive\Escritorio\xd.txt