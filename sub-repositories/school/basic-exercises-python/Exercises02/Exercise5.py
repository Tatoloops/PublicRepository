count=0
quantity=0
while(count<100):
    if count%2!=0:
        print(str(count), ", ", end="")
        quantity+=1
    count+=1
print("99")
print(f"there are :{quantity} odd numbers")