A=int(input("declare first number: "))
B=int(input("declare second number: "))
if (A<B):
    A=B
B=int(input("declare third number: "))
if (A<B):
    A=B
print(f"Biggest number is {A}")
