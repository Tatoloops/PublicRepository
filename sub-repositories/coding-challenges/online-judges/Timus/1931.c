#include <stdio.h>
int main(){
	int n,BestPos,BestCount,CurrentPos,CurrentCount,CurrentValue,NewValue,i;
	scanf("%d",&n);
	scanf("%d",&CurrentValue);
	BestPos=1;
	BestCount=0;
	CurrentPos=1;
	CurrentCount=0;
	for(i=1;i<n;++i){
		scanf("%d",&NewValue);
		++CurrentCount;
		if(NewValue<CurrentValue){
			if(CurrentCount>BestCount){
				BestCount=CurrentCount;
				BestPos=CurrentPos;
			}
			CurrentCount=1;
			CurrentPos=i+1;
			CurrentValue=NewValue;
		}
	}
	if (CurrentCount>BestCount)
		printf("%d",CurrentPos);
	else
		printf("%d",BestPos);
	return 0;
}