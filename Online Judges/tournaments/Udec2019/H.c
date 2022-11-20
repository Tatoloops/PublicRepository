#include <stdio.h>
int main(){ //udec torunament
	unsigned int n,d,value;
	scanf("%u",&n);
	scanf("%u",&d);
	printf("%u",n+2*(n-1)*d+(n-1)*(n-1)*d*d);
	return 0;
}