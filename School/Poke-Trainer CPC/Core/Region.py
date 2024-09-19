
import networkx as nx
import matplotlib.pyplot as plt

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

#Construir region
def buildRegion(routes):
	region = nx.Graph()

	region.add_edges_from(routes)
	# print(region)
	# for edge in region.edges(data=True):
	# 	print(edge)
	return region


#dibujar mapa
def drawRegion(region):

	fig, ax = plt.subplots()
	pos = nx.kamada_kawai_layout(region)
	nx.draw(region, pos, with_labels=True, node_color='#fe6a86', node_size=500, ax=ax)
	plt.show()

def drawRegion_Edges(region,edgeAttribute):
    fig, ax = plt.subplots()
    pos = nx.kamada_kawai_layout(region)

    # Draw all nodes
    nx.draw_networkx_nodes(region, pos, node_color='#fe6a86', node_size=500, ax=ax)
    nx.draw_networkx_labels(region, pos, ax=ax)

    # Separate edges based on the 'hasCPC' attribute
    edges_with_cpc = [(u, v) for u, v, d in region.edges(data=True) if d.get(edgeAttribute, False)]
    edges_without_cpc = [(u, v) for u, v, d in region.edges(data=True) if not d.get(edgeAttribute, False)]

    # Draw edges without 'hasCPC' attribute
    nx.draw_networkx_edges(region, pos, edgelist=edges_without_cpc, ax=ax, edge_color='black')

    # Draw edges with 'hasCPC' attribute
    nx.draw_networkx_edges(region, pos, edgelist=edges_with_cpc, ax=ax, edge_color='red', width=2.0)

    plt.show()



#if __name__ == "__main__":

	#1. Get trainers's request:
	#request = dc.Request("Bianca","Teselia")

	#2. Build Region:
	#region=buildRegion({insert array with edges})

	#3. Visualize Region:
	#drawRegion(region)