#include <stdlib.h>
#include "token.h"
#include "utils.h"

void free_list(token_list* tl)
{
    token_t* t = tl->start;
    
    while(t != NULL)
    {
        token_t* temp = t;
        t = t->next;
        free_token(temp);
    }

    free(tl);
}

void free_token(token_t* t)
{
    free(t->val);
    free(t);
}
