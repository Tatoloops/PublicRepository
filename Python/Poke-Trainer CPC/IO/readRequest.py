class Request:
	#Request class holds all the information extracted from the request files.

	#Builder
	def __init__(self,_regionName="region"):
		#map information
		self.__regionName =_regionName
		self.__cities = []
		self.__routes = []

	#Basic Getters
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


	#printing function
	def toString(self):
		print(f"\n---- {self.__regionName} ----")
		print("\n-- Cities --")
		for i in range(len(self.getCities())):
			print (self.getCities()[i],end=" ")
		print()
		
		print("\n-- Routes --")
		for i in range(len(self.getRoutes())):
			print(self.getRoutes()[i])


def readRequest(filename,_region="region"):
	#Open the request from a pokemon trainer and stores it in an instance of "Requested" class.
	aventura = Request(_region)
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
			route = (parts[0], parts[1])
			aventura.addRoutes(route)


	return aventura


if __name__ == "__main__":
	filename = '../Requests/Joey.txt'
	request = readRequest(filename)
	request.toString()