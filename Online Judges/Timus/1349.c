#include <stdio.h>
int main(void){
	char n;
	scanf("%hhi",&n);
	if (n==2)
		printf("3 4 5");
	else if (n==1)
		printf("1 2 3");
	else
		printf("-1");
	return 0;
}