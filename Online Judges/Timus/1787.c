#include <stdio.h>
#include <stdlib.h>
int main(){ // Timus 787. Turn for MEGA
	int c,m,t,i;
	scanf("%d",&c);
	scanf("%d",&m);
	int n[m];
	for(i=0;i<m;++i)
		scanf("%d",&n[i]);
	t=0;
	for(i=0;i<m;++i){
		t+=n[i];
		t-=c;
		if (t<0)
			t=0;
	}
	printf("%d",t);
	return 0;
}