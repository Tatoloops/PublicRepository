#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,m;
	scanf("%d",&m);
	scanf("%d",&n);
	if ((m*n)%2==0) printf("[:=[first]");
	else printf("[second]=:]");
	return 0;
}