#include <stdio.h>

int main(){
	int PotRed,PotBlue,PotMix;
	int NeedRed,NeedBlue,NeedMix;
	scanf("%d %d %d",&PotRed,&PotBlue,&PotMix);
	scanf("%d %d %d",&NeedRed,&NeedBlue,&NeedMix);

	PotRed=PotRed-NeedRed;
	PotBlue=PotBlue-NeedBlue;

	if(PotRed>0){
		NeedMix-=PotRed;
	}
	else if(PotRed<0){
		PotMix+=PotRed;
	}
	if (PotMix<0){
		printf("There are no miracles in life");
	}
	else{
		if(PotBlue>0){
			NeedMix-=PotBlue;
		}
		else if(PotBlue<0){
			PotMix+=PotBlue;
		}
		if (PotMix <0){
		printf("There are no miracles in life");
		}
		else if (PotMix>=NeedMix){
			printf("It is a kind of magic");
		}
		else{
			printf("There are no miracles in life");
		}

	}
	return 0;
}