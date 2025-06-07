#include <stdio.h>
#include <math.h>
int main(){
	int colors;
	scanf("%d",&colors);
	float flags;
	flags=floor(0.5+sqrt(1+8*colors)/2);
	colors=flags-1;
	int i,j,k;
	int contador1=0;
	int contador2=0;
	int resta;
	printf("%d\n",colors+1);


	for(i=0;i<flags;++i){
		printf("%d ",colors);
		for(j=0;j<colors-i;++j){
			++contador1;
			printf("%d ",contador1);
		}
		contador2=contador1-colors+i;
		resta=colors-3+j;
		for(j=0;j<i;++j){
			printf("%d ",contador2);
			contador2-=resta;
			++resta;
		}
		printf("\n");
	}


	return 0;
}