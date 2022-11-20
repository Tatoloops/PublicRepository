#include <stdio.h>
typedef unsigned short us;
int main(){
	us p,pi,d,di,r;
	scanf("%hu",&p);
	scanf("%hu",&pi);
	scanf("%hu",&d);
	scanf("%hu",&di);
	if (d<p)
		printf("%hu",p);
	else{
		r=(d-p)/(di+pi);
		p+=r*pi;
		d-=r*di;
		r=d-p;
		if(r>pi)
			printf("%hu",p+pi);
		else
			printf("%hu",d);
	}
	return 0 ;
}