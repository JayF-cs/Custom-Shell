#ifndef TOKEN_H
#define TOKEN_H

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

#endif
