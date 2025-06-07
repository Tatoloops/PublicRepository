#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,i,id,m;
	scanf("%d",&n);
	int id_holder[101][10000];
	int ids[101];
	for(i=0;i<101;++i)
		ids[i]=-1;
	for(i=0;i<n;++i){
		scanf("%d",&id);
		scanf("%d",&m);
		++ids[m];
		id_holder[m][ids[m]]=id;
	}
	for(i=100;i>=0;--i){
		m=0;
		while(ids[i]>=m){
			printf("%d %d\n",id_holder[i][m],i);
			++m;
		}
	}
	return 0;
}