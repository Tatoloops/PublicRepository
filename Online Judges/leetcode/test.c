// c standard library
#include <stdio.h>
#include <math.h>

// Problems
#include "fibonacci-number.c"
//#include "n-th-tribonacci-number.c"

int main(){
	// int n;
	// scanf("%d",&n);
	// printf("result: %d\n",fib(n));
	printf("fibonacci-number\n");
	for (int i=0;i<=37;i++){
		printf("%d -> %d\n",i,fibLoop(i));
	}


	return 0;
}