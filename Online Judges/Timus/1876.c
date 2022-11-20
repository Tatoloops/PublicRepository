#include <stdio.h>
#include <stdlib.h>
int main(){
	unsigned char a,b;
	scanf("%hhu",&a);
	a=a<<1;
	scanf("%hhu",&b);
	b=b<<1;
	if (a>b+1)
		printf("%hhu",a+39);
	else
		printf("%hhu",40+b);
	return 0;
}