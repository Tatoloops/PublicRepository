import networkx as nx

def DFS(G,v0,encontrados=[],padres={},tiempo=0,inicio_p={},fin_p={}):
    tiempo+=1
    inicio_p[v0]=tiempo
    if encontrados==[]:
        encontrados=[v0]
        padres[v0]=None
    for w in G.neighbors(v0):
        if w not in encontrados:
            encontrados.append(w)
            padres[w]=v0
            encontrados,padres,tiempo,inicio_p,fin_p = DFS(G,w,encontrados,padres,tiempo,inicio_p,fin_p)
    tiempo+=1
    fin_p[v0]=tiempo
    return encontrados,padres,tiempo,inicio_p,fin_p

G = nx.Graph()
G.add_edges_from([(0,1), (6,2), (1,3), (1,4), (7,8), (7,3), (10,2), (2,3), 
                  (2,4), (3,4), (6,9), (5,7), (6,8), (8,9), (6,10)])
encontrados, padres, tiempo, inicio_p, fin_p=DFS(G,1)
print('El orden de recorrido es {}'.format(encontrados))
print('El diccionario de padres es {}'.format(padres))
print('El tiempo total usado es {}'.format(tiempo))
print('El diccionario de inicio de procesamiento es {}'.format(inicio_p))
print('El diccionario de fin de procesamiento es {}'.format(fin_p))
nx.draw_kamada_kawai(G,with_labels=True, node_color='#22bbbb',node_size=500)
KKL=nx.kamada_kawai_layout(G)