/**
 * Test Id:     2 
 * Description: Tokenizing the input file.
 **/

#include <stdio.h>
#include <stdlib.h>
#include "../src/lexer.h"

int main() {
    struct Lexer *clexer = malloc(sizeof(struct Lexer)); 
    
    if(clexer) {
        initLexer(clexer, "subject3.c");
        
        lexify(clexer);

        printf("Operator: \tOccurance:\n");
        for(int i = 0; i < clexer->oprCount; i++) {
            printf("%s\t\t%d\n", clexer->oprTable[i].str, clexer->oprTable[i].count);
        }

        printf("Operand: \tOccurance:\n");
        for(int i = 0; i < clexer->opdCount; i++) {
            printf("%s\t\t%d\n", clexer->opdTable[i].str, clexer->opdTable[i].count);
        }

        delLexer(clexer);
        free(clexer);
    }
    
    return 0;
}