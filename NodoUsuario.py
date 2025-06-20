class NodoUsuario:
    def __init__(self, id_usuario, datos=None):
        self.id_usuario = id_usuario
        self.datos = datos
        self.izquierdo = None
        self.derecho = None
        self.altura = 1