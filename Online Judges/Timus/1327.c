#include <stdio.h>
#include <stdlib.h>
int main (){
	int a,b,days;
	scanf("%d %d",&a,&b);
	days=(b-a)>>1;
	if (a&1 || b&1) days+=1;
	printf("%d",days);
	return 0;
}