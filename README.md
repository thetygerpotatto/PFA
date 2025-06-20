# 🧠 Sistema de Gestión de Usuarios con AVL Tree

Este proyecto implementa un **sistema de administración de usuarios** utilizando un **árbol AVL** como estructura principal. Ha sido desarrollado como parte del taller final de la asignatura **Análisis y diseños de Algoritmos I**.

---

## 🚀 Objetivo del proyecto

* Administrar eficientemente una colección de usuarios.
* Permitir operaciones de **inserción**, **eliminación** y **búsqueda** bajo las restricciones del árbol AVL.
* Garantizar un **tiempo logarítmico (O(log n))** en el peor caso para todas las operaciones.
* Ofrecer una **interfaz por terminal intuitiva** para facilitar su uso.

---

## 🛠 Tecnologías usadas

* **Python 3.11+**
* **Tabulate** (para diseño de tablas)
* Programación orientada a objetos (POO)

---

## 🧱 Estructura del proyecto

```
PFA/
├── Main.py                                 # Archivo principal
├── NodoUsuarioClase.py                     # Clase Usuario (ID, nombre, correo)
├── SistemaGestionUsuariosClase.py          # Implementación del árbol AVL
└── README.md                               # Este documento
```

---

## ⚙️ Funcionalidades principales

### 1. Agregar Usuario

* Ingresar ID y nombre.
* Inserta el nodo en el árbol AVL y rebalancea si es necesario.

### 2. Eliminar Usuario

* Elimina el nodo si existe (casos: hoja, 1 hijo, 2 hijos).
* Se aplican rotaciones para mantener el balance.

### 3. Buscar Usuario (Ceiling)

* Implementado de forma recursiva con comparaciones eficientes.
* Buscar el usuario con ID **Mayor (>), Menor (<) o igual (=) al ID dado**.

### 4. Listar Usuarios

* Recorrido inorden del árbol para obtener los usuarios en orden creciente por ID.

---

## 🎨 Interfaz Por Terminal

La terminal permite:

* Elegir entre las distintas opciones del proyecto.
* Visualizar los resultados directamente.
* Manejo Intuitivo
---

## 📚 Conceptos aplicados

* Árbol AVL (balanceado con altura).
* Rotaciones simples y dobles.
* Recorrido inorden.
* Inserción y eliminación recursiva con actualización de alturas.
* Separación de responsabilidades en módulos (POO).

---

## 👥 Autores

* Dilan Lemos - 202359416
* Juan José Restrepo - 202359517
* Jaime Noreña - 202359523
* Diego Fernando Lenis - 202359540
* Estudiantes de Ingeniería de Sistemas - 2025-1

---

## 📦 Ejecución

```bash
python main.py
```

Requisitos:

* Tener todos los archivos `.py` en el mismo directorio.
* Python instalado (recomendado 3.11+).

---

## 📌 Notas finales

* La eficiencia de todas las operaciones está garantizada por el AVL.
* Este proyecto se puede expandir para incluir otros datos como correo, teléfono, etc.
* Se prestó atención especial a la claridad del código para fines educativos.

---

## 📤 Licencia

Este proyecto es de uso educativo. Puedes modificarlo y adaptarlo para tus propios fines académicos.
