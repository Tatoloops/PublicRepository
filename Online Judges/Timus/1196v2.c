#include <stdio.h>
#include <stdlib.h>
int main(){ //1196
	int n,m,i,j,k,count,date,div,sub;
	scanf("%d",&n);
	int teacher[n];
	count=0;
	div=2;
	while(n>div)
		div=div<<1;
	div=div>>1;
	for(i=0;i<n;++i)
		scanf("%d",&teacher[i]);
	scanf("%d",&m);
	for(i=0;i<m;++i){
		scanf("%d",&date);
		j=1;
		for(sub=2;sub<div;sub=sub*2){
			if(date>=teacher[(n*j)/sub]) j=j*2+1;
			else  j=j*2-1;
		}
		if(date>=teacher[(n*j)/div]) j=j+1; //patch
		for(k=(n*(j-1))/div;k<(n*j)/div;++k)
			if (date==teacher[k]){
				++count;
				k=(n*j)/div; //exit the loop(break);
			}
	}
	printf("%d",count);
	return 0;
}