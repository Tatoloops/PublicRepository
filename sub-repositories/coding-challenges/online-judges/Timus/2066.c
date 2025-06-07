#include <stdio.h>
#include <stdlib.h>
int main(){ //**** needs to be fixed
	int a,b,c;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	if (b!=0)
		if (b==1)
			printf("%d",a-b-c);
		else
			printf("%d",a-b*c);
	else
		printf("%d",-c);
	return 0;
}