import networkx as nx

class Itinerary:
	def __init__(self,_mainPoints):
		self.__mainPoints = _mainPoints
		self.__passPoints = []
		self.__trainers	 = []
		self.__totalTrainers =0

	#getters
	def getMainPoints(self):
	 	return self.__mainPoints
	# def getPassPoints(self,i):
	# 	return self.__passPoints[i]
	def getTrainers(self,i):
		return self.__trainers[i]
	# def getTotalTrainers(self):
	# 	return self.__totalTrainers

	#setters
	def addPassPoints(self,_array): 
		#here whole arrays must be added, not singular values
		self.__passPoints.append(_array)
	def addTrainers(self,_amount):
		self.__trainers.append(_amount)
	def addTotalTrainers(self,amount):
		self.__totalTrainers+=amount

	def toString(self):
		print("\0\0--- Itinerario a recorrer ---")
		for i in range(len(self.__mainPoints)-1):
			#print(f" ~Desde {self.__mainPoints[i]} hasta {self.__mainPoints[i+1]}: ")
			#print("recorreras los puntos:")
			print("   --",end="")
			for j in range(len(self.__passPoints[i])):
				print(f"{self.__passPoints[i][j]}",end ="")
				if j != len(self.__passPoints[i])-1:
					print(f" -> ",end ="")

			print(f" ||      vs {self.__trainers[i]} trainers")
			#print()
		print(f"Finalmente llegas a tu destino enfrentando a {self.__totalTrainers} trainers.")

def buscarItinerario(region,_mainPoints):
	itinerary = Itinerary(_mainPoints)

	#Loop all destinations and extract both: n of trainers and routes to follow
	for i in range(len(itinerary.getMainPoints())-1):
		#calculate shortest path
		strPoint=itinerary.getMainPoints()[i]
		endPoint=itinerary.getMainPoints()[i+1]
		shortest_path = nx.shortest_path(region, strPoint, endPoint, weight='trainers')

		trainers_on_path = 0 
		
		for i in range(len(shortest_path) - 1):
			#print(region[shortest_path[i]][shortest_path[i+1]])

			current_edge_trainers = region[shortest_path[i]][shortest_path[i+1]]['trainers']
			trainers_on_path += current_edge_trainers

		itinerary.addPassPoints(shortest_path)
		itinerary.addTrainers(trainers_on_path)
		itinerary.addTotalTrainers(trainers_on_path)
	return itinerary

#if __name__ == "__main__":
