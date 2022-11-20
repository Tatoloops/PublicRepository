#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,inicial,i,j,num,add;
	scanf("%d",&n);
	inicial=1+((n*n-n)/2);
	for(i=0;i<n;++i){
		num=inicial;
		add=n-i;
		for(j=0;j<n;++j){
			printf("%d ",num);
			if (add==n)
				--add;
			if (num>1+((n*n-n)/2)+(n-1)){ //left  bottom side
				num-=add;
				++add;
			}
			else {
				num-=add;
				--add;
			}
		}
		inicial+=(n-i);
		printf("\n");
	}
	return 0;
}