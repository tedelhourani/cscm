#include <stdio.h>
#include "parser.h"
#include "ast.h"

int tabs(char count)
{
    for(char i = 0; i < count; i++)
	printf("\t");
}


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

int show_ast(ast_t * ast, char depth)
{
    tabs(depth);
    printf("%s\n", ast->val);
    if( ast->list_expression )
	if( ast->first_child != NULL )
	    show_ast(ast->first_child, depth+1);
    if( ast->next != NULL )
	show_ast(ast->next, depth);
    return 0;
}

int main(int argc, char **argv)
{
    token_t* tokens = tokenize(argv[1]);
    //show_tokens(tokens);

    ast_t * abstract_syntax_tree = ast(tokens);

    printf("%p\n\n", abstract_syntax_tree);
    show_ast(abstract_syntax_tree,0);
    
    free_tokens(tokens);
    tokens = NULL;
    return 0;
}
