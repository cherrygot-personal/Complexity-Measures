#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "lib.h"

unsigned int initLexer(struct Lexer *argLexer, const char *filePath) {
//  printf("In initLexer");

    argLexer->pos = 0;
    argLexer->opdCount = 0;
    argLexer->oprCount = 0;
    argLexer->opdTable = NULL;
    argLexer->oprTable = NULL;

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("+", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("-", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("*", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("/", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("\%", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("++", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("--", 0, 2), 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("=", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("+=", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("-=", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("*=", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("/=", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("\%=", 0, 2), 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("&&", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("||", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("!", 0, 1), 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("==", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("!=", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("<=", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring(">=", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("<", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring(">", 0, 1), 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("if", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("do", 0, 2), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("while", 0, 5), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("for", 0, 3), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("switch", 0, 6), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("case", 0, 4), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("return", 0, 6), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("continue", 0, 8), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("break", 0, 5), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("sizeof", 0, 6), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("goto", 0, 4), 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("void", 0, 4), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("int", 0, 3), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("char", 0, 4), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("float", 0, 5), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("double", 0, 6), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("long", 0, 4), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("unsigned", 0, 8), 0));

    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("[", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("(", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring("{", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring(".", 0, 1), 0));
    addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(substring(";", 0, 1), 0));

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




unsigned int lexify(struct Lexer *argLexer) {
  printf("In parseCode\n");

    char ch1, ch2, ch3; 
    char ch4[2] = "_";
    ch1 = ch2 = ch3 = '\0';

    while(argLexer->pos < argLexer->buflen) {
        ch1 = argLexer->buf[argLexer->pos];

        if(ch1 == '#') {
            escapeTill(argLexer, '\n');
        }
        else if(ch1 == '/') {
            argLexer->pos++;
            ch2 = argLexer->buf[argLexer->pos];

            if(ch2 == '/') {
                escapeTill(argLexer, '\n');
            }
            else if(ch2 == '*') {
                do {
                    escapeTill(argLexer, '*');
                    ch3 = argLexer->buf[argLexer->pos];
                } while (ch3 != '/');                       // comments ending with **/ not working. See logic!

                argLexer->pos++;
            }
            else {
                incOprCount(argLexer, "/");
            }
        }    
        else if(strContains("+-*\%=&|!<>.;", ch1)) {
            processOpr(argLexer);
        }
        else if(strContains("[{(", ch1)) {
            ch4[0] = ch1;
            incOprCount(argLexer, ch4);
            argLexer->pos++;
        }
        else if(_isDigit(ch1)) {
            processNum(argLexer);
        }
        else if(strContains("\"\'", ch1)) {
            processStr(argLexer);
        }
        else if(_isAlpha(ch1) || ch1 == '_') {
            processWord(argLexer);
        }
        else {
            argLexer->pos++;
        }
    }

    for(int i = 0; i < argLexer->oprCount; i++) {
        if(!strcmp(argLexer->oprTable[i].str, "while")) {
            argLexer->oprTable[i].count -= argLexer->oprTable[i - 1].count;     
            //  assuming do is just before while. I know it's lame!
        }
    }

    return 0;
}




unsigned int processWord(struct Lexer *argLexer) {
  printf("In processWord\n");    
    
    unsigned int flag;
    unsigned int numFlag = 0;
    unsigned int endPos = argLexer->pos + 1;

    while(endPos < argLexer->buflen && (_isAlpha(argLexer->buf[endPos]) || _isDigit(argLexer->buf[endPos]) || argLexer->buf[endPos] == '_' )) {
        if(_isDigit(argLexer->buf[endPos])) {
            numFlag = 1;
        }

        endPos++;
    }

    const char *temp = substring(argLexer->buf, argLexer->pos, endPos);

    if(!numFlag && isKeyword(temp)) {
        flag = incOprCount(argLexer, temp); 
    }
    else if(isFunction(argLexer, endPos)) {
        flag = incOprCount(argLexer, temp); 
    }
    else {
        flag = incOpdCount(argLexer, temp);
    }

    argLexer->pos = endPos;

    if(flag != 1) {
        free((char *)temp);
    }

    return 0;
}




unsigned int isFunction(struct Lexer *argLexer, unsigned int endPos) {
  printf("In isFunction\n");

    char ch;
    unsigned int i = endPos;

    do {
        ch = argLexer->buf[i];
        i++;
    } while(strContains(" \n\t", ch));

    i--;

    if(argLexer->buf[i] == '(') {
        return 1;
    }

    return 0;
}




unsigned int isKeyword(const char *args) {
  printf("In isKeyword\n");

    const char *keywords[18] = {
        "if", "do", "while", "for", "switch",
        "case", "return", "continue", "break",
        "sizeof", "goto", "void", "int", "char",
        "float", "double", "long", "unsigned"
    };

    for(int i = 0; i < 18; i++) {
        if(!strcmp(keywords[i], args)) {
            return 1;
        }
    }

    return 0;
}




unsigned int processNum(struct Lexer *argLexer) {
  printf("In processNum\n");

    unsigned int endPos = argLexer->pos + 1;

    while(endPos < argLexer->buflen && _isDigit(argLexer->buf[endPos])) {
        endPos++;
    }

    const char *temp = substring(argLexer->buf, argLexer->pos, endPos);
    unsigned int flag = incOpdCount(argLexer, temp);

    argLexer->pos = endPos;

    if(flag != 1) {
        free((char *)temp);
    }

    return 0;
}




unsigned int processStr(struct Lexer *argLexer) {
  printf("In processStr\n");

    const char ch = argLexer->buf[argLexer->pos];
    unsigned int endPos = argLexer->pos + 1;
    unsigned int flag = 1;

    while(endPos < argLexer->buflen && flag) {
        if(argLexer->buf[endPos] == ch && argLexer->buf[endPos - 1] != '\\') {
            flag = 0;
        }

        endPos++;
    } 

    const char *temp = substring(argLexer->buf, argLexer->pos, endPos);
    flag = incOpdCount(argLexer, temp);

    argLexer->pos = endPos;

    if(flag != 1) {
        free((char *)temp);
    }

    return 0;
}




unsigned int processOpr(struct Lexer *argLexer) {
  printf("In processOpr\n");

    unsigned int endPos = argLexer->pos + 1;

    while(endPos < argLexer->buflen && strContains("+-*\%=&|!<>.;", argLexer->buf[endPos])) {
        endPos++;
    }

    const char *temp = substring(argLexer->buf, argLexer->pos, endPos);
    unsigned int flag = incOprCount(argLexer, temp);

    argLexer->pos = endPos;

    if(flag != 1) {
        free((char *)temp);       
    }

    return 0;
}




void delLexer(struct Lexer *argLexer) {
//  printf("In delLexer\n");

    free((char *)argLexer->buf);

    for(int i = 0; i < argLexer->oprCount; i++) {
        free((char *)argLexer->oprTable[i].str);
    }
    free(argLexer->oprTable);

    for(int i = 0; i < argLexer->opdCount; i++) {
        free((char *)argLexer->opdTable[i].str);
    }
    free(argLexer->opdTable);

//    free(argLexer); 
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




unsigned int incOprCount(struct Lexer *argLexer, const char *args) {
    for(int i = 0; i < argLexer->oprCount; i++) {
        if(!strcmp(argLexer->oprTable[i].str, args)) {
            argLexer->oprTable[i].count++;
            return 0;
        }
    }

    unsigned int flag = addOperator(&(argLexer->oprTable), &(argLexer->oprCount), createOperator(args, 1));
    if(!flag) {
        return 1;       //  Operator was created
    }
    return flag;
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




unsigned int incOpdCount(struct Lexer *argLexer, const char *args) {
    for(int i = 0; i < argLexer->opdCount; i++) {
        if(!strcmp(argLexer->opdTable[i].str, args)) {
            argLexer->opdTable[i].count++;
            return 0;
        }
    }

    unsigned int flag = addOperand(&(argLexer->opdTable), &(argLexer->opdCount), createOperand(args, 1));
    if(!flag) {
        return 1;       //  Operand was created
    }
    return flag;
}




void escapeTill(struct Lexer *argLexer, const char ch) {
    char curr_ch = argLexer->buf[argLexer->pos + 1];

    while(curr_ch != ch) {
        argLexer->pos++;
        curr_ch = argLexer->buf[argLexer->pos];
    }

    argLexer->pos++;
}