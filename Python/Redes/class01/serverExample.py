import socket

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 65432))
    server_socket.listen()

    print('Servidor escuchando en localhost:65432')

    invalid_chars = "!#$%&/()="

    while True:
        connection, client_address = server_socket.accept()
        try:
            print('Conexión desde', client_address)

            while True:
                data = connection.recv(1024)
                if data:
                    message = data.decode()
                    print('Recibido:', message)
                    
                    if any(char in message for char in invalid_chars):
                        response = "Carácter no válido encontrado en el mensaje."
                    else:
                        response = message  # Echo del mensaje

                    connection.sendall(response.encode())
                else:
                    break
        finally:
            connection.close()

if __name__ == '__main__':
    start_server()