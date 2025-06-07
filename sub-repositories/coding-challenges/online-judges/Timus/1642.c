/*
Timus 1642 1D Maze
*/

#include <stdio.h>

int main (){

	int ObstacleAmount, Exit;

	scanf("%d %d",&ObstacleAmount, &Exit);

	int Obstacle[ObstacleAmount];
	int ObstacleMinorLeft=-9999;
	int ObstacleMinorRight=9999;
	printf("asdasd");

	for (int i=0;i<ObstacleAmount;i++){
		scanf("%d",Obstacle[i]);
		printf("aaagasgashas");
		if (Obstacle[i]<0){
			if (Obstacle[i]>ObstacleMinorLeft)
				ObstacleMinorLeft=Obstacle[i];
		}
		else {
			if (Obstacle[i]<ObstacleMinorRight)
				ObstacleMinorRight=Obstacle[i];
		}
	}
	if (Exit>0){
		if (Exit >ObstacleMinorRight)
			printf("Impossible");
	}
	else{
		if (Exit <ObstacleMinorLeft)
			printf("Impossible");		
	}

	if (Exit>0){
		printf("%d",Exit);
		printf("%d",Exit-ObstacleMinorLeft*2); //right
	}
	else{
		printf("%d",-Exit);
		printf("%d",ObstacleMinorLeft*2-Exit); //right	
	}
	printf("hola feo");
	return 0;
}