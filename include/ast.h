#ifndef AST_H_   /* Include guard */
#define AST_H_

#include "parser.h"
#include <stdbool.h>

#define SIBLING "_SIBLING"

typedef struct ast
{
    struct ast * first_child;
    struct ast * next;
    bool list_expression;
    char * val;
} ast_t;

token_t * expression(ast_t *, token_t *);
ast_t * ast(token_t *);

#endif // AST_H_
