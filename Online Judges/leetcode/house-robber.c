#include <stdio.h>


struct Patron{
	int index;
	int roboTotal;
};


int Funcion(int* nums){

	int* bigN;
	int maxIndice;
	for (int i = 0; i < sizeof(nums)-1; i++){
		if (nums[i] <= nums[i+1]){
			maxIndice = i;
		}
	}

	printf("El maximo numero es: %d \n",nums[maxIndice]);

	return 0;
}

int rob(int* nums, int numsSize) {   
	struct Patron patron[5];

	//inicializar 
	for (int i =0;i<5;i++){
		patron[i].index=0;
		patron[i].roboTotal=0;
	}

	patron[1].index=1;
	patron[3].index=1;
	patron[4].index=2;



	for(int i=0;i<numsSize;i++){
		int maximo=0;
		for (int j=0;j<5;j++){
			
			if (patron[j].index==i){
				patron[j].roboTotal+=nums[i];
				if (patron[j].roboTotal>maximo){
					maximo=patron[j].roboTotal;
				}
			}

		}
		for (int j=0;j<5;j++){
			
			if (patron[j].index==i && patron[j].roboTotal < maximo){
				patron[j].roboTotal=maximo;
			}

			if (patron[j].index==i ){
				if (j==0 || j==1){
					patron[j].index+=2;
				}	
				else{
					patron[j].index+=3;
				}
			} 

		}
		printf("El maximo robo hasta el punto %d es: %d \n",i,maximo);

	}



	int maximo=0;
	for (int j=0;j<5;j++){
		if (patron[j].roboTotal>maximo){
			maximo=patron[j].roboTotal;
		}

	}

    return maximo;
}



int main(){
	int casas[4];

	casas[0]=1;
	casas[1]=2;
	casas[2]=3;
	casas[3]=1;

	Funcion(casas);
	printf("mayor robo posible: %d\n",rob(casas,4));

	int casas2[5];

	casas2[0]=2;
	casas2[1]=7;
	casas2[2]=9;
	casas2[3]=3;
	casas2[4]=1;


	printf("mayor robo posible: %d\n",rob(casas2,5));



	return 0;
}

