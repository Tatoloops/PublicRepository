#include <stdio.h>
#include <stdlib.h>
int main(){ //Timus 1991. The battle near the swamp
	int n,k,i,b,d; // n: number of trucks/sections - k:number of droids of each section
	scanf("%d",&n);
	scanf("%d",&k);
	int v[n];
	b=0;
	d=0;
	for(i=0;i<n;++i)
		scanf("%d",&v[i]);
	for(i=0;i<n;++i)
		if(k>v[i]) // more droids than bombs
			d+=k-v[i];
		else
			b+=v[i]-k;
	printf("%d %d",b, d);
	return 0;
}