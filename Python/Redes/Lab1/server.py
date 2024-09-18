import socket

HOST = 'localhost'                 # Symbolic name meaning all available interfaces
PORT = 65432              # Arbitrary non-privileged port\

def start_server(host=HOST, port=PORT):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(1)
    print(f"Server started at {host}:{port}")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Connection from {addr}")
        message = client_socket.recv(1024).decode('utf-8')
        print(f"Received message: {message}")
        client_socket.send("Message received!".encode('utf-8'))
        client_socket.close()

if __name__ == "__main__":
    start_server()
