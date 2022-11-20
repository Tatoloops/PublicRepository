#include <stdio.h>
#include <stdlib.h>
long long binstring_to_number(unsigned char*string,char*size){
	long long number;
	unsigned char digit,i;
	number=0;
	digit=0;
	i=0;
	do{
		number=number<<1;
		number+=digit;
		digit=*(string+i)-48;
		if (digit<0)
			digit=0;
		++i;
	}
	while(digit>47);
	*size=i-1;
	return number;
}
int main(){
	unsigned char a_size,i; //alphabet size,i
	unsigned char s[1000001]; //the code string, cyphercode
	scanf("%d",&a_size);
	unsigned char tobin[a_size+1];
	long long alpha[a_size];
	unsigned char alpha_size[a_size];
	scanf("%s",s);

	for(i=0;i<a_size;++i){
		scanf("%s",tobin);
		alpha[i]=binstring_to_number(tobin,alpha_size+i);
	}

}