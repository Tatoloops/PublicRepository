#include <stdio.h>
int main(){
	int n;
	unsigned char r;
	scanf("%d",&n);
	r=n%4;
	if (r==1)
		if(n%5==0)printf("2");
		else printf("1");
	else if(r==2) printf("1");
	else if (r==3) printf("2");
	else printf("0");
}