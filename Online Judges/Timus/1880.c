#include <stdio.h>
#include <stdlib.h>
int main(){ //Timus 1880 Psych Up's Eigenvalues
	int a,b,x,i,j,c;
	scanf("%d",&a);
	int v[a],w[a];
	c=0;
	for(i=0;i<a;++i)
		scanf("%d",&v[i]);
	scanf("%d",&b);
	for(i=0;i<b;++i){
		scanf("%d",&x);
		for(j=0;j<a;++j)
			if(x==v[j]){
				w[c]=x;
				++c;
			}
	}
	a=0;
	scanf("%d",&b);
	for(i=0;i<b;++i){
		scanf("%d",&x);
		for(j=0;j<c;++j)
			if(x==w[j])
				++a;
	}
	printf("%d",a);
	return 0;
}