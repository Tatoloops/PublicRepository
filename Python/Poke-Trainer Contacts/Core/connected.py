import networkx as nx

def directlyConnected(network,you):

	nodes =list(network.successors(you))

	return nodes