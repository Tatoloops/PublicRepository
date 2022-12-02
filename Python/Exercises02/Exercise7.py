"""
Hacer un programa que recorra los elementos de las siguientes lista:
nombres = ['Juan', 'Pedro', 'Ramiro', 'Andrea', 'Carlos', 'Antonio']
edad = [22,24,18,15,31,29]
Luego hacer que el programa despliegue el nombre y la edad de la siguiente forma.
Nombre: Juan - Edad: 22
Nombre: Pedro - Edad: 24

"""
Name=[0]*6
Age=[0]*6
count=0
for i in['Juan', 'Pedro', 'Ramiro', 'Andrea', 'Carlos', 'Antonio']:
    Name[count]=i
    count+=1
count=0
for i in [22,24,18,15,31,29]:
    Age[count]=i
    count+=1
for i in range(5):
    print(f"{Name[i]} - Edad: {Age[i]}")