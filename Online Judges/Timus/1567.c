#include <stdio.h>
#include <stdlib.h>
int main(){
	int i,count;
	char sum;
	unsigned char slogan[1001];
	i=-1;
	count=0;
	do{
		++i;
		scanf("%c",&slogan[i]);
		if (slogan[i]==32) ++count;
		else{
			sum=(slogan[i]-1)%3 +1;
			count+=sum;
		}
	}
	while(slogan[i]>31);
	printf("%d",count-1);
	return 0;
}