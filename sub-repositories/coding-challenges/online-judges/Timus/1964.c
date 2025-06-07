#include <stdio.h>
int main(){
	int n,a1,a2,k;
	scanf("%d%d%d",&n,&k,&a1);
	while(k>1){
		scanf("%d",&a2);
		a1-=n;
		a1+=a2;
		if (a1&0x80000000){
			printf("0");
			return 0;
		}
		--k;
	}
	printf("%d",a1);
	return 0;
}