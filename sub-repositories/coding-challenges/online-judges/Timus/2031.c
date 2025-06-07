#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if (n==1) printf("11");
	else if(n==2) printf("11 01");
	else if(n==3) printf("11 01 60");
	else if(n==4) printf("11 01 60 80");
	else printf("Glupenky Pierre");
	return 0;
}