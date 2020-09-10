typedef char String[11];

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "stacks.c"
#include "queue.c"
#include "tokenizer.c"
#include "infixToPostfix.c"
#include "evaluatePostFix.c"

int main()
{

    Stack *stack = NULL;
    Queue *queue = NULL;
    int x = 0;

    stack = malloc(sizeof(Stack));
    queue = malloc(sizeof(Queue));
    create_stack(stack);
    create_queue(queue);

    char input[258];
    String tokenized[256];
    //char *c;
    int i;

    while (x < 55)
    {

        fgets(input, 258, stdin);

        /* printf("TOKENIZED VALUE OF INPUT: ");

        for (i = 0; i < tokenizer(input, tokenized); i++)
        {
            printf("[%s]", tokenized[i]);
        }
*/
        printf("\nINFIX TO POSTFIX: ");

        infixToPostfix(stack, queue, tokenized, tokenizer(input, tokenized));

        for (i = 0; i < tokenizer(input, tokenized); i++)
        {
            printf("%s ", queue->S[i]);
        }

        printf("\nEVALUATE POSTFIX: ");

        evaluatePostfix(queue);

        while (!stack_empty(stack))
        {
            pop_stack(stack);
        }
        while (!queue_empty(queue))
        {
            dequeue(queue);
        }

        stack = NULL;
        queue = NULL;
        stack = realloc(stack, sizeof(Stack));
        queue = realloc(queue, sizeof(Queue));
        create_stack(stack);
        create_queue(queue);

        x++;
    }

    return 0;
}
