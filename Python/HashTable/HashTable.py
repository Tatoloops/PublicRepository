class HashTable:

	#constructor
	def __init__(self, _size):
		#tamano del array definido
		self.__size = _size
		
		#se crea la tabla hash
		self.__table = [None] * _size
		for i in range(_size):
			self.__table[i]=[]

	#insertar datos a la tabla hash 
	def addNumber(self, _numIngresado):
		indiceHash = _numIngresado%self.__size
		self.__table[indiceHash].append(_numIngresado)

	# mostrar la tabla hash
	def toString(self):
		for i in range(self.__size):
			print(f'index {i}: {self.__table[i]}')


if __name__ == "__main__":

	# crear tabla hash 
	tabla = HashTable(10)


	# Ingresar los numeros
	n = int(input("Ingrese la cantidad de numbers a insertar: "))
	print(f"Ingrese {n} numbers:")

	for _ in range(n):
		num = int(input())
		tabla.addNumber(num)


	# Mostrar los numeros
	print("aqui esta la tabla hash:")
	tabla.toString()
