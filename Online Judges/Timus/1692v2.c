#include <stdio.h>
#include <math.h>
int main(){
	int colors;
	scanf("%d",&colors);
	float flags;
	flags=floor(0.5+sqrt(1+8*colors)/2);
	colors=flags-1;
	int i,j;
	int contador1=0;
	printf("%d\n",colors+1);


	for(i=0;i<flags;++i){
		printf("%d ",colors);
		for(j=0;j<flags-1-i;++j){
			++contador1;
			printf("%03d ",contador1);
		}
		
		for(j=0;j<i;++j){
			printf("%03d ",contador1-colors+i-j*(colors-i)-j*j+((j*j-3*j+2)/2)-1);
		}
		printf("\n");
	}


	return 0;
}