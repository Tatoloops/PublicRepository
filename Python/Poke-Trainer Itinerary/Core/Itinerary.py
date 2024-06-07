import networkx as nx



def construirTeselia(G):
	G.add_weighted_edges_from([("L1","M1",{"trainers": 5}),("M1","A1",{"trainers": 15}),("A1","C2",{"trainers": 13})])
	G.add_weighted_edges_from([("A1","L2",{"trainers":9}),("L2","C1",{"trainers":20}),("C1","T1",{"trainers":6}),("T1","L3",{"trainers":18}),("L3","F",{"trainers":14}),("F","M2",{"trainers":10}),("M2","N",{"trainers":10}),("N","A1",{"trainers":14})])
	G.add_weighted_edges_from([("M2","P",{"trainers":16}),("P","H",{"trainers":13}),("H","O",{"trainers":5}),("O","E2",{"trainers":10})])
	G.add_weighted_edges_from([("P","E1",{"trainers":19}),("E1","G",{"trainers":8}),("G","T2",{"trainers":8}),("T2","A2",{"trainers":13})])

def construirDiccionario():
	diccionario={
		"L1": "Liga Pokemon",
		"T1": "Ciudad Teja",
		"C1": "Ciudad Caolin",
		"L2": "Pueblo Ladrillo",
		"M1": "Ciudad Marga",
		"L3": "Ciudad Loza",
		"C2": "Pueblo Chamota",
		"A1": "Pueblo Arenisca",
		"F" : "Ciudad Fayenza", 
		"M2": "Ciudad Mayolica",
		"N" : "Ciudad Negra",
		"O" : "Pueblo Ocre",
		"H" : "Ciudad Hormigon",
		"P" : "Ciudad POrcelana",
		"E1": "Ciudad Esmalte",
		"G" : "Ciudad Gres",
		"T2": "Pueblo Terracota",
		"E2": "Ciudad Engobe",
		"A2": "Pueblo Arcilla"
	}
	return diccionario

def buscarRecorrido(grafo,puntoInicio,puntoFinal):
	recorrido = nx.shortest_path(grafo,puntoInicio,puntoFinal,"trainers")

#dibujar mapa
def makeGraph(G):
	fig, ax = plt.subplots()

	nx.draw_kamada_kawai(G,with_labels=True, node_color='#ff87ab',node_size=500,ax=ax)



if __name__ == "__main__":
