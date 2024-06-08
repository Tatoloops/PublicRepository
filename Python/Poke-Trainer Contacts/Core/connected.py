import networkx as nx
#from itertools import combinations


def findNeighbours(graph, puntoZero):
	# Get all nodes in the graph
	all_nodes = set(graph.nodes)
	# Find direct out-neighbors of the starting node
	out_neighbors = set(graph.successors(puntoZero))

	smallest_set = set()
	visited = set()

	def dfs(node):
		for neighbor in graph.successors(node):
			if neighbor not in visited:
				visited.add(neighbor)
				dfs(neighbor)

	for neighbor in out_neighbors:
		if neighbor not in visited:
			smallest_set.add(neighbor)
			visited.add(neighbor)
			dfs(neighbor)

	return smallest_set


def directlyConnected(network,you):

	#nodes =list(network.successors(you)) -> returns 4 adyacents to YOU
	nodes= findNeighbours(network, you)
	#nodes= nx.algorithms.approximation.dominating_set.min_weighted_dominating_set(network)
	return nodes