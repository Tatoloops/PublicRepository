#include <stdio.h>
#include <stdlib.h>
int main(){ //2100 wededing dinner
	int n,count,name_length,i,j;
	scanf("%d",&n);
	count=200;
	char name[25];
	for(i=0;i<n;++i){
		scanf("%s",&name);
		count+=100;
		j=1;
		while(name[j]!='\0'){
			if(name[j]=='+'){
				count+=100;
				name[j]=0;
			}
			++j;
		}
	}
	if (count==1300)
		count=1400;
	printf("%d",count);
	return 0;

}