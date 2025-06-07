
# Escriba una función que multiplique 2 números mediante una suma. Función en caso no recursivo y recursivo. 
def suma(a,b):
    if b>0:
        total =suma(a,b-1)
        return total+a
    return 0

# Escriba una función que sume todos los elementos de un vector de n números enteros. Función en caso no recursivo y recursivo.

def sumaVector(array):
    if len(array)>=1:
        total=sumaVector(array[1:])
        return total+array[0]
    else: 
        return 0


# Escriba una función que busque un número x entre todos los elementos de un vector de n números enteros positivos. 
# Función en caso no recursivo y recursivo.


# nota personal: la funcion devuelve la posicion del primer digito encontrado que encaja con el critero de busqueda
def buscarEnArray(array,x):
    if len(array)>=1:
        # print(array)
        if array[0]==x:
            return 0
        else:
            posicion=buscarEnArray(array[1:],x)
            if (type(posicion))==int:
                return posicion+1
            else:
                return "valor no encontrado"
    else: 
        return "valor no encontrado"


#main function
    
def main():

    ejercicio=int(input("elegir ejercicio (1,2,3): "))

    #ejercicio 1
    if ejercicio==1:
        num1=int(input("ingresar numero 1: "))
        num2=int(input("ingresar numero 2: "))

        #print(f"la suma de ambos numeros es:{suma(num1,num2,0)}")
        print(f"la suma de ambos numeros es:{suma(num1,num2)}")

    #ejercicio 2
    elif ejercicio==2:
        size=int(input("ingresar array size: "))
        array=[""]*size
        for i in range(0,size):
            array[i]=int(input(f"ingresar valor array de la posicion {i}: "))
        print(f"la suma de los valores del array es: {sumaVector(array)}")

    #ejercicio 3
    elif ejercicio==3:
        x=int(input("valor a encontrar: "))
        size=int(input("ingresar array size: "))
        array=[""]*size
        for i in range(0,size):
            array[i]=int(input(f"ingresar valor array de la posicion {i}: "))
        valor = buscarEnArray(array,x)
        if type(valor)==int:
            print(f"el valor {x} se encuentra en la posicion {valor} del array")
        else:
            print("valor no encontrado en array")

#start
main()