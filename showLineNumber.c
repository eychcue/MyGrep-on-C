void showLineNumber(FILE* f) {
    int lineNum = 1;//Start the line number from 1
    char c;//Store a character from file

    //While it is not the end of file
    while ((c = fgetc(f)) != EOF) {
        //print out the line number inside brackets
        printf("[%d]: ", lineNum++);
        
        //Loop through the characters line by line and print it
        for ( c ; c!='\n' ; c=getc(f)) {
            printf("%c", c);
        }
        printf("\n");//Prints a new line 
    }
}
