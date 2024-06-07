#file must read .txt files and extract their information

class Request:

	#Builder
	def __init__(self,_regionName="Teselia",_trainerName="Bianca"):
		#map information
		self.regionName =_regionName
		self.cities = []
		self.routes = []

		#trainer information
		self.trainerName =_trainerName
		self.travels = []

	#cities information
	def addCities(self,_city):
		self.cities.append(_city)
	def getCities(self):
		return self.cities

	#routes information
	def addRoutes(self,_route):
		self.routes.append(_route)
	def getRoutes(self):
		return self.routes

	#travels information
	def addTravels(self,_travelPoint):
		self.travels.append(_travelPoint)
	def getTravels(self):
		return self.travels



def readRequest(filename):
	#Open the request from a pokemon trainer and stores it in an instance of "Requested" class.
	aventura = Request()
	with open(filename, 'r') as file:

		#cities
		nCities = int(file.readline().strip())
		#city = []
		for i in range(nCities):
			aventura.addCities(file.readline().strip())

		#routes
		nRoutes = int(file.readline().strip())
		#routes = []
		for i in range(nRoutes):
			line=file.readline().strip()
			parts = line.split()
			route = (parts[0], parts[1], {"trainers": int(parts[2])})
			aventura.addRoutes(route)

		#Adventure path
		nTravels = int(file.readline().strip())
		#travels = []
		for i in range(nTravels):
			aventura.addTravels(file.readline().strip())

	return aventura

if __name__ == "__main__":
	filename = '../mapRequests/Bianca.txt'
	request = readRequest(filename)

	print("\n-- Cities --")
	for i in range(len(request.getCities())):
		print (request.getCities()[i],end=" ")
	print()
	
	print("\n-- Routes --")
	for i in range(len(request.getRoutes())):
		print(request.getRoutes()[i])

	print("\n-- Travels --")
	for i in range(len(request.getTravels())):
		print(request.getTravels()[i], end=" ")
	print()
