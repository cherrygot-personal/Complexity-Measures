#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

unsigned int initLexer(struct Lexer *argLexer, const char *filePath) {
    printf("In initLexer");
    argLexer->pos = 0;
    argLexer->opdCount = 0;
    argLexer->oprCount = 0;
    argLexer->opdTable = NULL;
    argLexer->oprTable = NULL;

    return readBufFromFile(argLexer, filePath);
}

unsigned int readBufFromFile(struct Lexer *argLexer, const char *filePath) {
    printf("In readBufFromFile\n");
    FILE *theFile = fopen(filePath, "rb");
    char *buffer = NULL;
    unsigned int length = 0;
    
    if(theFile) {
        fseek(theFile, 0, SEEK_END);
        length = ftell(theFile);
        fseek(theFile, 0, SEEK_SET);
        buffer = malloc(length + 1);
        
        if(buffer) {
            fread(buffer, 1, length, theFile);

            argLexer->buf = buffer;
            argLexer->buflen = length;
        }
        fclose(theFile);
        return 0;
    }
    else {
        return 10;      //  Error Id: Can't read the file.
    }
}

void delLexer(struct Lexer *argLexer) {
    printf("In delLexer\n");
    free((char *)argLexer->buf);
    free(argLexer->oprTable);
    free(argLexer->opdTable);
    free(argLexer); 
}
