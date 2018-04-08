#include <stdio.h>
#include "parser.h"

int show_tokens(token_t * tokens)
{
    int index = 1;
    while(tokens != NULL){
	printf("%d: %s\n", index, tokens->val);
	tokens = tokens->next;
	index += 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    token_t* tokens = tokenize(argv[1]);
    show_tokens(tokens);
    return 0;
}
