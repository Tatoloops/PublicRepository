#include <stdio.h>
int main(){
	unsigned char n;
	scanf("%hhu",&n);
	int stone[n];
	for(i=0;i<n;++i){
		scanf("%u",&stone[i]);
	}
	for(i=0;i<n-1;++i)
		for(j=i+1;j<n;++j)
			if (stone[i]<stone[j]){
				stone[i]=stone[i]+stone[j];
				stone[j]=stone[i]-stone[j];
				stone[i]=stone[i]-stone[j];
			}
	return 0;
}
