import networkx as nx
import matplotlib.pyplot as plt


def buildNetwork(nodeList=None,edgeList=None):
	if nodeList is None:
		nodes = []
	if edgeList is None:
		edges = []

	network = nx.DiGraph()
	network.add_nodes_from(nodeList)
	network.add_edges_from(edgeList)

	return network

def drawNetwork(graph, specialNodes):
    fig, ax = plt.subplots()
    
    #pos = nx.kamada_kawai_layout(graph)
    # Ajustar el espacio de dibujo
    pos = nx.spring_layout(graph, k=39, iterations=80) 

    # Nodos
    nx.draw_networkx_nodes(graph, pos, node_color='#fe6f6a', node_size=400, ax=ax)

    # SuperNodos
    nx.draw_networkx_nodes(graph, pos, nodelist=specialNodes, node_color='#ffdd13', node_size=400, ax=ax)
    nx.draw_networkx_nodes(graph, pos, nodelist=["You"], node_color='#ff00ff', node_size=400, ax=ax)

    # nodos y edges
    nx.draw_networkx_edges(graph, pos, ax=ax)
    nx.draw_networkx_labels(graph, pos, ax=ax,font_size=8)

    plt.show()