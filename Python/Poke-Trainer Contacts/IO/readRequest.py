import networkx as nx
import matplotlib.pyplot as plt

class Contact:
	#Contact class holds all the information from 1 line of request file

	#Builder
	def __init__(self,_trainerName="trainer"):
		#contact information
		self.__name = _trainerName
		self.__contacts = [] #array 
		self.__reserved = False #boolean

	#Basic Getters
	def getName(self):
		return self.__name
	def getContacts(self):
		return self.__contacts
	def getReserved(self):
		return self.__reserved

	#setters
	def setName(self,_name):
		self.__name=_name
	def addContacts(self,_contact):
		self.__contacts.append(_contact)
	def setReserved(self,_bool):
		self.__reserved=_bool

	#printing function
	def toString(self):

		#personal information
		print(f"\n-- {self.__name} -- ",end="")
		if self.__reserved==True:
			print("RESERVED/SHY!")
		else:
			print()

		#contacts
		print("   ",end="")
		for i in range(len(self.getContacts())):
			print (self.getContacts()[i],end=" ")
		print()

def readRequest(filename):
	#Open the request from a pokemon trainer and stores it in an instance of "Requested" class.
	circle = []

	with open(filename, 'r') as file:

		#contacts
		netSize = int(file.readline().strip())

		for i in range(netSize):

			#read whole line and split
			line=file.readline().strip()
			parts = line.split()
			#print(f"parts: {len(parts)}")
			#get name
			name=parts[0]

			#get n of contacts
			nContacts=int(parts[1])

			#get all contacts
			contacts=[]
			for j in range(nContacts):
				#print(j)
				contacts.append(parts[2+j])

			#get reserved
			reserved=False
			if parts[len(parts)-1]=="yes":
				reserved=True

			#write values into Contact class
			person=Contact(name)
			person.setReserved(reserved)
			for j in range(len(contacts)):
				person.addContacts(contacts[j])
			#person.addContacts(contacts)

			#write into network
			circle.append(person)

	return circle

def buildNetwork(contacts):
	#create directed graph
	network = nx.DiGraph()

	# -- add nodes -- 
	for i in range(len(contacts)):
		network.add_node(contacts[i].getName())
	network.add_node("You")

	# -- add edges --
	#print("edges")
	for i in range(len(contacts)):
		#print(i)
		#Only contact list can contact this user
		for j in range(len(contacts[i].getContacts())):
			#print(contacts[i].getContacts())
			#print(contacts[i].getContacts()[j])
			#print(f"{contacts[i].getContacts()[j]} -> {contacts[i].getName()}")
			network.add_edge(contacts[i].getContacts()[j],contacts[i].getName())

			#print(f"{contacts[i].getContacts()[j]} -> {contacts[i].getName()}")
		
		#Anyone can contact non-reserved users
		#print(contacts[i].getReserved())
		if contacts[i].getReserved()==False:
			for j in range(len(contacts)):
				#print(f"{contacts[j].getName()} -> {contacts[i].getName()}")
				network.add_edge(contacts[j].getName(),contacts[i].getName())
			#you can contact users that are not reserved
			network.add_edge("You",contacts[i].getName())

	return network


def importNetwork(filename):
	contacts = readRequest(filename)

	#debug print contacts
	#for i in range(len(contacts)):
	#	contacts[i].toString()

	network = buildNetwork(contacts)
	
	return network

def drawNetwork(graph):
	# fig, ax = plt.subplots()
	# pos = nx.kamada_kawai_layout(graph)
	# nx.draw_kamada_kawai(graph,with_labels=True, node_color='#ff87ab',node_size=500,ax=ax)
	# plt.show
	fig, ax = plt.subplots()
	pos = nx.kamada_kawai_layout(graph)
	nx.draw(graph, pos, with_labels=True, node_color='#fe6a86', node_size=2000, ax=ax)
	#nx.draw_networkx_nodes(graph, pos, nodelist=recorrido, node_color='#ffdd13', node_size=500, ax=ax)
	plt.show()


if __name__ == "__main__":
	filename = '../Requests/Encina.txt'
	network = importNetwork(filename)

	drawNetwork(network)