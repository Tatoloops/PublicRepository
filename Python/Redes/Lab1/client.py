import socket

HOST = 'localhost'        # Symbolic name meaning all available interfaces
PORT = 65432              # Arbitrary non-privileged port\

def start_client(server_host=HOST, server_port=PORT):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((server_host, server_port))
    
    message = input("Enter a message to send: ")
    client_socket.send(message.encode('utf-8'))
    
    response = client_socket.recv(1024).decode('utf-8')
    print(f"Response from server: {response}")
    
    client_socket.close()

if __name__ == "__main__":
    start_client()
