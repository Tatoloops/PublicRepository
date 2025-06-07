
# Ejercicio 1
def contarDigitos(num):
    if num>9:
        return contarDigitos(num//10)+1
    return 1

# Ejercicio 2

def exponente(a,b):
    if b>0:
        total = exponente(a,b-1)
        return total*a
    else:
        return 1
        
#ejercicio 3
def completarLinea(length):
    if length>0:
        lineToPrint=completarLinea(length-1)
        return "*"+lineToPrint
    else:
        return ""

def completarRectangulo(base,h):
    if h>0:
        completarRectangulo(base,h-1)
        line=completarLinea(base)
        print(line)


#main function
def main():
    print("Elegir ejercicio: ")
    print("1- contar Digitos")
    print("2- calculo de exponente")
    print("3- Imprimir rectangulo")
    
    ejercicio=int(input())

    #ejercicio 1
    if ejercicio==1:
        num=int(input("ingresar numero 1: "))

        #print(f"la suma de ambos numeros es:{suma(num1,num2,0)}")
        print(f"el numero {num} posee {contarDigitos(num)} digitos.")

    #ejercicio 2
    elif ejercicio==2:
        base=int(input("ingresar base: "))
        expo=int(input("ingresar exponente: "))
        print(f"el numero {base} ^ {expo} = {exponente(base,expo)}")

    #ejercicio 3
    elif ejercicio==3:
        base=int(input("ingresar ancho del rectangulo: "))
        altura=int(input("ingresar alto del rectangulo: "))
        completarRectangulo(base,altura)
        

#start
main()