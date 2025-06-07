#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	int id[n];
	int m[n],values[101],value_count,switches;
	value_count=0;
	for(i=0;i<n;++i){
		scanf("%d",&id[i]);
		scanf("%d",&m[i]);
		switches=~(~switches|0x1);
		for(j=0;j<value_count;++j)
			if(m[i]==values[j])
				switches=switches|0x1;
		if (~switches & 0x1){
			values[value_count]=m[i];
			++value_count;
		}
	}
	for(i=0;i<value_count-1;++i)
		for(j=i+1;j<value_count;++j)
			if (values[i]<values[j]){
				values[i]=values[i]+values[j];
				values[j]=values[i]-values[j];
				values[i]=values[i]-values[j];
			}
	for(j=0;j<value_count;++j)
		for(i=0;i<n;++i){
			if(values[j]==m[i])
				printf("%d %d\n",id[i],m[i]);
	}
	return 0;
}