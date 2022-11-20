#include <stdio.h>
int main (){
	int amount,i,note;
	float total;
	scanf("%d",&amount);
	total=0;
	int result=0;
	for(i=0;i<amount;++i){
		scanf("%d",&note);
		if (note==3){
			result=-1;
			i=amount;
		}
		total+=note;
	}
	total=total/amount;

	if 		(result==-1)
		printf("None");
	else if (total==5)
		printf("Named");
	else if (total>=4.5)
		printf("High");
	else
		printf("Common");

	return 0;
}