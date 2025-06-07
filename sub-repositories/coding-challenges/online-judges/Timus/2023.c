#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,from,to,count;
	char name[8];
	to=0;
	count=0;
	scanf("%d",&n);
	while(n>0){
		--n;
		scanf("%s",&name);
		from=to;
		if(name[0]=='A'||name[0]=='P'||name[0]=='O'||name[0]=='R') 	to=0;
		else if(name[0]=='B'||name[0]=='M'||name[0]=='S') 			to=1;
		else														to=2;
		count+=abs(to-from);
	}
	printf("%d",count);
	return 0;
}