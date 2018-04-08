#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "parser.h"

token_t * tokenize(char * input)
{
    token_t * head_token = NULL;
    token_t * tail_token;
    token_t * next_token;
    
    int input_length = strlen(input);
    int index = 0;
    int left = index;
    bool first_token = true;

    if(!input_length)
	return head_token;
    
    do
	{
	    if(isspace(input[index]) ||
	       input[index] == '('   ||
	       input[index] == ')'   ||	     
	       input[index] == '\0')
		{
                    int size = index-left;

		    if(!size)
			{
			    if(input[index] == '(' ||
			       input[index] == ')')
				{
				    next_token = malloc(sizeof(token_t*));
				    next_token->val = malloc(sizeof(char) * 2);
				    memcpy(next_token->val, &input[left], 1);
				    next_token->val[1] = '\0';
				    next_token->next = NULL;
				}
			    else
				{
				    index++;
				    left++;
				    continue;
				}
			}
		    else
			{
			    next_token = malloc(sizeof(token_t*));
			    next_token->val = malloc(sizeof(char) * (size+1));
			    memcpy(next_token->val, &input[left], size);
			    next_token->val[size] = '\0';
			    next_token->next = NULL;
			}

		    if(first_token)
			{
			    tail_token = next_token;
			    head_token = next_token;
			    first_token = false;
			}
		    else
			{
			    tail_token->next = next_token;
			    tail_token = next_token;
			}

		    if(size &&
		       (input[index]==')' || input[index]=='('))
			{
			    left = index;
			    continue;
			}
		    else
			left = index + 1;
		}

	    index += 1;
	} 
    while(index < input_length + 1);
    
    return head_token;
}

