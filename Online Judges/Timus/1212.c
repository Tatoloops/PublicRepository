#include <stdio.h>
typedef struct{
unsigned short x; //position
unsigned short y;
unsigned char length; // 2 3 or 4
}Rship_block;
typedef struct{
unsigned short x; //position
unsigned short y;
unsigned char length; // 2 3 or 4
}Bship_block;

void createblocksV(Rship_block*r_blocks,Bship_block*b_blocks,unsigned short*c_block,
	unsigned short x, 
	unsigned short y, unsigned short length,
	unsigned short FieldHeight, unsigned short FieldWidth){ //vertical ship

	unsigned char i,j;
	unsigned short adjustedX=x-1;
	unsigned short adjustedY=y-1;
	unsigned short adjustedwidth=3;
	unsigned short adjustedheight=length+2;
	unsigned short c_block=0;
	if (x==1){
		adjustedX=x;
		adjustedwidth=length+1;
	}
	else if(x==FieldWidth+1-length)
		adjustedwidth=length+1;
	if (y==1){
		adjustedY=y;
		adjustedheight=2;
	}
	else if (y==FieldHeight)
		adjustedheight=2;
	for(j=0;j<adjustedheight;++j){ //3 or less to the right
		r_blocks+*(c_block)->x=adjustedX;
		r_blocks+*(c_block)->y=adjustedY+j;
		r_blocks+*(c_block)->length=adjustedwidth;
		++*c_block;
	}
	for(j=0;j<adjustedwidth;++j){ //to the bottom
		b_blocks+*(c_block+1)->x=adjustedX+j;
		b_blocks+*(c_block+1)->y=adjustedY;
		b_blocks+*(c_block+1)->length=adjustedheight;
		++*(c_block+1);
	}
}
void createblocksH(Rship_block*r_blocks,Bship_block*b_blocks,unsigned short*c_block,
	unsigned short x, 
	unsigned short y, unsigned short length,
	unsigned short FieldHeight, unsigned short FieldWidth){

	unsigned char i,j;
	unsigned short adjustedX=x-1;
	unsigned short adjustedY=y-1;
	unsigned short adjustedwidth=3;
	unsigned short adjustedheight=length+2;
	if (x==1){
		adjustedX=x;
		adjustedwidth=2;
	}
	else if(x==FieldWidth)
		adjustedwidth=2;
	if (y==1){
		adjustedY=y;
		adjustedheight=length+1;
	}
	else if (y==FieldHeight+1-length)
		adjustedheight=length+1;
	for(j=0;j<adjustedheight;++j){ //vertical blocks -> right
		r_blocks+*(c_block)->x=adjustedX;
		r_blocks+*(c_block)->y=adjustedY+j;
		r_blocks+*(c_block)->length=adjustedwidth;
		++*c_block;
	}
	for(j=0;j<adjustedwidth;++j){ //horizontal blocks -> down
		b_blocks+*(c_block+1)->x=adjustedX+j;
		b_blocks+*(c_block+1)->y=adjustedY;
		b_blocks+*(c_block+1)->length=adjustedheight;
		++*(c_block+1);
	}
}

int main(){
	unsigned short H,W,x,y;
	unsigned char n,o,l;
	scanf("%hu",&H);
	scanf("%hu",&W);
	scanf("%hhu",n);
	Rship_block Rblocks[6*n];
	Bship_block Bblock[6*n];
	unsigned short colliding[10][2]; //0:position 1:legth
	/*block id / x,y,length, orientation: 0=down, 1=right (were the legth generates more blocks)*/
	unsigned short c_block[2]=0; //0:counts vertical->right blocks 1:counts horizontal/bottom block
	for (i=0;i<n;++i){
		scanf("%hu",&x);
		scanf("%hu",&y);
		scanf("%hhu",&l);
		scanf(" %c",&o);
		if(o=='V')
			createblocksV(Rblocks,Bblocks,c_block,x,y,l,H,W);
		else
			createblocksH(Rblocks,Bblocks,c_block,x,y,l,H,W);
	}
	//blocks[block_ID][0,1,2:x,y,length,orientation]
	//Analyzing all obstructed bship_block for your vertical ship
	for(i=0;i<c_block[1];++i){
		x=(Bblocks+i)->x;
		for(j=i+1;j<c_block[1];++j){


		}
	}
	return 0;
}