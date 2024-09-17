import networkx as nx
import matplotlib.pyplot as plt

def BFS(G,v0):
    encontrados={v0}
    procesados=set()
    en_proceso=[v0]

    while en_proceso:
        v=en_proceso[0]
        print(v) #Aquí decidimos que hacer al comenzar a procesar un vértice
        for w in G.neighbors(v):
            if (w not in procesados) and (w not in encontrados):
                encontrados.add(w)
                en_proceso.append(w)
        en_proceso.remove(v)
        procesados.add(v)


if __name__ == "__main__":
	G = nx.Graph()
	G.add_edges_from([(0,1,5), (0,2,3), (0,3,8), (1,4,1), (7,4,2.6), (10,2,5.0), (2,3,4), (2,4,2), 
	                  (3,4,5), (6,7,6), (5,7,8), (6,8,0), (8,9,1), (6,10,6)])
    
	

	BFS(G,0)
    fig, ax = plt.subplots()
    nx.draw_kamada_kawai(G,with_labels=True, node_color='#22bbbb',node_size=500,ax=ax)
