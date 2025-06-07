# 'eliminarRepetidos' funciona pero tiene un ciclo "for", por lo tanto no se usa en el main()

#def eliminarRepetidos(srcArray):
#	destArray=[]
#	if checkLista(srcArray[1:],srcArray[0])==True:
#		destArray.append(srcArray[0])
#	if len(srcArray)>1:
#		tempArray=eliminarRepetidos(srcArray[1:])
#		for i in range (0,len(tempArray)):	
#			destArray.append(tempArray[i])
#	return destArray



#verifica si el numero actual "x" se repite en el resto del array.
def checkLista(array,x):
	if len(array)>=1:
		if array[0]==x:
			return False
		else:
			return checkLista(array[1:],x)
	else:
		return True
		
		
#algoritmo actual para remover valores repetidos de un array.
def removerRepetidos(srcArray,current):
	if len(srcArray)>current+1:
		if checkLista(srcArray[(current+1):],srcArray[current])==True:
			return removerRepetidos(srcArray,current+1)
		else:
			srcArray.pop(current)
			return removerRepetidos(srcArray,current)
	else:
		return srcArray

#main
def main():
	arraySize=int(input("ingresar array size: "))
	array=[]
	for i in range(0,arraySize):
		array.append(int(input(f"ingresar valor en la posicion {i} del array: ")))
	print(f"el array sin valores repetidos es: {removerRepetidos(array,0)}")

#ejecucion del codigo
main()
