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
		print("--- Itinerario a recorrer ---")
		for i in range(len(self.__mainPoints)-1):
			print(f"Desde {self.__mainPoints[i]} hasta {self.__mainPoints[i+1]}: ")
			print("recorreras los puntos:")
			for j in range(len(self.__passPoints[i])):
				print(f"{self.__passPoints[i][j]} -> ",end ="")
			print(f"enfrentando a un total de {self.__trainers[i]} entrenadores")
		print(f"Finalmente llegas a tu destino enfrentando a {self.__totalTrainers}.")

def buscarItinerario(region,_mainPoints):
	itinerary = Itinerary(_mainPoints)

	#Loop all destinations and extract both: n of trainers and routes to follow
	for i in range(len(itinerary.getMainPoints())-1):
		strPoint=itinerary.getMainPoints()[i]
		endPoint=itinerary.getMainPoints()[i+1]
		itinerary.addPassPoints(nx.shortest_path(region,strPoint,endPoint,weight='trainers'))
		itinerary.addTrainers(nx.shortest_path_length(region,strPoint,endPoint,weight='trainers'))
		itinerary.addTotalTrainers(itinerary.getTrainers(i))
	return itinerary

#if __name__ == "__main__":
