#incluse <stdio.h>
#include <string.h>

void main(){

	char cmd[1000], chr;
	int i=0;

	printf("$MyGrep ");
	scanf("%s", cmd);

	while(cmd[i] != \n){
		if(chr == ' '){
			i++;
		}
		else if(chr != '-'){
			printf(\n"Error, commands must be preceded by a - ");\
			break;
		}
		else{
			i++;
			callCMD(cmd[], i);
		}
	}
}


void callCMD(char cmd[], int index){
	if(cmd[index] == 'c' || cmd[index] == 'C'){
		funcC(cmd[], index);
	}
	else if(cmd[index] == 'o' || (cmd[index] == 'O'){
		funcO(cmd[], index);
	}	
	else if(cmd[index] == 's' || (cmd[index] == 'S'){
		funcS(cmd[], index);
	}
	else if(cmd[index] == 'n' || (cmd[index] == 'N'){
		funcN(cmd[], index);
	}
	else if(cmd[index] == 'k' || (cmd[index] == 'K'){
		funcK(cmd[], index);
	}
	else {
		printf(\n"Error: unrecognized command");
	}
}
