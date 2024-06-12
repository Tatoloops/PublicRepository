import networkx as nx

def initializeSpecialAttributes(graph):

	# Initialize 'hasCPC' attribute for nodes
	for n in graph.nodes:
		graph.nodes[n]['hasCPC'] = False

	# Initialize 'hasCPC' attribute for edges
	for e in graph.edges:
		graph.edges[e]['hasCPC'] = False

def showCpcPlacement(node1,node2):
	print(f"CPC installed in route between : {node1} <---> {node2}")

def instalarCpc(grafo):
	# initialize
	initializeSpecialAttributes(grafo)
	edgeList= []
	# instala los CPC en aquellos nodos que solo tienen 1 posible CPC
	noMoreEmergencyCpcs=False
	while noMoreEmergencyCpcs==False:
		noMoreEmergencyCpcs=True
		for n in grafo.nodes:
			
			#si el nodo no tiene una ruta con centro pokemon
			if grafo.nodes[n]['hasCPC']==False:

				#se calcula el nivel de prioridad
				emergencyLevel = grafo.degree[n]

				#analizando si los vecinos ya tienen un CPC
				for neighbor in grafo.neighbors(n):
					if 'hasCPC' in grafo.nodes[neighbor] and grafo.nodes[neighbor]['hasCPC'] == True:
						emergencyLevel-=1
				# for neighbor in grafo.neighbors(n):
				# 	if grafo.edges[(n, neighbor)]['hasCPC']:
				# 		emergencyLevel -= 1

				#si solo tiene un posible edge para CPC lo instala ahi
				if emergencyLevel==1:
					noMoreEmergencyCpcs=False
					for neighbor in grafo.neighbors(n):
						if 'hasCPC' not in grafo.nodes[neighbor] or grafo.nodes[neighbor]['hasCPC'] == False:
							# Modificar 'hasCPC' value to True on both nodes
							grafo.nodes[n]['hasCPC'] = True
							grafo.nodes[neighbor]['hasCPC'] = True

							# Modificar 'hasCPC' value on the edge
							grafo.edges[(n, neighbor)]['hasCPC'] = True
							showCpcPlacement(n,neighbor)
							#for attribute, value in grafo.nodes[n].items():
							#	print(attribute, ":", value)
							break  # No need to check other neighbors if CPC is installed
				elif emergencyLevel==0:
					noMoreEmergencyCpcs=False
					for neighbor in grafo.neighbors(n):
						# Modificar 'hasCPC' value to True on both nodes
						grafo.nodes[n]['hasCPC'] = True
						grafo.nodes[neighbor]['hasCPC'] = True

						# Modificar 'hasCPC' value on the edge
						grafo.edges[(n, neighbor)]['hasCPC'] = True
						showCpcPlacement(n,neighbor)
						break
	return edgeList
