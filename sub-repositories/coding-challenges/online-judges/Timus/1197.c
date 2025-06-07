#include <stdio.h>
#include <stdlib.h>
int main(){
	unsigned char n; //1 Byte - 8 bits (0 - 255)
	unsigned char position[3];
	scanf("%d",&n);
	while(n>0){
		--n;
		scanf("%s",&position);
		if (position[0]==97||position[0]==104) 		if(position[1]==49||position[1]==56) printf("2\n");
													else if(position[1]==50||position[1]==55) printf("3\n");
													else printf("4\n");
		else if (position[0]==98||position[0]==103)	if(position[1]==49||position[1]==56) printf("3\n");
													else if(position[1]==50||position[1]==55) printf("4\n");
													else printf("6\n");
		else 										if(position[1]==49||position[1]==56) printf("4\n");
													else if(position[1]==50||position[1]==55) printf("6\n");
													else printf("8\n");
	}
	return 0;
}