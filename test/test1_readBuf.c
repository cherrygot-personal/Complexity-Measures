/**
 * Test Id:     1 
 * Description: Initialising Lexer and loading the file into the memory.
 **/

#include <stdio.h>
#include <stdlib.h>
#include "../src/lexer.h"

int main() {
    struct Lexer *clexer = malloc(sizeof(struct Lexer)); 
    
    if(clexer) {
        initLexer(clexer, "subject.c");

        printf("The content of Lexer instance\n");
        printf("pos: %d\n", clexer->pos);
        printf("buflen: %d\n", clexer->buflen);
        printf("oprCount: %d\n", clexer->oprCount);
        printf("opdCount: %d\n", clexer->opdCount);
        printf("buf: %s\n", clexer->buf);

        delLexer(clexer);
        free(clexer);
    }
    
    return 0;
}