#include <stdio.h>
int operation(int number, int exponent, int div){
	int i;
	int newnum=number;
	for(i=1;i<exponent;++i){
		newnum*=number;
		newnum=newnum%div;
	}
	return newnum;
}
int main(){
	int i,n,m,y,x,numb;
	scanf("%d",&n); // 1 - 998
	scanf("%d",&m); // 2 - 998
	scanf("%d",&y); // 1 - 998
	x=0;
	for(i=1;i<m;++i){
		numb=operation(i,n,m);
		if(numb==y){
			x=1;
			printf("%d ",i);
		}
	}
	if (x==0)
		printf("-1");
	return 0;
}