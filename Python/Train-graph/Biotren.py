import networkx as nx
import matplotlib as plt



#Construir grafo del biotren
def construirBiotren(G):
	#linea 2
	G.add_weighted_edges_from([(0,1,4),(1,2,2.3),(2,3,3),(3,4,7),(4,5,5),(5,6,5),(6,7,3),(7,8,4),(8,9,4),(9,10,6),(10,11,4),(11,12,5),(12,13, 8)])
	#linea 1 conce -> hualqui
	G.add_weighted_edges_from([(13,14,27),(14,15,18),(15,16,20),(16,17,5),(17,18,7)])
	#linea 1 conce -> mercado
	G.add_weighted_edges_from([(13,19,5),(19,20,6),(20,21,5),(21,22,4),(22,23,5),(23,24,3)])





#imprimir el diccionario completo/listado de todas las estaciones y simbologia
def imprimirEstaciones(grafoImprimir,listadoEstaciones):
  for w in grafoImprimir:
    print(f"Estación {w}: {listadoEstaciones[w]}")

#dibujar grafo
def makeGrapf(G):
	fig, ax = plt.subplots()

	nx.draw_kamada_kawai(G,with_labels=True, node_color='#ff87ab',node_size=500,ax=ax)



if __name__ == "__main__":
	# 1.Construir grafo
	miGrafo = nx.Graph()
	construirBiotren(miGrafo)
	# Diccionario conteniendo el par ordenado (número - nombre estación)
	Estaciones = {
		0: "Coronel",
		1: "Nova Rosa Medel",
		2: "Los Chiflones",
		3: "Los Molles",
		4: "Los Canelos",
		5: "Escuadrón",
		6: "Conavicoop",
		7: "Lomas Coloradas",
		8: "Costa Mar",
		9: "Alborada",
		10: "Diagonal Biobío",
		11: "Juan Pablo II",
		12: "Concepción",
		13: "Chiguayante",
		14: "Pedro Medina",
		15: "Manquimávida",
		16: "La Leonera",
		17: "Hualqui",
		18: "Lorenzo Arenas",
		19: "U.T.F Santa María",
		20: "Los Cóndores",
		21: "Las Higueras",
		22: "El Arenal",
		23: "Mercado"
	}


	# 2.Preguntar al usuario su recorrido
	print("Listado completo de Estaciones del Servicio Biotren: ")
	imprimirEstaciones(Estaciones,Estaciones)

	puntoInicio =int(input("ingrese estacion de inicio (numero): "))
	puntoFinal  =int(input("ingrese estacion de llegada (numero): "))

	# 3.calcular estaciones por las que debe pasar
	
	# Documentación de la función "shortest_path"
	# https://networkx.org/documentation/stable/reference/algorithms/generated/networkx.algorithms.shortest_paths.generic.shortest_path.html#networkx.algorithms.shortest_paths.generic.shortest_path
	
	miCamino =	nx.shortest_path(miGrafo, puntoInicio, puntoFinal)
	#miRecorrido = recorridoEstaciones(miGrafo,puntoInicio,puntoFinal)
	print("Listado del recorrido que realizarás: ")
	imprimirEstaciones(miCamino,Estaciones)


	# 4.imprimir recorrido + suma de tiempo (weight)
	#imprimirRecorrido(miRecorrido)
	#makeGrapf(miGrafo)