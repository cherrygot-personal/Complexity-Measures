#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"




unsigned int initLexer(struct Lexer *argLexer, const char *filePath) {
//  printf("In initLexer");

    argLexer->pos = 0;
    argLexer->opdCount = 0;
    argLexer->oprCount = 0;
    argLexer->opdTable = NULL;
    argLexer->oprTable = NULL;

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("+", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("-", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("*", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("/", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("\%", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("++", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("--", 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("=", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("+=", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("-=", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("*=", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("/=", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("\%=", 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("&&", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("||", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("!", 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("==", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("!=", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("<=", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(">=", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("<", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(">", 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("if", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("do", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("while", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("for", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("switch", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("case", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("return", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("continue", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("break", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("sizeof", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("goto", 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("void", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("int", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("char", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("float", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("double", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("long", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("unsigned", 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("[", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("(", 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator("{", 0));

    return readBufFromFile(argLexer, filePath);
}




unsigned int readBufFromFile(struct Lexer *argLexer, const char *filePath) {
//  printf("In readBufFromFile\n");

    FILE *theFile = fopen(filePath, "rb");
    char *buffer = NULL;
    unsigned int length = 0;
    
    if(theFile) {
        fseek(theFile, 0, SEEK_END);
        length = ftell(theFile);
        fseek(theFile, 0, SEEK_SET);
        buffer = calloc(length + 1, sizeof(char));
        
        if(buffer) {
            fread(buffer, 1, length, theFile);

            argLexer->buf = buffer;
            argLexer->buflen = length;
        }
        fclose(theFile);
        return 0;
    }
    return 10;      //  Error desc: Can't read the file.
}




unsigned int parseCode(struct Lexer *argLexer) {
//  printf("In parseCode\n");
    return 0;
}




void delLexer(struct Lexer *argLexer) {
//  printf("In delLexer\n");

    free((char *)argLexer->buf);
    free(argLexer->oprTable);
    free(argLexer->opdTable);
    free(argLexer); 
}




struct Operator* createOperator(const char *args, unsigned int argc) {
//  printf("In createOperator\n");

    struct Operator *temp = malloc(sizeof(struct Operator));
    
    if(temp) {
        temp->str = args;
        temp->count = argc;
    }

    return temp;
}




unsigned int addOperator(struct Operator **oprTable, unsigned int *len, struct Operator *opr) {
//  printf("In addOperator\n");
    
    if(opr) {
        struct Operator *temp;
        if(*oprTable) {
            temp = realloc(*oprTable, (*len + 1) * sizeof(struct Operator));
        }
        else {
            temp = malloc(sizeof(struct Operator));
        }
        
        if(temp) {
            temp[(*len)] = *opr;
            *len += 1; 
            *oprTable = temp;

            free(opr);
            return 0;
        }
    }

    free(opr);
    return 11;      //  Error desc: Can't add more operators.
}




struct Operand* createOperand(const char *args, unsigned int argc) {
//  printf("In createOperand");

    struct Operand *temp = malloc(sizeof(struct Operand));
    
    if(temp) {
        temp->str = args;
        temp->count = argc;
    }

    return temp;
}




unsigned int addOperand(struct Operand **opdTable, unsigned int *len, struct Operand *opd) {
//  printf("In addOperand\n");
    
    if(opd) {
        struct Operand *temp;
        if(*opdTable) {
            temp = realloc(*opdTable, (*len + 1) * sizeof(struct Operand));
        }
        else {
            temp = malloc(sizeof(struct Operand));
        }
        
        if(temp) {
            *(temp + (*len)) = *opd;
            *len += 1; 
            *opdTable = temp;

            free(opd);
            return 0;
        }
    }

    free(opd);
    return 12;      //  Error desc: Can't add more operands.
}