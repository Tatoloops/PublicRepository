class Request:
	#Request class holds all the information extracted from the request files.

	#Builder
	def __init__(self,_trainerName="trainer",_regionName="region"):
		#map information
		self.__regionName =_regionName
		self.__cities = []
		self.__routes = []

		#trainer information
		self.__trainerName =_trainerName
		self.__travels = []

	#Basic Getters
	def getTrainer(self):
		return self.__trainerName
	def getRegion(self):
		return self.__regionName

	#cities information
	def addCities(self,_city):
		self.__cities.append(_city)
	def getCities(self):
		return self.__cities

	#routes information
	def addRoutes(self,_route):
		self.__routes.append(_route)
	def getRoutes(self):
		return self.__routes

	#travels information
	def addTravels(self,_travelPoint):
		self.__travels.append(_travelPoint)
	def getTravels(self):
		return self.__travels

	#printing function
	def toString(self):
		print("\n-- Cities --")
		for i in range(len(self.getCities())):
			print (self.getCities()[i],end=" ")
		print()
		
		print("\n-- Routes --")
		for i in range(len(self.getRoutes())):
			print(self.getRoutes()[i])

		print("\n-- Travels --")
		for i in range(len(self.getTravels())):
			print(self.getTravels()[i], end=" ")
		print()


def readRequest(filename,_trainer="trainer",_region="region"):
	#Open the request from a pokemon trainer and stores it in an instance of "Requested" class.
	aventura = Request(_trainer,_region)
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
	filename = '../Requests/Bianca.txt'
	request = readRequest(filename)
	request.toString()