#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){ //1209
	int n,i,r,number;
	double a;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%lf",&a);
		a=sqrt(a-0.875)*sqrt(8);
		number=a;
		if (number==a)
			printf("0 ");
		else
			printf("1 ");
	}
	return 0;
}