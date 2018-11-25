/**
 * Test Id: 3
 * Description: Checking the result of Halstead Metrics
 * */

#include <stdio.h>
#include "../src/lexer.h"
#include "../src/halstead.h"

int main() {
    unsigned int oprCount, opdCount, oprOccur, opdOccur;
    struct Lexer clexer;

    initLexer(&clexer, "subject3.c");

    lexify(&clexer);

    oprCount = opdCount = oprOccur = opdOccur = 0;

    for(int i = 0; i < clexer.oprCount; i++) {
        oprOccur += clexer.oprTable[i].count;
        if(clexer.oprTable[i].count)
            oprCount++;
    }

    for(int i = 0; i < clexer.opdCount; i++) {
        opdOccur += clexer.opdTable[i].count;
        if(clexer.opdTable[i].count)
            opdCount++;
    }

    delLexer(&clexer);

    struct HalsteadMetric metric = getHalsteadMetrics(oprCount, opdCount, oprOccur, opdOccur);
    char *opStr = "Distinct Operator Count: %d\n \
    Distinct Operand Count: %d\n \
    Total Occurences of Operators: %d\n \
    Total Occurences of Operands: %d\n\n \
    Program Length: %d\n \
    Program Vocabulary: %d\n \
    Language Level: %f\n \
    Program Volume: %f\n \
    Program Difficulty: %f\n \
    Programming Effort: %f\n \
    Programming Time: %f\n";
    
    printf(opStr, 
        oprCount,
        opdCount,
        oprOccur,
        opdOccur,

        metric.progLen,
        metric.progVoc,
        metric.langLevel,
        metric.progVol,
        metric.progDiff,
        metric.progEff,
        metric.progTime
    );

    return 0;
}