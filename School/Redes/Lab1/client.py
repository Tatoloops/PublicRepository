import socket
import time
from client  import ClientLogic as cl


DEFAULT_HOST = 'localhost'        # Symbolic name meaning all available interfaces
DEFAULT_PORT = 44555              # Arbitrary non-privileged port\

def start_client(host=DEFAULT_HOST, port=DEFAULT_PORT):
    # crear socket
    clientSocket= socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    # conectar con el servidor
    clientSocket.connect((host,port))


    try:

    # - --- step zero ---

    # data received from server
        time.sleep(2)
        data=clientSocket.recv(1024)
        response = ""
        
        if data:
            response = cl.clientStepZero(data.decode())
        else:
            response = cl.clientStepZero('')

        print(" -   -   -por enviar respuesta")
        time.sleep(2)
        if response != '':
            clientSocket.sendall(response.encode())
        else:
            clientSocket.sendall(''.encode())

    # - --- step ---
        print(" -   -   -entering while cycle")
        while(True):
            print(" -   -   -receiving data in loop...")
            time.sleep(2)
            data = clientSocket.recv(1024)
            print(" -   -   -data received successfully...")
            if data:
                response = cl.clientStep(data.decode())
            else:
                response = cl.clientStep('')

            # send data depending on the type
            
            time.sleep(2)
            if response == '':
                print(" -   -   -sending data 123...")
                clientSocket.sendall(''.encode())
            if response == 'json':
                print(" -   -   -json to be send")
                with open('data.json', 'rb') as f:  # Open the file in binary mode
                    clientSocket.sendfile(f)  # Use sendfile to send the file over the socket
                    print("JSON file sent")


            #clientSocket.sendall(response.encode())


    finally:
        # clientSocket.sendall(cl.clientStepFinal().decode())
        clientSocket.close()
        
        


if __name__ == "__main__":
    start_client()
