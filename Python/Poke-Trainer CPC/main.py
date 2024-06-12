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
		request = rq.readRequest(filenamePath,"Teselia")
	else:
		request = rq.readRequest(filenamePath)

	#3. Make Region/graph
	region = rn.buildRegion(request.getRoutes())
	#	Print Region information(Debug, toString)
	#request.toString()
	#rn.drawRegion(region)

	#3. Install CPCs
	edges=sr.instalarCpc(region)

	#4. show results
	#for edge in region.edges:
	#	print(region.edges[edge])
	rn.drawRegion_Edges(region,'hasCPC')