import random
import string
import json

personFile = 'personas.json'
numElements = 100


# Function to generate a random string
def stringAleatorio(length):
    letters = string.ascii_letters  # Contains both uppercase and lowercase letters
    return ''.join(random.choice(letters) for _ in range(length))

# Function to create a "persona" dictionary
def crearPersona():
    persona = {
        'nombre': stringAleatorio(random.randint(3, 15)),
        'edad': random.randint(18, 25),
        'carrera': stringAleatorio(random.randint(10, 26)),
        'semestre': random.randint(1, 14)
    }
    return persona

# Function to create a list of personas
def crearListaCompleta(numElements):
    lista = []

    for _ in range(numElements):
        lista.append(crearPersona())  # Call the function with parentheses

    return lista

# def create_json_file_if_not_exists(file_path, default_data=None):
#     if not os.path.exists(file_path):
#         # If the file does not exist, create it with default data
#         with open(file_path, 'w') as json_file:
#             json.dump(default_data or {}, json_file, indent=4)
#         print(f"Created a new JSON file: {file_path}")
#     else:
#         print(f"JSON file already exists: {file_path}")






# Creation of personas and writing them to a JSON file
lista = crearListaCompleta(numElements)


# encontrar index de los 15% a modificar

cantidadAModificar= (15 * numElements) / 100

random = []

for j in range(cantidadAModificar):

    num=random.randint(1,numElements)

    check=0
    for i in random:
        if num==i:
            check=1

    if check==1:
        j-=1
    else:
        random.append(num)

#modificar el 15% de los datos dados:



# simbolos malos !#$(?

for i in random:
    lista[random[i]].'nombre' +=\#
    lista[random[i]].'edad' +=!
    lista[random[i]].'carrera'+=?
    lista[random[i]].'semestre' +=$



# Creates 
# create_json_file_if_not_exists(personFile)

# Writing the list to a JSON file
with open(personFile, 'w') as json_file:
    json.dump(lista, json_file, indent=4)  # indent=4 makes the JSON more readable


# with open (personFile, 'r+') as json_file:

