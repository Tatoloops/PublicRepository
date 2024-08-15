// c standard library
#include <stdio.h>
#include <math.h>


// Problems
#include "fibonacci-number.c"

int main(){
	// int n;
	// scanf("%d",&n);
	// printf("result: %d\n",fib(n));
	printf("fibonacci-number\n");
	for (int i=0;i<=45;i++){
		printf("%d -> %d\n",i,fib(i));
	}


	return 0;
}