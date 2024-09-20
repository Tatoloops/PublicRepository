import json
import string

# --- ~~ ~~ __Private methods ~~ ~~ --- 
def _AnalizarMensaje(DictionaireList):
    errorCharacters = ['!', '@', '#', '$', '%', '&']

    goodList = []
    badList = []

    for i in DictionaireList:
        is_bad = False  # Flag to track if the dictionary contains any error characters

        # Check each key and value in the dictionary
        for key, value in i.items():
            # # Check for error characters in keys
            # if any(j in key for j in errorCharacters):
            #     badList.append(i)
            #     is_bad = True
            #     break

            # Check for error characters in values (if values are strings)
            if isinstance(value, str) and any(j in value for j in errorCharacters):
                badList.append(i)
                is_bad = True
                break

        # If no errors were found, add to the goodList
        if not is_bad:
            goodList.append(i)

    return goodList, badList

        

# --- ~~ ~~ PUBLIC EVENTS ~~ ~~ --- 
def eventCreation():
    return '0'


def eventConnectionOpen(message = '0'):
    # print(" -   -   -step zero")
    # response = f"Bienvenido al servidor, eres el cliente numero {i+1}"
    return '0'


def eventStep(message='0'):
    
    if isinstance(message,str) and message.endswith('.json'): # sends json in case it is sending a json file.
        with open(message, 'rb') as f:  # Open the file in binary mode
            h=0


    response ='0'
    if message=='':
        print("no response from client")
        return response
    

    return response

def eventConnectionClose():

    return '0'