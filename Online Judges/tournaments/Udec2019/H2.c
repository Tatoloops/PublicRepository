#include <stdio.h>
#include <math.h>

#define MaxNumbers 512

typedef struct  {
    char number[MaxNumbers];
    int size;
}BigNumber;

void BigNumReset(BigNumber* MainNumber){
	for(int i=0;i<MaxNumbers;++i)
		MainNumber->number[i]=0;
	MainNumber->size=0;
	return;
}
void BigNumConvert(BigNumber* MainNumber,int digital){
	BigNumReset(MainNumber);
	for(int i=0;i<10;++i)
		MainNumber->number[i]=digital%(10*(i+1))-digital%(10*(i));
	for(int i=9;i>=0;--i)
		if (MainNumber->number[i]>0){
			MainNumber->size=i+1;
			i=0;
		}
	return;
}

void BigNumCopy(BigNumber* destination,BigNumber* source){
		for(int i=0;i<source->size;++i)
			destination->number[i]=source->number[i];
		destination->size=source->size;
	return;
}


void BigNumDecimal(BigNumber* MainNumber,int position){
	if (MainNumber->number[position]>9){
		MainNumber->number[position]-=10;
		MainNumber->number[position+1]+=1;
		MainNumber->size=position+1;
		BigNumDecimal(MainNumber,position+1);
	}
	return;
}
void BigNumSum(BigNumber* MainNumber, BigNumber* Bignumber2){

	BigNumber Bignumber1;

	int reserve,sum;

	int size1=MainNumber->size;
	int size2=Bignumber2->size;

	BigNumCopy(&Bignumber1,MainNumber);
	BigNumReset(MainNumber);
	
	if (size1>size2){
		for(int i=0;i<size2;++i){
			sum=Bignumber1.number[i]+Bignumber2->number[i];
			reserve=(sum)/10;
			sum=sum%10;
			MainNumber->number[i]+=sum;
			MainNumber->size=i;
			if (reserve>0){
				MainNumber->number[i+1]+=reserve;
				MainNumber->size=i+1;
			}
			BigNumDecimal (MainNumber,i);
		}
	}
}
void BigNumSumEscalar(BigNumber* MainNumber, int digit){
	BigNumber A;
	BigNumConvert(&A,digit);
	BigNumSum(MainNumber,&A);
	return;
}
void BigNumMultiplication(BigNumber* MainNumber, BigNumber* Bignumber2){
	BigNumber Bignumber1;
	int size1=MainNumber->size;
	int size2=Bignumber2->size;
	int division,multiplication;

	BigNumCopy(&Bignumber1,MainNumber);
	BigNumReset(MainNumber);

	for(int i=0;i<size1;++i){

		for(int j=0;i<size2;++i){

			multiplication=Bignumber1.number[i]*Bignumber2->number[j];
			division=(multiplication)/10;
			multiplication=multiplication%10;
			MainNumber->number[i+j-1]+=multiplication;
			MainNumber->size=i+j-1;
			if (division>0){
				MainNumber->number[i+j]+=division;
				MainNumber->size=i+j;
			}
			BigNumDecimal (MainNumber,i+j-1);
		}
	}
	return;
}
void BigNumMultEscalar(BigNumber* MainNumber,int escalar){
	BigNumber Bignumber1;
	BigNumCopy(&Bignumber1,MainNumber);
	BigNumReset(MainNumber);

	int digit,reserve;
	int size=Bignumber1.size;

	for (int i=0;i<size;++i){
		digit=Bignumber1.number[i]*escalar;
		reserve=digit/10;
		digit=digit%10;
		MainNumber->number[i]+=digit;
		if (reserve>0){
			MainNumber->number[i+1]+=reserve;
			MainNumber->size=i+1;
		}
		BigNumDecimal (MainNumber,i);
	}
	return;
}
void BigNumDivisionEscalar(BigNumber* MainNumber,int escalar){
	BigNumber Bignumber1;
	BigNumCopy(&Bignumber1,MainNumber);
	BigNumReset(MainNumber);

	int digit,reserve;
	int size=Bignumber1.size;
	reserve=0;
	for (int i=size-1;i>=0;--i){
		Bignumber1.number[i]+=reserve;
		digit=Bignumber1.number[i]/escalar;
		reserve=Bignumber1.number[i]%escalar;
		reserve=reserve*10;
		MainNumber->number[i]=digit;
		
	}
	return;
}
int main(){

	BigNumber total;
	unsigned int n;
	unsigned int d;
	scanf("%u",&n);
	scanf("%u",&d);
	BigNumber N;
	BigNumConvert(&N,n);
	BigNumber D;
	BigNumConvert(&D,d);

	BigNumber N2;
	BigNumber N3;
	BigNumber D2;
	BigNumber D3;
	BigNumMultiplication(&D2,&D);
	BigNumMultiplication(&D,&D);
	BigNumMultiplication(&N2,&N);
	BigNumMultiplication(&N,&N);
	// 					n*(1+2*d*n+d2*n2) 	+ 	(n)*(1+n)*(-2*d-2*d2*n)/2 	+ 	(n)*(n+1)*(2*n+1)*d2/6;
	BigNumber sum1;
	BigNumber sum2;
	BigNumber sum3;
	/*			sum 1			*/
	//			n*(1+2*d*n+d2*n2)

	
	BigNumCopy(&sum1,&D);						//d
	BigNumCopy(&sum2,&N);						//n
	BigNumMultiplication(&sum1,&sum2);		//(d*n)
	BigNumMultEscalar(&sum1,2);				//2*d*n
	BigNumSumEscalar(&sum1,1);				//1+2*d*n
	BigNumCopy(&sum2,&D2);					// d2
	BigNumCopy(&sum3,&N2);					// n2
	BigNumMultiplication(&sum2,&sum3);		// (1+2*d*n)		//(d2*n2)
	BigNumSum(&sum1,&sum2);					// (1+2*d*n2	+	d2*n2)
	BigNumCopy(&sum3,&N);
	BigNumMultiplication(&sum1,&sum3);		//sum1;

	/*			sum 2			*/
	//			(n)*(1+n)*(-d-d2*n) 
	
	BigNumCopy(&sum2,&D);




	for(int i=total.size;i>=0;--i)
		printf("%c",total.number[i]);
	
	return 0;
}