void showStringAndLineNumber(char* str, FILE* fp) {
    int Max_Char = 256;//Set the maximum character to 256
    char line[Max_Char];//Create a character array with limit of 256
    int lineNum = 1;//Start the line number from 1

    /**fgets scan the file in one shot
    ** @line is where to save the line
    ** @Max_Char is the maximum size of this string
    ** @ fp is the file source
    **/
    while (fgets(line, Max_Char, fp)!= NULL) {
        
        //ststr checks str(haystack) if it contains line (needle)
        if (strstr(line,str) != NULL) {
            printf("%d: %s", lineNum++, line);//If it not Null, then print that line with the line number
        }
    }
}
/* print file content with line number */
void showLineNumber(FILE* fp) {
    int lineNum = 1;//Start the line number with 1
    char c;//Store a character from file

    //While it is not the end of file
    while ((c = getc(fp)) != EOF) {
        //print out the line number inside brackets
        printf("%d: ", lineNum++);

        //Loop through the characters line by line
        while (c!='\n') {
            printf("%c", c);
	    c = getc(fp);
        }
        printf("\n");//Prints a new line 
    }
}
