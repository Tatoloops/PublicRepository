"""
Realizar un algoritmo que lea un número por teclado. En caso de que ese número sea
0 o menor que 0, se saldrá del programa imprimiendo antes un mensaje de error. Si
es mayor que 0, se deberá calcular su cuadrado y la raíz cuadrada del mismo,
visualizando el número que ha tecleado el usuario y su resultado (“Del número X, su
potencia es X y su raíz X”).
"""
A=int(input("Declare a nummber: "))
if A<=0:
	print("error: invalid number!")
else:
	print(f"Del número {A}, su potencia es {A**2} y su raíz {A**(1/2)}")