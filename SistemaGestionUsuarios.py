from NodoUsuario import NodoUsuario

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
            return self.altura(nodo.izquierdo) - self.altura(nodo.derecho)
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
        balance = self.factor_de_balanceo(nodo)

        if balance > 1:
            if self.factor_de_balanceo(nodo.izquierdo) < 0:
                nodo.izquierdo = self.rotar_izquierda(nodo.izquierdo)
            return self.rotar_derecha(nodo)

        if balance < -1:
            if self.factor_de_balanceo(nodo.derecho) > 0:
                nodo.derecho = self.rotar_derecha(nodo.derecho)
            return self.rotar_izquierda(nodo)

        return nodo

    # funcion para agregar usuario
    def insertar_usuario(self):
        while True:
            try:
                id = int(input("ingrese el id del nuevo usuario:"))
                break
            except ValueError:
                print("Entrada no válida. Por favor, ingrese un número entero.")
                continue

        datos = input("Ingrese el nombre del usuario: ")
        self.raiz = self.insertar_aux(self.raiz, id, {"nombre": datos})
        print(self.recorrido_inorden())

    def insertar_aux(self, nodo, id_usuario, datos):
        if not nodo:
            nuevo_nodo = NodoUsuario(id_usuario, datos)
            return nuevo_nodo

        if id_usuario < nodo.id_usuario:
            nodo.izquierdo = self.insertar_aux(nodo.izquierdo, id_usuario, datos)
        elif id_usuario > nodo.id_usuario:
            nodo.derecho = self.insertar_aux(nodo.derecho, id_usuario, datos)
        else:
            print(f"El usuario con ID {id_usuario} ya existe.")
            return nodo

        return self.balancear(nodo)

    def eliminar_usuario(self, id_usuario):
        self.raiz = self.eliminar(self.raiz, id_usuario)

    def eliminar(self, nodo, id_usuario):
        if not nodo:
            print(f"El usuario con ID {id_usuario} no existe.")
            return nodo

        if id_usuario < nodo.id_usuario:
            nodo.izquierdo = self.eliminar(nodo.izquierdo, id_usuario)
        elif id_usuario > nodo.id_usuario:
            nodo.derecho = self.eliminar(nodo.derecho, id_usuario)
        elif id_usuario == nodo.id_usuario:
            if not nodo.izquierdo:
                return nodo.derecho
            elif not nodo.derecho:
                return nodo.izquierdo
            
            temp = self.minimo_nodo(nodo.derecho)
            nodo.id_usuario = temp.id_usuario
            nodo.datos = temp.datos
            nodo.derecho = self.eliminar(nodo.derecho, temp.id_usuario)


        return self.balancear(nodo)


    def minimo_nodo(self, nodo):
        actual = nodo
        while actual.izquierdo:
            actual = actual.izquierdo

        return actual

    def _buscar_mayor_igual(self, id_buscar):
        resultado = self.buscar_mayor_igual(self.raiz, id_buscar, None)
        return resultado

    def buscar_mayor_igual(self, nodo, id_buscar, candidato):
        if not nodo:
            return candidato

        if nodo.id_usuario == id_buscar:
            return nodo
        elif nodo.id_usuario > id_buscar:
            return self.buscar_mayor_igual(nodo.izquierdo, id_buscar, nodo)
        else:
            return self.buscar_mayor_igual(nodo.derecho, id_buscar, candidato)

    def recorrido_inorden(self):
        resultado = []
        self.inorden(self.raiz, resultado)
        return resultado

    def inorden(self, nodo, resultado):
        if nodo:
            self.inorden(nodo.izquierdo, resultado)
            resultado.append(nodo.id_usuario)
            self.inorden(nodo.derecho, resultado)