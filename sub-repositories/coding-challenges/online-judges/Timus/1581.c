#include <stdio.h>
#include <stdlib.h>
int main(){  //1581
	int n,a,b,c,i;
	scanf("%d",&n);
	b=1; //contador
	scanf("%d",&c); //previous number
	for(i=0;i<n-1;++i){
		scanf("%d",&a);
		if (a==c){
			++b;
		}
		else{
			printf("%d %d ",b,c);
			b=1;
			c=a;
		}
	}
	printf("%d %d",b,c);
	return 0;
}