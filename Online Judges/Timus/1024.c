#include <stdio.h>
#include <stdlib.h>
int inner_mcm(unsigned short*numbers,short int count_0,unsigned short amount){
	 //give the array with the numbers and the amount of numbers, returns the mcm.
	short int count_1=1; // number of times the number will be multiplied. (n*2 n*3 n*4....)
	if (amount>2)
			inner_mcm(numbers+1,count_1,amount-1);
	do{

		if (count_0**(numbers)<count_1**(numbers+1))
			++count_0;
		else{
			++count_1;
			if (amount>2)
				count_1=inner_mcm(numbers+1,count_1,amount-1);
		}
	}
	while(count_0**(numbers)!=count_1**(numbers+1));
	return count_0;
}
int mcm(unsigned short*numbers,unsigned short amount){
	//give the array with the numbers and the amount of numbers, returns the mcm.
	int min=1;
	short int i=0;
	short int count[2]; // number of times the number will be multiplied. (n*2 n*3 n*4....)
	count[0]=1;
	count[1]=1;
	if (amount>2)
			count[1]=inner_mcm(numbers+1,*(count+1),amount-1);
	do{

		if (count[0]**(numbers)<count[1]**(numbers+1))
			++count[0];
		else{
			++count[1];
			if (amount>2)
				count[1]=inner_mcm(numbers+1,*(count+1),amount-1);
		}
	}
	while(count[0]**(numbers)!=count[1]**(numbers+1));
	min=count[0]**(numbers);
	return min;
}
int inner_mcm2(short int n0,unsigned short*numbers,unsigned short amount){
	int min=1;
	short int sum[2]; // number of times the number will be multiplied. (n*2 n*3 n*4....)
	sum[0]=n0;
	sum[1]=*numbers;
	while(sum[0]!=sum[1]){
		if (sum[0]<sum[1])
			sum[0]+=n0;
		else(sum[0]<sum[1])
			sum[1]+=*numbers;
	}
	if (amount>2)
		min==inner_mcm2(sum[0],numbers+1,amount-1);
	else
		min=sum[0];
	return min;
}
int mcm2(unsigned short*numbers,unsigned short amount){
	int min=1;
	short int sum[2]; // number of times the number will be multiplied. (n*2 n*3 n*4....)
	sum[0]=*numbers;
	sum[1]=*(numbers+1);
	while(sum[0]!=sum[1]){
		if (sum[0]<sum[1])
			sum[0]+=*numbers;
		else
			sum[1]+=*(numbers+1);
	}
	if (amount>2)
		min==inner_mcm2(sum[0],numbers+2,amount-1);
	else
		min=sum[0];
	return min;
}

unsigned short number (unsigned short*Permutation,unsigned char*Pswitch,unsigned short Psize,unsigned short*numbers){
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
	unsigned int order;

	scanf("%hu",&n);
	unsigned short P[n+1];
	unsigned short numbers[n/2];
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
		order=inner_mcm2(*numbers,numbers+1,amount);
	else
		order=numbers[0];
	printf("%u",order);
	return 0;
}
