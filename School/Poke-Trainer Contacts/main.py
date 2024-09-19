from Core import connected as it
from Core import Region as rn
from IO import readRequest as rq


if __name__ == "__main__":

	#1. Request your itinerary
	filenamePath = "Requests/"
	filename  	 = input("Introduce the name of your request file: ")
	filenamePath +=filename
	#filenamePath +=".txt"

	#extract network information
	nodes=[]
	edges=[]
	nodes,edges=rq.extractNodesEdges(filenamePath)

	#print(nodes)
	#3. Build network
	network= rn.buildNetwork(nodes,edges)

	#4. Find who you must send the message to
	directContacts = it.directlyConnected(network,"You")

	#5. show results
	print(f"si quieres transmitir tu mensaje a todos los entrenadores contactar con:\n{directContacts}")
	rn.drawNetwork(network,directContacts)