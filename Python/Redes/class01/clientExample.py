import socket

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 65432))

    try:
        while True:
            # Ingresar datos por teclado
            message = input("Ingrese un mensaje para enviar al servidor: ")
            if not message:
                break  # Salir si el mensaje está vacío
            client_socket.sendall(message.encode())

            # Recibir respuesta del servidor
            data = client_socket.recv(1024)
            print('Respuesta del servidor:', data.decode())
    finally:
        client_socket.close()

if __name__ == '__main__':
    start_client()