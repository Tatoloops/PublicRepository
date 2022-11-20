#include <stdio.h>
#include <stdlib.h>
int main() { //1209 v0 * TLE *
	int n,i,c;
	scanf("%d",&n);
	int v[n];
	for(i=0;i<n;++i)
		scanf("%d",&v[i]);
	for(i=0;i<n;++i){
		c=1;
		while(v[i]>1){
			v[i]-=c;
			++c;
		}
	}
	for(i=0;i<n;++i)
		if(v[i]==1)
			printf("1 ");
		else
			printf("0 ");
	return 0;
	}