#include "lexer.h"

//Seperate the tokens in individual tokens that can be indexed through

token_t* create_token(tokenType type, const char* val, int len)
{
    token_t* tok = malloc(sizeof(token_t));
    tok->val = malloc(len + 1);
    strcpy(tok->val, val);
    tok->val[len] = '\0';
    tok->type = type;
    tok->len = len;
    tok->next = NULL;
    return tok;
}

void add_token(token_list* l, token_t* t)
{
    if(NULL == l->start && NULL == l->end)
    {
        l->start = t;
        l->end = t;
    }
    else
    {
        l->end->next = t;
        l->end = t;
    }
}

token_list* lex(char *input)
{
    token_list* tokens = malloc(sizeof(token_list));
    tokens->start = NULL;
    tokens->end = NULL;

    int i = 0;

    while(input[i] != '\0')
    {
        switch (input[i])
        {
            case ' ':
            case '\t':
            case '\n':
                i++;
                break;
            case '|':
            {
                token_t* token = create_token(PIPE, "|", 1);
                add_token(tokens, token);
                i++;
                break;
            }
            case '>':
            {
                if (input[i + 1] == '>')
                {
                    token_t* token = create_token(APPEND, ">>", 2);
                    add_token(tokens, token);
                    i+=2;
                }
                else
                {
                    token_t* token = create_token(REDIRECT_OUT, ">", 1);
                    add_token(tokens, token);
                    i++;
                }
                break;
            }
            case '<':
            {
                token_t* token = create_token(REDIRECT_IN, "<", 1);
                add_token(tokens, token);
                i++;
                break;
            }
            case '\"':
            {
                int start = i;
                while(input[++i] != '\"' && input[i] != '\0')
                {
                    i++;
                }
                //Count might be wrong value to pass in here might be off by one
                token_t* token = create_token(STRING, input + start, i - start);
                add_token(tokens, token);
                break;
            }
            default:
            {
                char* buff = malloc(strlen(input + i) + 1);
                int n = 0;
                while('\0' != input[i] && NULL == strchr(" \t\n|<>", input[i]))
                {
                    if(input[i] == '\"')
                    {
                        i++;
                        while ('\"' != input[i] && '\0' != input[i])
                            buff[n++] = input[i++];
                        if('\"' == input[i]) i++;
                    }
                    else
                    {
                        buff[n++] = input[i++];
                    }
                }
                token_t* token = create_token(STRING, buff, n);
                add_token(tokens, token);
                free(buff);
                break;
            }
        }
    }
    return tokens;
}
