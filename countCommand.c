#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countString(char* str, FILE* f, int bol);
void returnDashK(int argc, char * argv[]);
void returnCount(int argc, char * argv[]);

int main (int argc, char *argv[])
{
	char *fileName=argv[argc-1];
	
	FILE  *fp;
	fp = fopen(fileName, "r");
	
	if(strcmp(argv[1], "-c") == 0){
		returnCount(argc,argv);
	}else if (strcmp(argv[1], "-k") == 0){
		returnDashK(argc, argv);
	}
	
}

int countString(char* strngSearch, FILE* fileName, int bol) {
	char fillArr[100];
	int count =0;
	
	while(fscanf(fileName,"%s",fillArr)!=-1) {
		if(!bol){
			if((strcmp(fillArr, strngSearch)) ==0) {
				count++;
			}
		}else{
			if((strcasecmp(fillArr, strngSearch)) ==0) {
				count++;
			}
		}
		
	}
	return count;
}

void returnDashK(int argc, char * argv[]) {
	
	int i=0;
	int caseIgnore =0;
	int start =2;
	if(strcmp(argv[2], "-i") ==0){
		caseIgnore = 1;
		start = 3;
	}
	
	int count;
	for(i =start;i<argc-1;i++) {
		FILE  *fp;
		fp = fopen(argv[argc - 1], "r");
		count = countString(argv[i], fp, caseIgnore);
		printf("%s %d \n", argv[i], count);
	}
}

void returnCount(int argc, char * argv[]) {
	
	int caseIgnore =0;
	FILE  *fp;
	fp = fopen(argv[argc - 1], "r");
	if( argc == 5 ){
		if(strcmp(argv[2], "-i") == 0){
			caseIgnore = 1;
		}
		int count;
		count = countString(argv[3], fp, caseIgnore);
		printf("%d \n", count);
		
	}else if( argc == 4 ){
		if(strcmp(argv[2], "-i") == 0){
			caseIgnore = 1;
		}
		int count;
		count = countString(argv[2], fp, caseIgnore);
		printf("%d \n", count);
	}
}
