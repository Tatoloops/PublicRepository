#include <stdio.h>

struct Counter{
	int suma;
	int index;
};

int minCostClimbingStairs(int* cost, int costSize) {
	int minCost=0;

	// Initialize counters
	struct Counter c1,c2,c3;
	c1.suma=0;
	c1.index=0;

	c2.suma=0;
	c2.index=0;

	c3.suma=0;
	c3.index=1;


	//marvelous loop
	for (int i=0;i<costSize;i++){

		c1.suma+=cost[i];
		

		if (c2.index==i){
			c2.suma+=cost[i];
			if (c1.suma >c2.suma){
				c1.suma=c2.suma;
			}
			else{
				c2.suma=c1.suma;
			}
			c2.index+=2;
		}
		if (c3.index==i){
			c3.suma+=cost[i];
			if (c1.suma >c3.suma){
				c1.suma=c3.suma;
			}
			else{
				c3.suma=c1.suma;
			}
			c3.index+=2;
		}

		c1.index+=1;
	}

	//retrieve minCost
	if (c2.suma<c1.suma){
		c1.suma=c2.suma;
	}
	if (c3.suma<c1.suma){
		c1.suma=c3.suma;
	}
	minCost=c1.suma;

	//export min cost
	return minCost;
}


int main(){

	printf("min-cost-Stairs\n");

	int cost[10];
	cost[0]=1;
	cost[1]=100;
	cost[2]=1;
	cost[3]=1;
	cost[4]=1;
	cost[5]=100;
	cost[6]=1;
	cost[7]=1;
	cost[8]=100;
	cost[9]=1;


	printf("min cost > %d\n",minCostClimbingStairs(cost,10));
	


	return 0;
}