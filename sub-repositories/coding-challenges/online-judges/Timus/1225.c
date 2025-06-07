#include <stdio.h>
#include <stdlib.h>
int main(){
	int N,i;
	long long int count,a,b;
	a=2;
	b=2;
	count=2;
	scanf("%d",&N);
	for(i=3;i<=N;++i){
		count=a+b;
		a=b;
		b=count;
	}
	printf("%lli",count);
	return 0;
}