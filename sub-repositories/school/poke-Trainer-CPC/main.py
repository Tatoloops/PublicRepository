from Core import Region as rn
from Core import Search as sr
from IO import readRequest as rq


if __name__ == "__main__":

	#1. filename
	filenamePath = "Requests/"
	filename  	 = input("Introduce the name of your request file: ")
	filenamePath +=filename
	#filenamePath +=".txt"

	#2. Extract information
	if (filename == "Joey"):
		edges = rq.readRequest(filenamePath,"Teselia")
	else:
		edges = rq.readRequest(filenamePath)

	#3. Make Region/graph
	region = rn.buildRegion(edges)

	#rn.drawRegion(region)

	#3. Install CPCs
	edges=sr.instalarCpc(region)

	#4. show results
	rn.drawRegion_Edges(region,'hasCPC')