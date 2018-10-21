#ifndef CUSTOM_LEXER
#define CUSTOM_LEXER

struct Operator {
    const char *str;
    unsigned int count;
};

struct Operand {
    const char *str;
    unsigned int count;
};

struct Lexer {
    const char *buf;
    unsigned int pos;
    unsigned int buflen;

    unsigned int oprCount;
    struct Operator *oprTable;

    unsigned int opdCount;
    struct Operand *opdTable;
};


unsigned int initLexer(struct Lexer *, const char *);

unsigned int readBufFromFile(struct Lexer *, const char *);

unsigned int parseCode(struct Lexer *);

unsigned int processWord(struct Lexer *);

unsigned int processNum(struct Lexer *);

unsigned int isOperator(struct Lexer *, const char *);

unsigned int isVariable(struct Lexer *, const char *);

unsigned int isKeyword(struct Lexer *, const char *);

unsigned int isFunction(struct Lexer *, const char *);

void delLexer(struct Lexer *);

#endif