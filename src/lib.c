#include <stdlib.h>
#include "lib.h"

unsigned int strContains(const char *str, const char ch) {
    unsigned int occur = 0;

    for(const char *ptr = str; *ptr; ptr++){
        if(*ptr == ch) {
            occur++;
        }
    }

    return occur;
}

const char* substring(const char *str, unsigned int start, unsigned int end) {
    unsigned int len = end - start + 1;
    char *ptr = (char *)malloc(sizeof(char) * len);

    if(ptr) {
        unsigned int i;
        
        for(i = 0; i < len; i++) {
            *(ptr + i) = *(str + start + i);
        }

        *(ptr + i) = '\0';
    }

    return (const char *)ptr;
}

unsigned int _isAlpha(const char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

unsigned int _isDigit(const char ch) {
    return (ch >= '0' && ch <= '9');
}
