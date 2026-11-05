#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"


token_list* lex(char* input);
void add_token(token_list* l, token_t* t);
token_t* create_token(tokenType type, const char* val, int len);

#endif
