#include <stdio.h>
int mixingcodes(unsigned long long*code,int *code_amount,char* finalmatrix,int matrix_size){ //returns the d values to be summed
	int d_count=0;
	int i;
	int sum=0;
	int copy_count=0;
	int main_code;
	int copy[*code_amount];
	for(i=0;i<*code_amount;++i)
		copy[i]=0;
	for(i=0;i<*code_amount-1;++i){
		if(code[*code_amount]&code[i])
			if (sum==0)
				main_code=i;
			copy[i]=1;
			++sum;
	}
	for(i=0;i<n;++i){
		if (code[main_code] & code[*code_amount] & 1<<i){
			++d_count;
			for(j=0;j<n;++j)
				finalmatrix
		}
	}
	code[main_code]
	for(i=main_code+1;i<sum;++i){

	}
	return d_count;
}
int main(){
	int n,d,d_count,a,a_count,save,value,code_count,connected; // n:matrix size d:cost of taking a flight off a:cost of adding a new flight.
	scanf("%d%d%d",&n,%d,%a);
	int matriz[n][n];
	char finalmat[n][n];
	if (n>64) i=2;
	else i=1;
	unsigned long long code[n+1][i];
	code_count=0;

	for(i=0;i<n;++i)
		for(j=0;j<n;++j)
			finalmat[i][j]='0';

	/*less tha 64 flights*/ //---

	//first line
	for(i=1;i<n-1;++i){
		scanf("%d",&value);
		code[code_count][0]=code[code_count][0]|(value<<i);
		m[0][i]=value;
	}
	//the rest of the lines
	for(i=1;i<n-1;++i){ //files
		connected=0;
		for(j=0;j<=code_count;++j){
			if((1<<i) & code[j]){ //the airport 'i' is connected to one of the previous airports
				connected=j;
				j=code_count; //exit loop
			}
		}
		if(connected){
			for(j=0;j<i;++j){//columns
				scanf();
			}
			for(j=i;j<=n;++j){
				scanf("%d",&m[i][j]);
				if(code[connected][0] & m[i][j]<<j){
						finalmat[i][j]='d';
						finalmat[j][i]='d';
						++d_count;
				}
				else{
					code[connected][0]=code[connected][0]|m[i][j]<<j;
				}
			}
		}
		else{
			++code_count;
			for(j=0;j<i;++j){//columns
				scanf();
			}
			for(j=i;j<=n;++j){
				scanf("%d",&m[i][j]);
				code[code_count][0]=code[code_count][0]|m[i][j]<<j;
			}
				//checking for connections to previous codes/airports
			d_count+=mixingcodes(code,&code_count,finalmat,n);
		}


	}
	//at this point no code should have repeated '1' bits, so we can merge them
	code_count
	for(i=0;i<code_count;++i)
		if(code[i][0]&1){
			connected=i;
			i=code_count;
		}
	for(i=0;i<code_count;++i){
		if(i!=connected){
			for(j=1;j<n;++j){
				if(1<<j & code[i][0]){
					finalmat[j][0]='a';
					finalmat[0][j]='a';
					++a_count;
				}
			}
		}
	}
	printf("%d",a*a_count+d*d_count);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%c",finalmat[i][j]);
		}
		printf("\n");
	}

	return 0;
}