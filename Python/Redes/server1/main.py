import os
import subprocess
import sys


python="python3"



def open_new_console(command):
    if sys.platform.startswith('win'):
        # Windows command to open a new console window and keep it open
        subprocess.Popen(['start', 'cmd', '/k', command], shell=True)
    elif sys.platform.startswith('linux'):
        # Linux command to open a new terminal window and keep it open
        subprocess.Popen(['gnome-terminal', '--', 'bash', '-c', f'{command}; exec bash'])
    elif sys.platform.startswith('darwin'):
        # macOS command to open a new terminal window and keep it open
        subprocess.Popen(['open', '-a', 'Terminal', command])
    else:
        print("Unsupported OS, try manually opening client and host")



if __name__ == "__main__":
    # Command to start the server
    server_command = python+" serverFiles/host.py"
    # Command to start the client
    client_command = python+" clientFiles/client.py"
    
    # Open server in a new console
    open_new_console(server_command)
    
    # Open client in a new console
    open_new_console(client_command)
