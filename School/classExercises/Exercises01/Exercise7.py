"""
Desarrolle un programa que determine si un número es primo o no. Los números
primos son aquellos que al dividirlos por 2 su resto no es exacto, a excepción del
número 2.
"""
Number=float(input("declare a number: "))
count=2
prime=1
while(count<Number):
    NumberRest=Number % count
    if (NumberRest==0):
        prime=0
        count=Number
    count+=1
if(prime==0):
    print("number is NOT prime")
else:
    print("number is prime")

