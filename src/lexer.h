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

unsigned int lexify(struct Lexer *);

unsigned int processWord(struct Lexer *);

unsigned int processNum(struct Lexer *);

unsigned int processStr(struct Lexer *);

unsigned int processOpr(struct Lexer *);

unsigned int isKeyword(const char *);

unsigned int isFunction(struct Lexer *, unsigned int);

void delLexer(struct Lexer *);

struct Operator* createOperator(const char *, unsigned int);

unsigned int addOperator(struct Operator **, unsigned int *, struct Operator *);

unsigned int incOprCount(struct Lexer *, const char *);

struct Operand* createOperand(const char *, unsigned int);

unsigned int addOperand(struct Operand **, unsigned int *, struct Operand *);

unsigned int incOpdCount(struct Lexer *, const char *);


void escapeTill(struct Lexer *, const char);

#endif