#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {

    char dashI = 0;
    char * pString = argv[1]; // for now just getting the string. Will include quotes implementation later
    if(strcmp(argv[2], "-i")){
         dashI = 1;
    }
    char * pFile = argv[argc-1];

    int len = strlen(pString);

    FILE * fp = fopen(pFile, "r");

    if(NULL == fp){
        printf("failed to open file");
    }

    int count =0;
    while(!feof(fp)){
        int c = fgetc(fp);

        if(EOF == c) {
            break;
        }

        if(c == pString[0]) {
            char word[1000];
            int index = 0;


            do {
                word[index++] = c;
                c=fgetc(fp);
            } while (!feof(fp) && index <len && index<1000);
            word[index] = '\0';

            if(!dashI){
                if(0 == strcasestr(word, pString)){ //strcasestr for ignoring cases
                    count++;
                }
            }else{
                if(0 == strcmp(word, pString)){
                    count++;
                }
            }

        }
    }
    printf("%d",count);
    return 0;
}
