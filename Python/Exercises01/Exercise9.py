"""
Crear un programa que solicite por pantalla la cantidad de hombres y el total de
personas de un salón de clase y calcule el porcentaje de mujeres y hombres que hay.
"""

Men=int(input("amount of men in the room: "))
Total=int(input("Total people in room: "))
Women=Total-Men
print(f"percentaje of men: %{100*(Men/Total)}")
print(f"percentaje of men: %{100*(Women/Total)}")