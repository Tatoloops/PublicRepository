"""
Escriba una función que tome una lista de números y muestre por pantalla la suma
acumulada, es decir el primer elemento es el mismo, el segundo elemento es la
suma del primero con el segundo, el tercer elemento es la suma del resultado
anterior con el siguiente elemento y así sucesivamente. Por ejemplo, la suma
acumulada de [1,2,3,4] es 1, 3, 6,10.
"""
ListSize=int(input("Size of array: "))
MainArray=[0]*ListSize
PrimeArray=[0]*ListSize
Sum=0
for i in range (ListSize):
    MainArray[i]= input(f"type number :")
    Sum+=int(MainArray[i])
    PrimeArray[i]=Sum
for i in range(ListSize-1):
    print(PrimeArray[i], ", ", end="")
print(PrimeArray[ListSize-1])

