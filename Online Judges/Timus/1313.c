#include <stdio.h>
#include <stdlib.h>
int main(){ //Timus 1313. Some Words about Sport
	int n,i,j,c;
	scanf("%d",&n);
	int v[n][n];
	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
		scanf("%d",&v[j][i]);
	for(c=0;c<2*n-1;++c)
		if (c<n)
			for(i=c;i>=0;--i)
				printf("%d ",v[c-i][i]);
		else
			for(i=0;i<2*n-1-c;++i)
				printf("%d ",v[c-n+i+1][n-1-i]);
	return 0;
}