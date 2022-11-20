#include <stdlib.h>
#include <stdio.h>
int main () //1877. Bicycle Codes
	{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	if (a%2==0 || b%2)
		printf("yes");
	else
		printf("no");

	return 0;
	}