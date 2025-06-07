"""
Desarrolle un programa que lea dos números y nos diga cuál de ellos es mayor o bien
si son iguales.
"""
A=int(input("Declare value A: "))
B=int(input("Declare value B: "))
if A>B:
	print("A > B")
elif A==B:
	print("A = B")
else:
	print("A < B")