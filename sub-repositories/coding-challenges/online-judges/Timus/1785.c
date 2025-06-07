#include <stdlib.h>
#include <stdio.h>
int main () //1785. Lost in Localization
	{
	int a;
	scanf("%d",&a);
	if (a>=1 && a<5)
		printf("few");
	else if (a>=5 && a<10)
			printf("several");
		else if (a>=10 && a<20)
				printf("pack");
			else if (a>=20 && a<50)
					printf("lots");
				else if (a>=50 && a<100)
						printf("horde");
					else if (a>=100 && a<250)
							printf("throng");
						else if (a>=250 && a<500)
								printf("swarm");
							else if (a>=500 && a<1000)
									printf("zounds");
								else if (a>=1000)
										printf("legion");
	return 0;
	}