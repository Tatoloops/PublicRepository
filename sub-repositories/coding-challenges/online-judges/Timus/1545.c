#include <stdio.h>
int main(){
	int total;
	scanf("%d",&total);
	int i;
	char hieroglyph[total][2];
	for (i=0;i<total;++i){
		scanf("%s",&hieroglyph[i][0]);
	}

	char letter;
	scanf("%s",&letter);
	
	for(i=0;i<total;++i){
		printf("%c",hieroglyph[i][0]);
		printf("%c",hieroglyph[i][1]);
		printf("\n");
	}

	return 0;
}