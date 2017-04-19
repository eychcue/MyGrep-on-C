#include <stdio.h>
#include <string.h>


int returnCount(char * stringUsed, char fileName, char dashINum);
void returnStringCount(int argc, char * argv[]);
void returnDashK(int argc, char * argv[]);

int main(int argc, char * argv[]) {


    return 0;
}

int returnCount(char * stringUsed, char fileName, char dashINum) { // dashI for -i either 0 for ignoring case or 1 for not

    char dashI = dashINum;
    char * pFile = fileName;
    char * pString = stringUsed;

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
    return count;
}
void returnStringCount(int argc, char * argv[]) {


    char caseIgnore =0;
    if( argc ==5 ){
        if(strcmp(argv[2], "-i")){
            caseIgnore = 1;
        }
        int count;
        count = returnCount(argv[3], argv[argc - 1], caseIgnore);
        printf("%d \n", count);

    }else if( argc == 4 ){
        if(strcmp(argv[1], "-i")){
            caseIgnore = 1;
        }
        int count;
        count = returnCount(argv[2], argv[argc - 1], caseIgnore);
        printf("%d \n", count);
    }

}

void returnDashK(int argc, char * argv[]) {

    int i=0;
    char caseIgnore =0;
//    if(strcmp(argv[2], "-i")){
//        caseIgnore = 1;
//    }
    int count;
    char * store;
    for(i =2;i<argc-1;i++) {
        store[i] = argv[i];
        count = returnCount(store[i], argv[argc - 1], caseIgnore);
        printf("%s + %d \n", store[i], count);
    }


}
