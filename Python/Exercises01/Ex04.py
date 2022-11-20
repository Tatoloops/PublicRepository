"""
Algoritmo que lea tres números distintos y nos diga cuál de ellos es el mayor.
"""
A=int(input("first value: "))
B=int(input("second value: "))
if A<B:
	A=B
B=int(input("third value: "))
if A<B:
	A=B
print(f"highest value: {A}")