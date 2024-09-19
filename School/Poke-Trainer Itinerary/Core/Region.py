#networkx to make graphs
import networkx as nx
import matplotlib.pyplot as plt
#import files and extract the information as pokemon trainer request
#from IO import readRequest as rq

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
	region = nx.Graph(weight_name='custom_weight')

	region.add_edges_from(routes)
	# print(region)
	# for edge in region.edges(data=True):
	# 	print(edge)
	return region


#dibujar mapa
def drawRegion(region):
	# fig, ax = plt.subplots()
	pos = nx.kamada_kawai_layout(region)
	# nx.draw_kamada_kawai(region,with_labels=True, node_color='#ff87ab',node_size=500,ax=ax)
	# plt.show
	fig, ax = plt.subplots()
	# pos = nx.kamada_kawai_layout(region,weight='trainers')
	nx.draw(region, pos, with_labels=True, node_color='#fe6a86', node_size=500, ax=ax)
	#nx.draw_networkx_nodes(region, pos, nodelist=recorrido, node_color='#ffdd13', node_size=500, ax=ax)
	plt.show()



#if __name__ == "__main__":

	#1. Get trainers's request:
	#request = dc.Request("Bianca","Teselia")

	#2. Build Region:
	#region=buildRegion({insert array with edges})

	#3. Visualize Region:
	#drawRegion(region)
