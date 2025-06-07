/*	Timus 1019	Line Painting


*/
#define LimitA=1
#define LimitZ=1000000000

typedef struct{
	int x1;
	int x2;
	}WhitePaint;

void PaintingWhite(
	short* 		BigID,
	int* 		BigSize,
	short* 		ArraySize,
	WhitePaint* Current,
	WhitePaint* Paint){

	//localize x1
	
	int n=*ArraySize;

	int objective=Current->x1;
	int AdaptPositionB=n;
	int AdaptPositionA=roof(n/2);
	int AdaptSize=roof(n/2);

	int found=0;
	
	int FoundPaintA;
	int FoundPaintAState;		//state 0-> before the white line 1:inside white line 2:Right after white line
	int FoundPaintB;
	int FoundPaintBState;

	while(found==0){

		if (objective	<	(Paint+AdaptPositionA-1)->x2){
			if(objective	>	(Paint+AdaptPositionA-1)->x1){	// FOUND right between x2 and x1
				found=1;
				FoundPaintA=AdaptPositionA-1;
				FoundPaintAState=1;
			}
			else if(objective	==	(Paint+AdaptPositionA-1)->x1){ //FOUND in the x1 point
				found=1;
				FoundPaintA=AdaptPositionA-1;
				FoundPaintAState=1;
			}
			else if (AdaptPositionA	!=	1 &&	objective	>	(Paint+AdaptPositionA-2)->x2){	//FOUND between x2-1 and x1
				found=1;
				FoundPaintA=AdaptPositionA-1;
				FoundPaintAState=0;

			}
			else {						//before	--continue
				AdaptSize=roof(AdaptSize/2);
				AdaptPositionB=AdaptPositionA;
				AdaptPositionA=AdaptPositionA-AdaptSize;
			}
		}
		else if (objective	==	(Paint+AdaptPositionA-1)->x2){	//FOUND in x2
			found=1;
			FoundPaintA=AdaptPositionA-1;
			FoundPaintAState=1;

		}
		else if(AdaptPositionA	!=	n &&	objective	<	(Paint+AdaptPositionA+0)->x1){	// FOUND right after x2 and x1 from next value
			found=1;
			FoundPaintA=AdaptPositionA-1;
			FoundPaintAState=2;
		}
		else{	//after -- continue
			AdaptSize=roof(AdaptSize/2);
			AdaptPositionB=AdaptPositionA;
			AdaptPositionA=AdaptPositionA+AdaptSize;
		} 


	}

	//localize x2
	objective=Current->x2;
	AdaptPositionB=n;
	AdaptPositionA=roof(n/2);
	AdaptSize=roof(n/2);

	found=0;


	while(found==0){

		if (objective	<	(Paint+AdaptPositionA-1)->x2){
			if(objective	>	(Paint+AdaptPositionA-1)->x1){	// FOUND right between x2 and x1
				found=1;
				FoundPaintB=AdaptPositionA-1;
				FoundPaintBState=1;
			}
			else if(objective	==	(Paint+AdaptPositionA-1)->x1){ //FOUND in the x1 point
				found=1;
				FoundPaintB=AdaptPositionA-1;
				FoundPaintBState=1;
			}
			else if (AdaptPositionA	!=	1 &&	objective	>	(Paint+AdaptPositionA-2)->x2){	//FOUND between x2-1 and x1
				found=1;
				FoundPaintB=AdaptPositionA-1;
				FoundPaintBState=0;

			}
			else {						//before	--continue
				AdaptSize=roof(AdaptSize/2);
				AdaptPositionB=AdaptPositionA;
				AdaptPositionA=AdaptPositionA-AdaptSize;
			}
		}
		else if (objective	==	(Paint+AdaptPositionA-1)->x2){	//FOUND in x2
			found=1;
			FoundPaintB=AdaptPositionA-1;
			FoundPaintBState=1;

		}
		else if(AdaptPositionA	!=	n &&	objective	<	(Paint+AdaptPositionA+0)->x1){	// FOUND right after x2 and x1 from next value
			found=1;
			FoundPaintB=AdaptPositionA-1;
			FoundPaintBState=2;
		}
		else{	//after -- continue
			AdaptSize=roof(AdaptSize/2);
			AdaptPositionB=AdaptPositionA;
			AdaptPositionA=AdaptPositionA+AdaptSize;
		} 
	}

	int PaintsDeleted;
	int FirstDeleted;
	int LastDeleted;

	if (FoundPaintAState==0){	//before
		FirstDeleted=FoundPaintA+1;
		(Paint+FoundPaintA)->x1=Current->x1;

	}
	else if (FoundPaintAState==1){	//current line
		FirstDeleted=FoundPaintA+1;
	}
	else{	//after
		FirstDeleted=FoundPaintA+2;
		(Paint+FoundPaintA+1)->x1=Current->x1;

	}

	if (FoundPaintBState==0){	//before
		LastDeleted=FoundPaintB-1;
	}
	else if (FoundPaintBState==1){	//current line
		LastDeleted=FoundPaintB-1;
	}
	else{	//after
		LastDeleted=FoundPaintB-1;

	}

	PaintsDeleted=LastDeleted-FirstDeleted+1;
	if(FoundPaintAState==1){
		if(FoundPaintBState==1){
			PaintsDeleted+=1;
			(Paint+FoundPaintA)->x2=(Paint+FoundPaintB)->x2;
		}
	}
	else if()
	for(int i=0;i<PaintsDeleted;++i){
		(Paint+FoundPaintA+i+1)->x1=(Paint+FoundPaintB+i+1)->x1;
		(Paint+FoundPaintA+i+1)->x2=(Paint+FoundPaintB+i+1)->x2;
	}
	
	//Paint already located


	return;
}

int main(){
	short lines,BiggestID,ArraySize;
	int posx1,posx2,BiggestSize;
	char color;
	scanf("%hd",&lines);
	WhitePaint Paint[5000]; //array with all the white paintings
	WhitePaint Current;

	//Start point

	Paint[0].x1=LimitA; Paint[0].x2=LimitZ;
	ArraySize=1;
	BiggestID=0;
	BiggestSize=Paint[0].x2-Paint[0].x1;
	//end of start point

	//main algorithm
	for(short i=0;i<lines;++i){
		scanf("%d%d%c",&Current.x1,&Current.x2,&color);
		if (color=="w")	//if the paint is white
			PaintingWhite(BiggestID,BiggestSize,ArraySize,Current,Paint);
		else			//if the paint is black
			PaintingBlack(BiggestID,BiggestSize,ArraySize,Current,Paint);
	}


	//printing results
	printf("%d %d",Paint[BiggestID].x1,Paint[BiggestID].x2);
	return 0;
}