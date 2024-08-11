#include <stdio.h>
//1878. Rubinchik's Cube


int diferenciaNumeros(int a,int b,int limit){

	//check for higher numer
	int mayor,menor;
	if (a>b){
		mayor=a;
		menor=b;
	}
	else if(b>a){
		mayor=b;
		menor=a;
	}
	else{
		return 0;
	}

	//conseguir minima diferencia
	int minimaDiferencia =mayor-menor;

	mayor-=limit;

	if (menor-mayor <minimaDiferencia){
		minimaDiferencia=menor-mayor;
	}

	return minimaDiferencia;
}


int main(){
	const int colors =4;

	int position[colors];
	int j=0;
	// int a
	int colorsCuadrado = colors*colors;

	//scan all positions and keep only the top right 2x2 square.
	int count =0;
	for (int i=0;i<colorsCuadrado;i++){
		char frase[2];
		scanf("%s",frase);

		if (i==0 || i==1 || i==4 || i==5){
			position[count]=frase[0]-'0';
			if (i==5){
				break;
			}
			count++;
		}
	}



	int minTurnos=colorsCuadrado;

	for (int i =1; i<=colors;i++){
		// verificar cuantos turnos se requieren por cada cara formada en el primer 2x2.
		int turnos= diferenciaNumeros(position[0],i,colors);
		turnos+= diferenciaNumeros(position[1],i,colors);
		turnos+= diferenciaNumeros(position[2],i,colors);
		turnos+= diferenciaNumeros(position[3],i,colors);

		if (turnos<=minTurnos){
			minTurnos=turnos;
		}
	}

	printf("%d",minTurnos);

	return 0;
}