#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.h"

token_t * expression(ast_t * node, token_t * token)
{
    while( token != NULL )
	{
	    if( strcmp(token->val, ")") == 0 )
		return token;
	    else
		if( strcmp(token->val, "(") == 0 )
		    {
			ast_t * list_expression = malloc(sizeof(ast_t));
			list_expression->list_expression = true;
			list_expression->val = malloc( strlen(node->val) + strlen("_SIBLING") + 1 );
			strcpy(list_expression->val, node->val);
			strcat(list_expression->val, "_SIBLING");
			#ifdef DEBUG
			printf("New list expression %s sibling of %s\n", list_expression->val, node->val);
			#endif
			node->next = list_expression;
			node = list_expression;
			token = expression(node, token->next);
		    }
		else
		    {
			ast_t * atomic_expression = malloc(sizeof(ast_t));
			atomic_expression->list_expression = false;
			atomic_expression->val = malloc( strlen(token->val) + 1 );
			strcpy(atomic_expression->val, token->val);
			atomic_expression->first_child = NULL;
			if( node->list_expression && node->first_child == NULL){
			    #ifdef DEBUG
			    printf("New atomic expression %s child of %s\n", atomic_expression->val, node->val);
			    #endif
			    node->first_child = atomic_expression;
			}
			else{
			    #ifdef DEBUG
			    printf("New atomic expression %s sibling of %s\n", atomic_expression->val, node->val);
			    #endif
			    node->next = atomic_expression;
			}
			node = atomic_expression;
		}

	    if( token == NULL ){
		printf("Error: Malformed expression\n");
		exit(EXIT_FAILURE);
	    }

	    token = token->next;
	}
    return token;
}

ast_t * ast(token_t * head_token)
{
    ast_t * ast = malloc(sizeof(ast_t));
    ast->val = "ROOT";
    ast->list_expression = true;
    ast->next = NULL;
    ast->first_child = NULL;
    token_t * result = expression(ast, head_token);
    return ast;
}
