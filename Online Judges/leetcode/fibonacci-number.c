// compilation:
// include   				~   	linker
// #Include <math.h>    	~    	-lm

int fibMath(int n){
	if (n==2) return 1;
	else{
		return (1/sqrt(5) * pow((1+ sqrt(5))/2,n) - 1/sqrt(5) * pow((1- sqrt(5))/2,n));
	}
	
}



int fibLoop(int n){
	int pre2=0;
	int pre1=1;
	int new;
	for (char i=0;i<n;i++){
		new = pre2 + pre1;
		pre2 = pre1;
		pre1=new;
	}
	return pre2;
}