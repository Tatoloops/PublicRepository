#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,first,last;
	int temp[3];
	scanf("%d",&n);
	if (n%10==0){
		temp[0]=n/100000;
		temp[1]=(n-temp[0]*100000)/10000;
		temp[2]=(n-temp[0]*100000-temp[1]*10000)/1000;
		first=temp[0]+temp[1]+temp[2];
		//printf("%d %d %d %d \n",temp[0],temp[1],temp[2],first);
		last=n%1000;
		temp[0]=last/100;
		temp[1]=(last-temp[0]*100)/10;
		temp[2]=last%10;
		last=temp[0]+temp[1]+temp[2];
		//printf("%d %d %d %d \n",temp[0],temp[1],temp[2],last);
		if (first>last)
			printf("Yes");
		else
			printf("No");
	}
	else if(n%10==9){
		temp[0]=n/100000;
		temp[1]=(n-temp[0]*100000)/10000;
		temp[2]=(n-temp[0]*100000-temp[1]*10000)/1000;
		first=temp[0]+temp[1]+temp[2];
		last=n%1000;
		temp[0]=last/100;
		temp[1]=(last-temp[0]*100)/10;
		temp[2]=last%10;
		last=temp[0]+temp[1]+temp[2];
		if (first>last)
			printf("No");
		else
			printf("Yes");
	}
	else printf("Yes");
	return 0;
}