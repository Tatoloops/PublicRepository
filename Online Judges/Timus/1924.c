#include <stdio.h>
#include <stdlib.h>
int main(){
	int N;
	scanf("%d",&N);
	N=N%4;
	if (N==1 || N==2) //even
		printf("grimy");
	else
		printf("black");
	return 0;
}