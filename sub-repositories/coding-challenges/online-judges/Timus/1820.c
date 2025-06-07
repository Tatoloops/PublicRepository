#include <stdlib.h>
#include <stdio.h>
int main () //1820. Ural Steaks
	{
	int n,k,a;
	scanf("%d",&n);
	scanf("%d",&k);
	if (n>k){
		n=n*2;
		a=n%k;
		n=n/k;
		if (a)
			printf("%d",n+1);
		else
			printf("%d",n);
	}
	else{
		printf("%d",2);
	}
	return 0;
	}