/*
	1008
*/
#include <string.h>
#include <stdio.h>
typedef struct{
	unsigned short color; //0 white - 1 black
	unsigned short read; //0 unread - 1 read
}Pixel;
typedef struct{
	unsigned short x;
	unsigned short y;
}PixelRead;

int main(){
	unsigned short temp1,temp2;
	unsigned char temp3[6];
	scanf("%hu %hu %s",&temp1,&temp2,temp3);
	Pixel Map[10][10];
	if (temp3[0]<60 && temp3[0]>47){	//first encoding to second
		unsigned short Lines;
		Lines=temp1;
		unsigned short Xcoor,Ycoor;
		
		for(unsigned short i=0;i<10;++i)
			for(unsigned short j=0;j<10;++j){
				Map[i][j].color=0;
				Map[i][j].read=0;
			}
		unsigned short Xstart,Ystart;
		Xstart=temp2;
		Ystart=temp3[0]-48;
		Map[Xstart-1][Ystart-1].color=1;

		for(unsigned short i=1;i<Lines;++i){
			scanf("%hu %hu",&Xcoor,&Ycoor);
			Map[Xcoor-1][Ycoor-1].color=1;
			if (Xcoor==Xstart && Ycoor < Ystart){
				Xstart=Xcoor;
				Ystart=Ycoor;
			}
			else if (Xcoor<Xstart){
				Xstart=Xcoor;
				Ystart=Ycoor;
			}
		}
		unsigned short ReadListTotal=1;
		unsigned short ReadListCurrent=0;
		unsigned short ReadListConfirm;

		PixelRead ReadList[Lines];
		ReadList[0].x=Xstart;
		ReadList[0].y=Ystart;
		Map[Xstart-1][Ystart-1].read=1;
		printf ("%hu %hu\n",Xstart,Ystart);
		int number=1;
		while (ReadListCurrent < ReadListTotal){
			Xcoor=ReadList[ReadListCurrent].x;
			Ycoor=ReadList[ReadListCurrent].y;

			if (Map[Xcoor][Ycoor-1].color==1 && Map[Xcoor][Ycoor-1].read==0){
				Map[Xcoor][Ycoor-1].read=1;
				printf("R");
				ReadList[ReadListTotal].x=Xcoor+1;
				ReadList[ReadListTotal].y=Ycoor;
				++ReadListTotal;
			}
			if (Map[Xcoor-1][Ycoor].color==1 && Map[Xcoor-1][Ycoor].read==0){
				Map[Xcoor-1][Ycoor].read=1;
				printf("T");
				ReadList[ReadListTotal].x=Xcoor;
				ReadList[ReadListTotal].y=Ycoor+1;
				++ReadListTotal;
			}
			if (Xcoor>=2 && Map[Xcoor-2][Ycoor-1].color==1 && Map[Xcoor-2][Ycoor-1].read==0){
				Map[Xcoor-2][Ycoor-1].read=1;
				printf("L");
				ReadList[ReadListTotal].x=Xcoor-1;
				ReadList[ReadListTotal].y=Ycoor;
				++ReadListTotal;

			}
			if (Ycoor>=2 && Map[Xcoor-1][Ycoor-2].color==1 && Map[Xcoor-1][Ycoor-2].read==0){
				Map[Xcoor-1][Ycoor-2].read=1;
				printf("B");
				ReadList[ReadListTotal].x=Xcoor;
				ReadList[ReadListTotal].y=Ycoor-1;
				++ReadListTotal;

			}
			++ReadListCurrent;
			if (ReadListCurrent==ReadListTotal)
				printf(".");
			else
				printf(",\n");
		}
	}


	else{//second encoding
		//initializing map variables on 0
		unsigned short 		PositionCurrentX=	temp1;
		unsigned short 		PositionCurrentY=	temp2;
		unsigned char 		CurrentPhrase[6];
		for(int tempcounter=0;tempcounter<6;tempcounter++){
			CurrentPhrase[tempcounter]=temp3[tempcounter];
			if (temp3[tempcounter]=='\0')
				tempcounter=6;
		}
		for(unsigned short i=0;i<10;++i)
			for(unsigned short j=0;j<10;++j){
				Map[i][j].color=0;
				Map[i][j].read=0;
			}
		//reading first line of the coded image
		PixelRead ReadList[100];
		int ReadListCurrent=0;
		int ReadListTotal=1;

		ReadList[0].x=PositionCurrentX;
		ReadList[0].y=PositionCurrentY;

		unsigned short end=',';

		do{
			PositionCurrentX=ReadList[ReadListCurrent].x;
			PositionCurrentY=ReadList[ReadListCurrent].y;

			Map[PositionCurrentX-1][PositionCurrentY-1].color=1;
			for(int tempcounter=0;tempcounter<5;++tempcounter){
				if (CurrentPhrase[tempcounter]=='R'){
					ReadList[ReadListTotal].x=PositionCurrentX+1;
					ReadList[ReadListTotal].y=PositionCurrentY;
					ReadListTotal++;
				}
				else if(CurrentPhrase[tempcounter]=='T'){
					ReadList[ReadListTotal].x=PositionCurrentX;
					ReadList[ReadListTotal].y=PositionCurrentY+1;
					ReadListTotal++;
				}
				else if(CurrentPhrase[tempcounter]=='L'){
					ReadList[ReadListTotal].x=PositionCurrentX-1;
					ReadList[ReadListTotal].y=PositionCurrentY;
					ReadListTotal++;
				}
				else if(CurrentPhrase[tempcounter]=='B'){
					ReadList[ReadListTotal].x=PositionCurrentX;
					ReadList[ReadListTotal].y=PositionCurrentY-1;
					ReadListTotal++;
				}
				else if(CurrentPhrase[tempcounter]==','){
					tempcounter=5;
					scanf("%s",CurrentPhrase);
					end=CurrentPhrase[0];
					ReadListCurrent++;
				}
				else{
					tempcounter=5;
					end='.';
				}
			}
		}while(end!= '.');
		PositionCurrentX=ReadList[ReadListCurrent].x;
		PositionCurrentY=ReadList[ReadListCurrent].y;

		Map[PositionCurrentX-1][PositionCurrentY-1].color=1;

			
		printf("%d\n",ReadListCurrent+1);
		for(int tempcountA=0;tempcountA<10;tempcountA++) 			//X
			for(int tempcountB=0;tempcountB<10;tempcountB++){		//Y
				if (Map[tempcountA][tempcountB].color==1)
					printf("%d %d\n",tempcountA+1,tempcountB+1);
			}

	}
	return 0;
}