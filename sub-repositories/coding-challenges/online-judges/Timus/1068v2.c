#include <stdio.h>
#include <stdlib.h>
int main(){ //Timus 1068. Sum
	int n;
	scanf("%d",&n);
	if (n>0)
		if (n%2)
			n=(n+2)*((n-1)/2)+1;
		else
			n=(n+2)*((n-2)/2)+(n/2+1)+1;
	else
		if(n%2)
			n=(n-2)*-((n+1)/2);
		else
			n=(n-2)*-((n+2)/2)+(n/2-1);
	printf("%d",n);
	return 0;
}