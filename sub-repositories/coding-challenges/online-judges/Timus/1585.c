#include <stdio.h>
#include <stdlib.h>
int main(){
	short int n,count_m,count_e,count_l; //e:emperor l:little m:macaroni  
	char penguin[17];
	count_l=0;
	count_e=0;
	count_m=0;
	scanf("%hi",&n);
	while(n>0){
		--n;
		scanf("%s",&penguin);
		scanf("%s",&penguin[9]);
		if (penguin[0]=='E') ++count_e;
		else if (penguin[0]=='L') ++count_l;
		else ++count_m;
	}
	if (count_m>count_l)
		if(count_m>count_e) printf("Macaroni Penguin");
		else printf("Emperor Penguin");
	else if(count_l>count_e) printf("Little Penguin");
		else printf("Emperor Penguin");
	return 0;
}