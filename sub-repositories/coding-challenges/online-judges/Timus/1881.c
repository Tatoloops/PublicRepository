/*		1881
		Long Problem Statement
 */
#include <stdio.h>
#include <string.h>

int main(){
	int LinesPerPage;
	unsigned short SymbolsPerLine;
	unsigned short Words;
	scanf("%d %hu %hu",&LinesPerPage,&SymbolsPerLine,&Words);

	int CurrentPage=1;
	int LinesDone=0;
	int SymbolsDone=0;
	int AddedSymbols=0;

	char WordTyped[SymbolsPerLine];
	//printf("-LinesPerPage:%d\n-SymbolsPerLine:%hu\n-Words:%hu\n\n",LinesPerPage,SymbolsPerLine,Words);
	for(unsigned short i=0;i<Words;i++){
		scanf("%s",WordTyped);
		AddedSymbols=strlen(WordTyped);
		if (SymbolsDone!=0)
			SymbolsDone+=AddedSymbols+1;
		else
			SymbolsDone+=AddedSymbols;
		if(SymbolsDone>SymbolsPerLine){
			SymbolsDone=AddedSymbols;
			++LinesDone;
			if (LinesDone >= LinesPerPage){
				LinesDone=0;
				++CurrentPage;
			}
		}
		//printf("-Current word:%s\n-Length:%d\n-CurrentPage:%d\n-LinesDone:%d\n-SymbolsOnLine:%d\n\n",WordTyped,AddedSymbols,CurrentPage,LinesDone,SymbolsDone);
	}
	//printf("-FinalResult: ");
	printf("%d",CurrentPage);
	return 0;
}