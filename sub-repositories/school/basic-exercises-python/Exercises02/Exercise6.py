"""
Hacer un programa que muestre la tabla de multiplicar del 1 al 12 de cualquier
número ingresado por pantalla. Puede utilizar el ciclo while o for.

"""
table= input("multiplication table (1-n): ")
for i in range(1, 13):
    print(f"{table} x {i} = {int(table)*i}")