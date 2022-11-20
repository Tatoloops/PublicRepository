#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,m,i,vote;
	scanf("%d",&n);
	float candidate[n];
	for(i=0;i<n;++i)
		candidate[i]=0;
	scanf("%d",&m);
	for(i=0;i<m;++i){
		scanf("%d",&vote);
		++candidate[vote-1];
	}
	for(i=0;i<n;++i){
		printf("%.2f%c\n",candidate[i]*100/m,37);
	}
	return 0;
}