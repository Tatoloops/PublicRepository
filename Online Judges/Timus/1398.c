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

	//printf ("Bishop pos: %hhi,%hhi Pawnpost: %hhi,%hhi\n",BishopPosition[0],BishopPosition[1],PawnPosition[0],PawnPosition[1]);
	short PawnDiN=		PawnPosition[0]		+	PawnPosition[1];	//Pawn Diagonal negative \*
	short PawnDiP=		9-PawnPosition[0]	+	PawnPosition[1];	//Pawn Diagonal Positive /
	short BishopDiN=	BishopPosition[0]	+	BishopPosition[1];
	short BishopDiP=	9-BishopPosition[0]	+	BishopPosition[1];

	//printf("pawndin%hi,pawndip%hi,Bdin%hi,Bdip%hi\n",PawnDiN,PawnDiP,BishopDiN,BishopDiP);

	if (BishopDiN & 0x1){//identify the colors
		BishopData=BishopData|0x1;
	}
	else
		BishopData=~((~BishopData)|0x1);

	if(PawnDiN & 0x1){
		PawnData=PawnData|0x1;
	}
	else
		PawnData=~((~PawnData)|0x1);

	//printf("\nBishopsquarecolor: %hhi PawnSquarecolor: %hhi\n",BishopData&0x1,PawnData&0x1);
	if(PawnPosition[1]>2)
		printf("WHITE");
	else if(PawnPosition[0]==2 && BishopPosition[0]==1 && BishopPosition[1]==2){
			printf("DRAW");
	}
	else if(PawnPosition[0]==7 && BishopPosition[0]==8 && BishopPosition[1]==2){
			printf("DRAW");
	}
	else if((BishopData & 0x1) != (PawnData & 0x1)) //if they are on different color squares
		printf("WHITE");
	else if(PawnDiN==BishopDiN || PawnDiP==BishopDiP) //if they are on same diagonal
		printf("WHITE");
	else
		printf("BLACK");
	return 0;
}