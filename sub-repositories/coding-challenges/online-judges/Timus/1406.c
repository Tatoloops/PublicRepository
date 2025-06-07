#include <stdio.h>
//1406

int main(){
	char serial[2001];
	char end;		//	.	.	.	.	.	temporal variable, character used.
	int size=0;	//	.	.	.	.	.	number of digits	
	scanf("%s",serial);
	do{
		end=serial[size];
		serial[size]=serial[size]-48;
		++size;
	}while(end!='\0');
	size--;

		/*			PART A			*/
	//adding digits to the sum
	int sum=0;
	short i=1;
	do{
		end=serial[size-i];
		if(end!=0){
			sum=end;
			serial[size-i]=0;
		}
		++i;
	}while(end==0 && i<=size);

	if (i>size){
		printf("-1");
	}
	else{
			/*			PART B			*/
		for(short j=i;j<=size;++j){
			if(serial[size-j]==9){
				if(size==j){
					size=-1;
				}
				serial[size-j]=0;
				sum+=9;
			}
			else{
				serial[size-j]++;
				sum--;
				j=size+1;	//leave the loop
			}
		}
		if(size<0){
			printf("-1");
		}
		else{
			/*			PART C			*/
			//generating new number and calculations
			short nines=sum/9;	//number of nines added to the product
			short residual=sum%9;	//number added after the nines
			for(i=0;i<nines;++i){
				serial[size-i-1]=9;
			}
			/*			PART C			*/
			// printing the results
			serial[size-i-1]=residual;
			for(i=0;i<size;++i){
				end=serial[i];
				printf("%c",end+48);
			}
		}
		
	}

	
	return 0;
}