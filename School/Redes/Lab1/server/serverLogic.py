



# --- Interaction con el Socket ---
def serverStepZero(i):
    print(" -   -   -step zero")
    response = f"Bienvenido al servidor, eres el cliente numero {i+1}"
    return response


def serverStep(message=''):
    print(" -   -   -step")
    response =''
    if message=='':
        print("no response from client")
        return response
    


    return response

# def serverStepFinal():
#     response = ''
#     return response