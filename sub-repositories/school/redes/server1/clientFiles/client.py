import socket
import createList as cl 

# def stringAleatorio(length):
#     letters = string.ascii_letters  # Contains both uppercase and lowercase letters
#     return ''.join(random.choice(letters) for _ in range(length))


# def crearPersona():
#     persona= {
#         'nombre':stringAleatorio(random.randint(3, 15)),
#         'edad': random.randint(18,25),
#         'carrera': stringAleatorio(random.randint(10, 26)),
#         'semestre': random.randint(1,14)
#     }
#     return persona

# def crearListsCompleta():
#     lista=[]

#     for _ in range(100):
#         lista.append(crearPersona)

#     return lista



#creacion de los usuarios
lista= cl.crearListaCompleta()



#servidor
HOST = ''    # The remote host
PORT = 50007              # The same port as used by the server
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'Hello, world')

    #enviar lista
    with open('data.json', 'rb') as f:  # Open the file in binary mode
        s.sendfile(f)  # Use sendfile to send the file over the socket
    print("JSON file sent")




    data = s.recv(1024)
print('Received', repr(data))