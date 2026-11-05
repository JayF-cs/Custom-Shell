#include <stdio.h>
#include "lexer.h"
#include "token.h"
#include "utils.h"

#define READ 0
#define WRITE 1

static const char *type_name(tokenType t)
{
    switch (t)
    {
        case STRING:       return "STRING";
        case PIPE:         return "PIPE";
        case REDIRECT_IN:  return "REDIRECT_IN";
        case REDIRECT_OUT: return "REDIRECT_OUT";
        case APPEND:       return "APPEND";
        case END:          return "END";
    }
    return "?";
}

static void test(char *input)
{
    printf("input: [%s]\n", input);
    token_list *l = lex(input);
    for (token_t *t = l->start; t != NULL; t = t->next)
        printf("  %-12s len=%d  [%s]\n", type_name(t->type), t->len, t->val);
    printf("\n");
    free_list(l);
}


int main(int argc, char **argv)
{
    test("");
    test("ls");
    test("ls -l");
    test("   ls    -l   ");
    test("ls|wc");
    test("ls | wc -l");
    test("cat < in.txt");
    test("echo hi > out.txt");
    test("echo hi >> out.txt");
    test("echo a\"b c\"d");
    test("echo \"a|b\"");
    test("echo \"hello world\"");
    test("echo \"\"");
    test("echo \"unterminated");
    test("cat<in|grep x>>out");
    return 0;

    return 0;

    do{
        printf("> ");

    }while(1);
}
