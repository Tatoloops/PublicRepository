#networkx to make graphs
import networkx as nx

#import files and extract the information as pokemon trainer request
import documentReader.py as dc

def construirRegion(region,request):
	region.add_weighted_edges_from(request.getRoutes())

# def construirDiccionario():
# 	diccionario={
# 		"L1": "Liga Pokemon",
# 		"T1": "Ciudad Teja",
# 		"C1": "Ciudad Caolin",
# 		"L2": "Pueblo Ladrillo",
# 		"M1": "Ciudad Marga",
# 		"L3": "Ciudad Loza",
# 		"C2": "Pueblo Chamota",
# 		"A1": "Pueblo Arenisca",
# 		"F" : "Ciudad Fayenza", 
# 		"M2": "Ciudad Mayolica",
# 		"N" : "Ciudad Negra",
# 		"O" : "Pueblo Ocre",
# 		"H" : "Ciudad Hormigon",
# 		"P" : "Ciudad POrcelana",
# 		"E1": "Ciudad Esmalte",
# 		"G" : "Ciudad Gres",
# 		"T2": "Pueblo Terracota",
# 		"E2": "Ciudad Engobe",
# 		"A2": "Pueblo Arcilla"
# 	}
# 	return diccionario

def buscarRecorrido(grafo,puntoInicio,puntoFinal):
	recorrido = nx.shortest_path(grafo,puntoInicio,puntoFinal,"trainers")
	entrenadores = nx.shortest_path_length(miGrafo,puntoInicio,puntoFinal,"trainers")

#dibujar mapa
def makeGraph(G):
	fig, ax = plt.subplots()

	nx.draw_kamada_kawai(G,with_labels=True, node_color='#ff87ab',node_size=500,ax=ax)



if __name__ == "__main__":
	request = dc.Request("Bianca")