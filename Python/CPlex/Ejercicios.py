from docplex.mp.model import Model as ml

#inicializar modelo
modelo = ml("miModelo")

# -- parametros --
n =6 #num paquetes
m =4 #furgonetas para enviar
v={(1):20,(2):30,(3):40,(4):50}
p={(1):1000,(2):1500,(3):2000,(4):2500}

vv={(1):10,(2):25,(3):35,(4):15,(5):20,(6):45}
pp={(1):400,(2):900,(3):1100,(4):600,(5):800,(6):2000}
gg={(1):300,(2):600,(3):800,(4):400,(5):500,(6):900}


# -- variables --
ind_ij=[(i,j) for i in range(1,n+1) for j in range(1,m+1)]

x=modelo.binary_var_dict(ind_ij,name='x')

# -- Funcion principal --
model.maximize()

print(x)
# -- sa --

# -- resolucion --
