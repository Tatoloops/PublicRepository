from Core import connected as it
from IO import readRequest as rq
if __name__ == "__main__":

	#1. Request your itinerary
	filenamePath = "Requests/"
	filename  	 = input("Introduce the name of your request file: ")
	filenamePath +=filename
	#filenamePath +=".txt"

	network = rq.importNetwork(filenamePath)

	#3. Find shortest path and trainers to fight
	directContacts = it.directlyConnected(network,"You")

	#4. show results
	print(directContacts)

	rq.drawNetwork(network)