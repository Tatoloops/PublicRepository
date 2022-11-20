#include <stdio.h>
int mcm(int n0,int*numbers,unsigned short amount){
	int min;
	int sum[2]; // number of times the number will be multiplied. (n*2 n*3 n*4....)
	sum[0]=n0;
	sum[1]=*numbers;
	while(sum[0]!=sum[1]){
		if (sum[0]<sum[1])
			sum[0]+=n0;
		else
			sum[1]+=*numbers;
	}
	if (amount>2)
		min=mcm(sum[0],++numbers,--amount);
	else
		min=sum[0];
	return min;
}
unsigned short number (unsigned short*Permutation,unsigned char*Pswitch,unsigned short Psize,int*numbers){ 
	unsigned short i,j; 	//give the permutation array, its switch and size. Also the array where the numbers will be stored.
	unsigned short amount; 	//it returns the amount of numbers stored there
	unsigned short cycle;
	amount=0;
	for(i=0;i<Psize;++i){	
		while (*(Pswitch+i)==1)
			++i;
		*(Pswitch+i)=1;
		cycle=1;
		j=i;

		while(*(Permutation+j)!=i+1){
			j=*(Permutation+j)-1;
			*(Pswitch+j)=1;
			++cycle;
		}
		for(j=0;j<amount;++j){ //makes sure the number(cycle) is unique and not a multiply or divisor of another stored number.
			if (*(numbers+j)%cycle==0){
				cycle=1;
				j=amount;
			}
			else if (cycle%*(numbers+j)==0){
				*(numbers+j)=cycle;
				cycle=1;
				j=amount;
			}
		}
		if (cycle>1){
			*(numbers+amount)=cycle;
			++amount;
		}
	}

	return amount;
}
int main(void){
	unsigned short n,i,amount;
	int order;

	scanf("%hu",&n);
	unsigned short P[n+1];
	int numbers[n/2];
	unsigned char Pswitch[n+1];
	numbers[0]=1;

	for (i=0;i<n;++i){
		Pswitch[i]=0;
		scanf("%hu",P+i);
	}
	Pswitch[n]=0;
	P[n]=n+1;
	
	//getting the cycles/numbers
	amount=number(P,Pswitch,n,numbers);

	if(amount>1)
		order=mcm(*numbers,numbers+1,amount);
	else
		order=numbers[0];
	printf("%u",order);
	return 0;
}