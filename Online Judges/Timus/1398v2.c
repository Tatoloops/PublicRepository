#include <stdio.h>

int main(){
	char BishopPosition[3];
	char PawnPosition[3];
	scanf("%s",BishopPosition);
	scanf("%s",PawnPosition);
	char BishopData;
	char PawnData;
	BishopPosition[0]=BishopPosition[0]-'a'+1;
	PawnPosition[0]=PawnPosition[0]-'a'+1;
	BishopPosition[1]=BishopPosition[1]-'0';
	PawnPosition[1]=PawnPosition[1]-'0';

	//printf ("Bishop pos: %hhi,%hhi  |  Pawnpost: %hhi,%hhi\n",BishopPosition[0],BishopPosition[1],PawnPosition[0],PawnPosition[1]);
	int PawnDiN=		PawnPosition[0]		+	PawnPosition[1];	//Pawn Diagonal negative \*
	int PawnDiP=		9-PawnPosition[0]	+	PawnPosition[1];	//Pawn Diagonal Positive /
	int BishopDiN=		BishopPosition[0]	+	BishopPosition[1];
	int BishopDiP=		9-BishopPosition[0]	+	BishopPosition[1];

	//printf("pawnDiN: %d ,pawnDiP: %d   |   BDiN: %d, BDiP: %d \n",PawnDiN,PawnDiP,BishopDiN,BishopDiP);

	if (BishopDiN & 0x1){//identify the colors
		BishopData=BishopData|0x1;
	}
	else{
		BishopData=~((~BishopData)|0x1);
	}

	if(PawnDiN & 0x1){
		PawnData=PawnData|0x1;
	}
	else{
		PawnData=~((~PawnData)|0x1);
	}

	//printf("\nBishopsquarecolor: %hhi PawnSquarecolor: %hhi\n",BishopData&0x1,PawnData&0x1);

	// ---- Calculating who wins ----

	// only position from 3rd row where pawn can draw
	if (PawnPosition[1]==3){
		if 		(PawnPosition[0]==8 && BishopPosition[0]==7 && BishopPosition[1]==1){
			printf("DRAW");
		}
		else if (PawnPosition[0]==1 && BishopPosition[0]==2 && BishopPosition[1]==1){
			printf("DRAW");
		}
		else{
			printf("WHITE");
		}
	}
	

	// 1. If black pawn is too far away from crowning, white bishop wins.
	else if(PawnPosition[1]>2){
		//printf("too far away for pawn to promote\n");
		printf("WHITE");
	}

	// 2. Two possible positions to draw
	else if(PawnPosition[0]==2 && BishopPosition[0]==1 && BishopPosition[1]==2){
			printf("DRAW");
	}
	else if(PawnPosition[0]==7 && BishopPosition[0]==8 && BishopPosition[1]==2){
			printf("DRAW");
	}
	

	//if they are on different color squares 
	else if((BishopData & 0x1) != (PawnData & 0x1)){
			printf("WHITE");
	} 
	
	//if they are on same diagonal -> bishop inmediately captures black pawn
	else if(PawnDiN==BishopDiN || PawnDiP==BishopDiP){ 
		printf("WHITE");
	} 
	else{
		printf("BLACK");
	}
	return 0;
}