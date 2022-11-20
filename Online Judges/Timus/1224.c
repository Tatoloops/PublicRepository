#include <stdio.h>
int main(){
	unsigned int h,w;
	scanf("%u%u",&h,&w);
	if(w<h)
		printf("%u",(w<<1)-1);
	else
		printf("%u",(h<<1)-2);
	return 0;
}