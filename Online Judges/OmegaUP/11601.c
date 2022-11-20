#include <stdio.h>

int main(){
	int N;
	int M,current;
	scanf("%d",&N);
	scanf("%d",&M);
	int pelota[M];
	for(int i=0;i<M;++i){
		pelota[i]=0;
	}
	for(int i=0;i<N;++i){
		scanf("%d",&current);
		pelota[current-1]++;
	}
	for(int i=0;i<M;++i){
		printf("%d: %d\n",i+1,pelota[i]);
	}
	return 0;
}