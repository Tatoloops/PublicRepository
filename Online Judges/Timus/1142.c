#include <stdio.h>
#include <stdlib.h>
int main(){  //1142
	int N,i,j,k,a;
	scanf("%d",&N);
	int w[11];
	w[0]=1;
	do{
		for(i=0;i<N-1;++i){
			k=0;
			for(j=0;j<=i;++j){
				a=(j+2)*w[j];
				w[j]=(j+1)*w[j]+k;
				k=a;
			}
			w[i+1]=a;
		}
		k=0; 
		for(i=0;i<N;++i)
			k+=w[i];
		printf("%d\n",k);
		scanf("%d",&N);
	} 
	while(N!=-1);
	return 0;
}