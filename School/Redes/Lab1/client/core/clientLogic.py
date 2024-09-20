import json
import string
import random


# --- ~~ ~~ __Private methods ~~ ~~ --- 

# Function to generate a random string
def _CrearStringAleatorio(length):
    letters = string.ascii_letters  # Contains both uppercase and lowercase letters
    return ''.join(random.choice(letters) for _ in range(length))


# Function to create a "persona" dictionary
def _crearPersonaAleatoria():
    persona = {
        'nombre': _CrearStringAleatorio(random.randint(3, 15)),
        'edad': str(random.randint(18, 25)),
        'carrera': _CrearStringAleatorio(random.randint(10, 26)),
        'semestre': str(random.randint(1, 14))
    }
    return persona

# Function to create a list of personas
def _crearListaZero(filename,elements):
    lista = []

    for _ in range(elements):
        lista.append(_crearPersonaAleatoria())  # Call the function with parentheses

    # Writing the list to a JSON file
    with open(filename, 'w') as json_file:
        json.dump(lista, json_file, indent=4)  # indent=4 makes the JSON more readable

    return filename

# funcion para encontrar entradas aleatorias
def _definirEntradasAleatorias(percentageToModify,amountToModify):

    cantidadAModificar= int((percentageToModify * amountToModify) / 100)
    if cantidadAModificar > amountToModify:
        print("error, elements to modify are way more than the ones available!")
        return

    randomSelection = []

    for j in range(cantidadAModificar):

        num=random.randint(1,amountToModify)

        if randomSelection.count(j)>0:
            j-=1
        else:
            randomSelection.append(num)

    return randomSelection

def _modificarListaZero(filenameOriginal,filenameModified,percentageToModify,numElements):

    errorCharacters = ['!','@','#','$','%','&']

    # seleccionar numeros aleatorios para modificar
    listaNumerosSeleccionados = _definirEntradasAleatorias(percentageToModify,numElements)

    with open(filenameOriginal, 'r') as json_file:
        data = json.load(json_file)

    for  i in range(numElements):
        
        if i in listaNumerosSeleccionados:
            # modify element
            errorCharacterToAdd = errorCharacters[random.randint(0,5)]
            valueToModify = random.randint(1,4)
            if valueToModify ==1 :
                data[i]['nombre']+=errorCharacterToAdd
            elif valueToModify == 2:
                data[i]['edad']+=errorCharacterToAdd
            elif valueToModify ==3:
                data[i]['carrera']+=errorCharacterToAdd
            else :
                data[i]['semestre']+=errorCharacterToAdd

            

    with open(filenameModified, 'w') as json_file:
        json.dump(data,json_file,indent=4)









# --- ~~ ~~ PUBLIC EVENTS ~~ ~~ --- 

def eventCreation():
    print(" -   -   - ~event Creation~")

    numElements =100
    filenameOriginal ='PersonasOriginal.json'
    filenameModified ='PersonasModifiedZero.json'
    percentageToModify = 15


    # crear la lista de 100 personas
    pathToJsonFile = _crearListaZero(filenameOriginal,numElements)
    print(" 1. lista creada")
    

    # modificar el 15% de la lista con caracteres no permitidos
    pathToJsonFile = _modificarListaZero(filenameOriginal,filenameModified,percentageToModify,numElements)
    print(" 2. lista modificada con caracteres no validos")

    return '0'


def eventConnectionOpen():
    # print(" -   -   - ~event Connection~")
    # print(connectionMessage)

    # numElements =100
    # filenameOriginal ='PersonasOriginal.json'
    # filenameModified ='PersonasModifiedZero.json'
    # percentageToModify = 15


    # # crear la lista de 100 personas
    # pathToJsonFile = _crearListaZero(filenameOriginal,numElements)
    # print(" 1. lista creada")
    

    # # modificar el 15% de la lista con caracteres no permitidos
    # pathToJsonFile = _modificarListaZero(filenameOriginal,filenameModified,percentageToModify,numElements)
    # print(" 2. lista modificada con caracteres no validos")

    return '0'

def eventStep(message='0'):
    filenameToSend = 'PersonasModifiedZero.json'

    miLista = open(filenameToSend,'r')
    # response =''
    if message=='':
        print("     - no response from server")
        return  '1'
    elif message == '0':
        print("     - json file to be sent...")
        #send the data to the server for the first time
        
        return filenameToSend

    else:
        #compare the data and correct invalid characters
        for i in message:
            if not message[i]==miLista[i]:
                #discrepancia detectada
                print(f"    - discrepancia detectada en la persona {i+1}")
                #correct the data

    return '0'

def eventConnectionClose():
    return '0'


if __name__ == "__main__":
    eventConnectionOpen("testing")