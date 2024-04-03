#nodos
class Node:
    def __init__(self,info):
        self.info=info
        self.next=None

#Lista   
class ListaLigada:
    def __init__(self):
        self.head=None
        
    def inicio(self,info):
        nuevo_nodo=Node(info)
        if self.head:
            nuevo_nodo.next=self.head
            self.head=nuevo_nodo
        else:
            self.head=nuevo_nodo
            
    def fin(self,info):
        nuevo_nodo=Node(info)
        puntero=self.head
        if self.head:
            while(puntero.next):
                puntero=puntero.next
        puntero.next=nuevo_nodo

#Clase estatica para imprimir listas
class ListaLigadaImprimir:
    def medioSuperior(lista):
        if (lista.head):
            punt1=lista.head
            punt2=lista.head
            while punt1.next:
                punt1=punt1.next
                if punt1.next:
                    punt1=punt1.next
                punt2=punt2.next
            print(f"punto medio superior: {punt2.info}")
        else:
            print("lista vacia")

    def medioInferior(lista):
        if (lista.head):
            punt1=lista.head
            punt2=lista.head
            while punt1.next:
                punt1=punt1.next
                if punt1.next:
                    punt1=punt1.next
                    punt2=punt2.next
            print(f"punto medio superior: {punt2.info}")
        else:
            print("lista vacia")
        
    def mostrar(lista):
        puntero=lista.head
        while(puntero):
            print(puntero.info,end="")
            if puntero.next:
                print("-> ",end="")
            puntero=puntero.next
        print()

    def primero(lista):
        if lista.head:
            print(f"primer punto: {lista.head.info}")
        else:
            print("lista vacia")

    def ultimo(lista):
        puntero=lista.head
        if (lista.head):
            while puntero.next:
                puntero=puntero.next
            print(f"ultimo punto: {puntero.info}")
        else:
            print("lista vacia")
    def posicion(lista,n):
        if (lista.head):
            puntero=lista.head
            for i in range(1,n+1):
                if i==n:
                    print(f"valor en la posicion {n}: {puntero.info}")
                    break
                elif not puntero.next:
                    print(f"no hay valor en la posicion {n}")
                    break
                puntero=puntero.next
        else:
            print("lista vacia")


def main():
    lista=ListaLigada()
    lista.inicio(15)
    lista.inicio(2)
    lista.inicio(39)
    lista.inicio(41)
    lista.inicio(72)
    lista.inicio(71)
    lista.fin(520)
    lista.inicio(12)
    lista.inicio(34)
    lista.inicio(55)
    lista.inicio(90)
    lista.inicio(85)
    lista.fin(550)

    ListaLigadaImprimir.mostrar(lista)
    ListaLigadaImprimir.medioSuperior(lista)
    ListaLigadaImprimir.medioInferior(lista)
    ListaLigadaImprimir.primero(lista)
    ListaLigadaImprimir.ultimo(lista)
    ListaLigadaImprimir.posicion(lista,2)
    ListaLigadaImprimir.posicion(lista,5)
    ListaLigadaImprimir.posicion(lista,3)
    ListaLigadaImprimir.posicion(lista,13)
    
    
main()