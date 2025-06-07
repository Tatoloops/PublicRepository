#include <stdio.h>
#include <stdlib.h>
int main(){ //Timus 1880 Psych Up's Eigenvalues
	int n,i,c,w,k;
	scanf("%d",&n);
	int v[n]; //the walls
	for(i=0;i<n;++i)
		scanf("%d",&v[i]);
	w=0;
	for(i=1;i<n-1;++i){
		c=v[i-1]+v[i]+v[i+1];
		if (c>w){
			w=c;
			k=i+1;
		}
	}
	printf("%d %d",w,k);
	return 0;
}