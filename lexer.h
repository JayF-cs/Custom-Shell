#ifndef LEXER_H
#define LEXER_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef enum{
    STRING,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    APPEND,
    END,
} tokenType;

typedef struct token_t {
    tokenType type;
    char* val;
    int len;
    struct token_t* next;
} token_t;

typedef struct token_list{
    token_t* start;
    token_t* end;
} token_list;

token_list* lex(char* input);
void add_token(token_list* l, token_t* t);
token_t* create_token(tokenType type, const char* val, int len);

#endif
