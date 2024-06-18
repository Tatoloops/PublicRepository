from Core import Region as rn
from Core import Itinerary as it
from IO import readRequest as rq
if __name__ == "__main__":

	#1. Request your itinerary
	filenamePath = "Requests/"
	filename  	 = input("Introduce the name of your request file: ")
	filenamePath +=filename
	#filenamePath +=".txt"

	#2. Build your itinerary
	if (filename == "Bianca"):
		request = rq.readRequest(filenamePath,"Bianca","Teselia")
	else:
		request = rq.readRequest(filenamePath)

	#3. Make Region
	region = rn.buildRegion(request.getRoutes())
	#	Print Region (Debug)
	#request.toString()
	#rn.drawRegion(region)

	#3. Find shortest path and trainers to fight
	itinerary = it.buscarItinerario(region,request.getTravels())


	#4. show results
	itinerary.toString()

	rn.drawRegion(region)
