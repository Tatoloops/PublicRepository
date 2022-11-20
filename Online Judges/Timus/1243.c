#include <stdio.h>
#include <stdlib.h>
int main(){
	int i,final_num;
	char digit,vuelta,count;
	char number[53];
	char mark[53];
	char size;
	scanf("%s",mark);
	count=-1; //number of things after a 7 multiply
	do{
		size=0;
		do{
			number[size]=mark[size];
			digit=mark[size];
			++size;
		}
		while(digit!='\0');
		size-=2;
		vuelta=0;
		i=0;
		if (count>-1){
			number[size]-=count+1;
			if (number[size]<48){
				number[size]+=10;
				vuelta+=1;
			}
			while(vuelta>0){
				++i;
				number[size-i]-=vuelta;
				vuelta=0;
				if (number[size-i]<48){
					number[size-i]+=10;
					vuelta+=1;
				}
			}
		}
		while(size>3){
			for(i=0;i<=size;++i)
			digit=number[size];
			--size;
			digit=(digit-48)<<1;
			vuelta=0;
			while(digit>0){
				--number[size];
				--digit;
				if (number[size]<48){
					number[size]+=10;
					vuelta+=1;
				}
			}
			while(vuelta>0){
				++digit; 						//digit is not used to count 
				number[size-digit]-=vuelta;
				vuelta=0;
				if (number[size-digit]<48){
					number[size-digit]+=10;
					vuelta+=1;
				}
			}
		}
		final_num=0;
		for(vuelta=0;vuelta<=size;++vuelta){
			final_num=final_num*10;
			final_num+=number[vuelta]-48;
		}
	++count;
	}
	while(final_num%7!=0);
	printf("%hhu",count);
	return 0;
}