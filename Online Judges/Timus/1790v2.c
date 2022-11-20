#include <stdio.h>
int main(){ //1790
	int n,a,m;
	int count[2],aux[2];
	scanf("%d",&n);
	scanf("%d",&m);
	aux[0]=0;
	aux[1]=0;
	if (n==2)
		while(m>0){
			--m;
			scanf("%d",&a);
			if (a==1) {
				++aux[0];
				--aux[1];
			}
			else if (a==2){
				++aux[1];
				--aux[0];
			}
			else{
				--aux[0];
				--aux[1];
			}
			if (aux[0]<0) aux[0]=0;
			if (aux[1]<0) aux[1]=0;
			if (aux[0]>1 || aux[1]>1)
				m=-1;
		}
	else if((n-2)*2<=m){
		count[0]=0;
		count[1]=0;
		while(m>0){
			--m;
			scanf("%d",&a);
			if (count[0]<n-2){ 
			//PRIMERA PARTE
			//LEFT TO RIGHT
				if(a==count[0]+2 && aux[0]==0){ //ascending to n-1
					++count[0];
				}
				else if(aux[0]>0){ // you are in the auxiliar line
					if (a==count[0]-aux[0]+2){ // 1-- going forward
						--aux[0];
					}
					else if(aux[0]==(count[0]-1)/2){ // 2-- limit of the auxiliar line
						if (a!=count[0]-aux[0]+1){
							count[0]-=2;
							--aux[0];
						}
					}
					else if (a==aux[0]+2){ // 3-- going backwards
						++aux[0];
					}
					else{// 
						--aux[0];
						count[0]-=2;
					}
				}
				else if(count[0]%2!=0 && count[0]!=1) //going to the aux line
					if(a==2){
						++aux[0];
					}
					else{
						--count[0];
					}
				else if (a!=2 || count[0]!=1)
					--count[0];

			// RIGHT TO LEFT
				if(a==n-count[1]-1 && aux[1]==0){ //ascending to 2
					++count[1];
				}
				else if(aux[1]>0){ // you are in the auxiliar line
					if (a==n-count[1]+aux[1]-1){ // 1-- going forward
						--aux[1];
					}
					else if(aux[1]==(count[1]-1)/2){ // 2-- limit of the auxiliar line
						if (a!=n-count[1]+aux[1]){
							count[1]-=2;
							--aux[1];
						}
					}
					else if (a==n-aux[1]-1){ // 3-- going backwards
						++aux[1];
					}
					else{// everything else
						--aux[1];
						count[1]-=2;
					}
				}
				else if(count[1]%2==1 && count[1]!=1) //going backwards
					if(a==n-1){
						++aux[1];
					}
					else{
						--count[1];
					}
				else if (a!=n-1 || count[1]!=1)
					--count[1];
			//	
				if (count[0]<0) count[0]=0;
				else if (count[0]==n-2){ //llegaste a la derecha
					if (n%2!=0) count[1]=2; //impar
					else count[1]=1; //par
				}
				if (count[1]<0) count[1]=0;
				else if (count[1]==n-2) {
					count[0]=n-2;
					count[1]=2; //llegaste a la izquierda
				}
			}
			//* SEGUNDA PARTE *//
			else{
				if (count[1]==1){ 
					if (n%2!=0){ // 1 0 1 0 1  -- 1 is the treasure - 0 is an empty space
						if (a==aux[0]+2 && a%2!=0) ++aux[0]; //a impar
						else --aux[0];
						if (a==n-aux[1]-1 && a%2!=0) ++aux[1];
						else --aux[1];
					}
					else{ // 1 0 1 0
						if (a==aux[0]+2 && a%2!=0) ++aux[0];
						else --aux[0];
						if (a==n-aux[1]-1 && a%2!=0) ++aux[1];
						else --aux[1];
					}
				}
				else{//aux[0] = 2
					if (n%2!=0){ // 0 1 0 1 0 - n impar
						if (a==aux[0]+2 && a%2==0) ++aux[0];
						else --aux[0];
						if (a==n-aux[1]-1 && a%2==0) ++aux[1];
						else --aux[1];
					}
					else{ // 0 1 0 1 - n par
						if (a==aux[0]+2 && a%2==0) ++aux[0];
						else --aux[0];
						if (a==n-aux[1]-1 && a%2==0) ++aux[1];
						else --aux[1];
					}
				}
				--count[1];
				if (count[1]<1)
					count[1]=2;

				if (aux[0]<0) aux[0]=0;
				else if (aux[0]==n-2) m=-1; //llegaste a la derecha
				if (aux[1]<0) aux[1]=0;
				else if (aux[1]==n-2) m=-1; //legaste a la izquierda
			}
			//printf("a: %d c[0]: %d c[1]: %d c[2]: %d aux[0]: %d aux[1]: %d m: %d pos:%d \n",a,count[0],count[1],count[2],aux[0],aux[1],m,pos);
		}
	}
	if (m==-1)
		printf("YES");
	else
		printf("NO");
	return 0;
}