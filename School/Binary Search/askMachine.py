import random
import time
#version 1


def busquedaBinaria1(x):
	sup=100
	inf=1
	while (sup>=inf):
		intento=sup+100
		while intento > sup or intento <inf:
			time.sleep(1)
			intento=int(input(f"-> intenta adivinar mi numero (entre {inf} - {sup}): "))
		if intento==x:
			return True
		elif intento>x:
			time.sleep(1)
			print("-> mi numero es menor...")
			sup=intento-1
		else:
			time.sleep(1)
			print("-> mi numero es mayor...")
			inf=intento+1
	return False	

def version1():
	print("-> Debes adivinar mi numero del 1 al 100")
	numeroSecreto = random.randint(1, 100)
	if busquedaBinaria1(numeroSecreto):
		print(f"-> Felicidades, has encontrado mi numero {numeroSecreto}")
	else:
		print(f"-> equivocado, mi numero era {numeroSecreto}")

def busquedaBinaria2():
	sup=100
	inf=1
	time.sleep(1)
	print("   ...pensando...")
	time.sleep(1)
	while (sup>=inf):
		med=int((sup+inf)/2)
		question=input(f"-> es tu numero.... {med}? (y/ma/me):")
		if question=="y":
			return med
		elif question=="me":
			time.sleep(1)
			print("-> me has dicho que tu numero es menor")
			sup=med-1
		elif question=="ma":
			time.sleep(1)
			print("-> tu number es MAYOR!")
			inf=med+1
	return False	

def version2():
	#tuNumber = int(input("escoge un numero del 1 al 100: "))
	print("\n\n-> Debes escoger un numero entre 1 y 100 (ambos incluidos)")
	time.sleep(2)
	print("-> No es necesario que lo ingreses por computadora, yo no necesito hacer trampas")
	time.sleep(2)
	print("-> tu tampoco hagas trampas")
	time.sleep(1)
	print("   ...")
	time.sleep(1)
	print("-> que comience el juego!")
	time.sleep(1)
	print("   0.0")
	tuNumber=busquedaBinaria2()
	if tuNumber==False:
		print("-> hiciste trampas >:(")
	else:
		print(f"-> He logrado encontrar tu number {tuNumber}")





if __name__ =="__main__":
	game = int (input("escoge 1 o 2 segun la version del juego que desees:"))

	if game==1:
		version1()

	elif game ==2:
		version2()

