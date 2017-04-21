#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Declare the functions we use in main
int countString(char *str, FILE *f, int bol);
void returnDashK(int argc, char *argv[]);
void returnCount(int argc, char *argv[]);
void dashO(char *high, FILE *f);
void dashS(FILE *f);
void dashNwithString(char *str, FILE *fp);
void dashN(FILE *fp);

//Main
void main(int argc, char *argv[]) {

    char *filename = argv[argc - 1];
    FILE *f = fopen(filename, "r");
    char *str;

    //Check to see that the file exists
    if (f == NULL) {
        printf("Error: file %s not found\n", argv[argc - 1]);
        exit(-1);
    }

    //Switch the arguments
    switch (argv[1][1]) {
        case 'c' :
            /* Call -c func with specified arguments */
            returnCount(argc, argv);
            break;

        case 'o' :
            /* Call -o func with specified arguments */
            str = argv[2];
            dashO(str, f);
            break;
        case 's' :
            /* Call -s func with specified arguments */
            dashS(f);
            break;
        case 'n' :
            /* Call -n func with specified arguments */
            if (argc == 4) {
                str = argv[2];//Second argument, starts from 0
                dashNwithString(str, f);
            } else {
                dashN(f);
            }
            break;

        case 'k' :
            /* Call -k func with specified arguments */
            returnDashK(argc, argv);
            break;

        default :
            printf("Error, command %s not found\n", argv[1]);
    }

    fclose(f);
    return;

}

void returnDashK(int argc, char *argv[]) {

    int i = 0;
    int caseIgnore = 0;
    if (strcmp(argv[2], "-i")) {
        caseIgnore = 1;
    }

    int count;
    for (i = 2; i < argc - 1; i++) {
        FILE *fp;
        fp = fopen(argv[argc - 1], "r");
        count = countString(argv[i], fp, caseIgnore);
        printf("%s %d \n", argv[i], count);
    }
}

void returnCount(int argc, char *argv[]) {
    int caseIgnore = 0;
    FILE *fp;
    fp = fopen(argv[argc - 1], "r");
    if (argc == 5) {
        if (strcmp(argv[2], "-i") == 0) {
            caseIgnore = 1;
        }
        int count;
        count = countString(argv[3], fp, caseIgnore);
        printf("%d \n", count);

    } else if (argc == 4) {
        if (strcmp(argv[2], "-i") == 0) {
            caseIgnore = 1;
        }
        int count;
        count = countString(argv[2], fp, caseIgnore);
        printf("%d \n", count);
    }
}

int countString(char *strngSearch, FILE *fileName, int bol) {
    char fillArr[1000];
    int count = 0;
    while (fgets(fillArr, 1000, fileName) != NULL) {
        if (!bol) {
            if ((strstr(fillArr, strngSearch)) != NULL) {
                count++;
            }
        } else {
            if ((strcasestr(fillArr, strngSearch)) != NULL) {
                count++;
            }
        }
    }
    return count;
}


void dashO(char *high, FILE *f) {
    int MAX_CHAR = 256;
    char w[MAX_CHAR];/*//Creating a character array with limit of 255 */
    int w_count = 0;
    while (!feof(f))/*start searching from the beginning of the file */
    {
        fscanf(f, "%s", w);/*Scan the file characters into "w"*/
        if (strstr(w,high))/*count how many times the input string matches the scanned string*/ {
            w_count++;
        }
    }
    int i;
    for (i = 0; i < w_count; i++) {
        printf("\033[1;31m"); /* printing red*/
        printf("%s\n", high); /*printing the match string*/
        printf("\033[1m");/*close the red color*/
    }
}


void dashS(FILE *f) {
    char c;                         // character to store value of fgetc() from file
    int lineStart = 1;              // boolean to represent whether or not this is a new line, initialized as true.
    while ((c = fgetc(f)) != EOF) { // while not end of file, reads whole file
        if (!lineStart) {
            if (c == '\n') {        // new line, start removing spaces again
                lineStart = 1;
                printf("\n");
            } else {                // prints line until it reaches \n
                printf("%c", c);
            }
        } else {
            if (c != ' ' && c!= '\t') {         // find first non-space char in line and starts printing
                lineStart = 0;
                printf("%c", c);
            }
        }
    }
}

void dashNwithString(char *str, FILE *fp) {
    int Max_Char = 256;//Set the maximum character to 256
    char line[Max_Char];//Create a character array with limit of 256
    int lineNum = 1;//Start the line number from 1

    /**fgets scan the file in one shot
    ** @line is where to save the line
    ** @Max_Char is the maximum size of this string
    ** @fp is the file source
    **/
    while (fgets(line, Max_Char, fp) != NULL) {

        //ststr checks str(haystack) if it contains line (needle)
        if (strstr(line, str) != NULL) {
            printf("%d: %s", lineNum++, line);//If it not Null, then print that line with the line number
        }
    }
}

void dashN(FILE *fp) {
    int lineNum = 1;//Start the line number with 1
    char c;//Store a character from file

    //While it is not the end of file
    while ((c = getc(fp)) != EOF) {
        //print out the line number
        printf("%d: ", lineNum++);

        //Loop through the characters line by line
        while (c != '\n') {
            printf("%c", c);
            c = getc(fp);
        }
        printf("\n");//Prints a new line
    }
}
