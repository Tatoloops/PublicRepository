#include <stdio.h>
#include <stdlib.h>
int main (){ // stone pile WRONG
	int n,i,j,k,s,copy,nocopy;
	scanf("%d",&n);
	int w[n];
	int v[120];
	for(i=0;i<n;++i)
		scanf("%d",&w[i]);
	for(i=0;i<n;++i) //ordenar de mayor a menor
		for(j=i+1;j<n;++j)
			if (w[i]<w[j]){
				k=w[i];
				w[i]=w[j];
				w[j]=k;
			}
	for(i=0;i<n;++i){
		
	}
	printf("%d ",k);
	return 0;
}