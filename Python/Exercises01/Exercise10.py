"""
Elaborar un algoritmo que solicite dos números enteros y un operador aritmético y
luego debe mostrar el resultado de la operación correspondiente
"""
Number1=int(input("number 1: "))
Number2=int(input("number 2: "))
Oper=(input("number 2: "))

if (Oper=="-"):
    print(f"substraction of numbers is: {Number1-Number2}")
elif (Oper=="+"):
    print(f"sum of numbers is: {Number1+Number2}")
elif (Oper=="*"):
    print(f"multiplication of numbers is: {Number1*Number2}")
elif (Oper=="/"):
    print(f"division of numbers is: {Number1/Number2}")