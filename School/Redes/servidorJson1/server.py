import socket
from server import serverLogic as sl

DEFAULT_HOST = 'localhost'         # Symbolic name meaning all available interfaces
DEFAULT_PORT = 44555               # Arbitrary non-privileged port\

def start_server(host=DEFAULT_HOST, port=DEFAULT_PORT):
    
    # mySocket[i]=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    mySocket = (socket.socket(socket.AF_INET,socket.SOCK_STREAM))
    mySocket.bind((host,port))
    mySocket.listen()
    


    # step zero
    try:
        
        print(f"conectando con cliente ")
        connection,client_adresss = mySocket.accept()

        print(f'Conexión establecida con {client_adresss}')
    
        response = sl.serverStepZero(1)
        print(" -   -   -sending data zero")
        if response :
            connection.sendall(response.encode())
        else :
            connection.sendall(''.encode())

        # client step zero
        print(" -   -   -receiving data zero")
        # data = connection.recv(1024)

            
    # step
        message =''

        print("entering loop")
        while(True):
        
            print("looping client ")

            #send to client
            response = sl.serverStep(message)
            connection.sendall(response.encode())

            #receive from client
            data = connection.recv(1024)
            if data:
                message=data.decode()
            else:
                message=''
                


            
    # step final
    finally:
        # response = sl.serverStepFinal()
        # for i in range(clientAmount):
        #     connection[i].sendall(response.encode())
            connection.close()
        

if __name__ == "__main__":
    start_server('localhost',44555)
