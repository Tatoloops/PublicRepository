#include <stdio.h>
#include <string.h>

typedef struct{
	int ID;
	char name[20];
	float time;
}contestant;
//(sizeof(contestant)*3 ) * 0 + sizeof(contestant)*i
//sizeof(contestant)*(3*0+i)  
void initialize_contestant (contestant* cont){
	for (int i=0;i<3;++i){
		(cont+(sizeof(contestant)*(3*0+i)))->ID=0;
		//for (int j=0;j<20;++j)
			*((cont+(sizeof(contestant)*(3*0+i)))->name)="\0";
		(cont+(sizeof(contestant)*(3*0+i)))->time=999999.9;

		(cont+(sizeof(contestant)*(3*1+i)))->ID=0;
		//for (int j=0;j<20;++j)
			*((cont+(sizeof(contestant)*(3*1+i)))->name)="\0";
		(cont+(sizeof(contestant)*(3*1+i)))->time=999999.9;
	}
}
void string_copy(char* destination_string, char* source_string){
	char count=0;
	do{ *(destination_string+count)=*(source_string+count);
		++count;
	}
	while (*(source_string+count) != 0);
}


int main(){
	unsigned short N;
	contestant Current;
	contestant Category[2][3];
	initialize_contestant(&(Category[0][0]));
	scanf("%hu",&N);
	
	for(int i=0;i<N;++i){
		scanf("%d",&(Current.ID));
		scanf("%s",Current.name);
		scanf("%e",&(Current.time));
		if (scanf("%hu")==1){ //category 1
			if (Current.time < Category[0][2].time)
				if (Current.time < Category[0][1].time)
					if (Current.time < Category[0][0].time){	//first place

						Category[0][2].ID 		=			Category[0][1].ID;
						string_copy(Category[0][2].name,	Category[0][1].name);
						Category[0][2].time 	=			Category[0][1].time;

						Category[0][1].ID 		=	 		Category[0][0].ID;
						string_copy(Category[0][1].name, 	Category[0][0].name);
						Category[0][1].time		=			Category[0][0].time;

						Category[0][0].ID 		=			Current.ID;
						string_copy(Category[0][0].name, 	Current.name);
						Category[0][0].time		=			Current.time;
					}	
					else{										//second place
						Category[0][2].ID 		=			Category[0][1].ID;
						string_copy(Category[0][2].name,	Category[0][1].name);
						Category[0][2].time 	=			Category[0][1].time;

						Category[0][1].ID 		=	 		Current.ID;
						string_copy(Category[0][1].name, 	Current.name);
						Category[0][1].time		=			Current.time;
					}									
				else{											//third place
					Category[0][2].ID 		=	 		Current.ID;
					string_copy(Category[0][2].name, 	Current.name);
					Category[0][2].time		=			Current.time;
				}										
		}

		else{							//category 2

		}
	}

	for(int i=0;i<3;++i)
		printf("%d %s\n",Category[0][i],Category[0][i]);
	for(int i=0;i<3;++i)
		printf("%d %s\n",Category[1][i],Category[1][i]);
	return 0;
}