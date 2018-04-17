#ifndef PARSER_H_   /* Include guard */
#define PARSER_H_

typedef struct token
{
    char * val;
    struct token * next;
} token_t;

token_t * tokenize(char *);
int free_tokens(token_t *);

#endif // PARSER_H_
