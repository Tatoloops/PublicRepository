#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main(){ //1209
	int n,number,root;
	double a;
	scanf("%d",&n);
	while(n>0){
		--n;
		scanf("%d",&number);
		a= (sqrt(8)*sqrt(number-(0.875) ) +1) /2;
		//root=(a*a-a+2)/2;
		root=floor(a);
		number=ceil(a);
		printf("a: %lf floor: %d ceil: %d ",a,root,number);
		if (floor(a)==a)
			printf("1 ");
		else
			printf("0 ");
		printf("\n");
		}
}