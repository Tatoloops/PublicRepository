#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	int id[n];
	unsigned char m[n];
	for(i=0;i<n;++i){
		scanf("%d",&id[i]);
		scanf("%u",&m[i]);
	}
	for(j=100;j>=0;--j)
		for(i=0;i<n;++i){
			if(j==m[i])
				printf("%d %u\n",id[i],m[i]);
	}
	return 0;
}