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
    /*
    char c; 
    queue = malloc(sizeof(Queue));
    create_queue(queue);
    printf("%d\n", queue_empty(queue));
    enqueue(queue, 'S');
    printf("%d\n", queue_full(queue));
    enqueue(queue, 'A');
    printf("%d\n", queue_full(queue)); 
    enqueue(queue, 'Q');
    printf("%d\n", queue_full(queue));
    c = dequeue(queue);
    printf("%c\n", c);
    printf("%c\n", queue_head(queue));
    c = dequeue(queue);
    printf("%c\n", queue_head(queue));
    printf("%d\n", queue_empty(queue));
    c = dequeue(queue);
    printf("%d\n", queue_empty(queue));
*/
    Stack *stack = NULL;
    Queue *queue = NULL;
    int x = 0;
    int j;
    stack = malloc(sizeof(Stack));
    queue = malloc(sizeof(Queue));
    create_stack(stack);
    create_queue(queue);

    char input[258];
    String tokenized[256];
    char *c;
    // char output[256];

    while (x <= 50)
    {

        fgets(input, 258, stdin);
        // input[strlen(input) - 1] = '\0';
        int i;

        printf("TOKENIZED VALUE OF INPUT: ");

        for (i = 0; i < tokenizer(input, tokenized); i++)
        {
            printf("[%s]", tokenized[i]);
        }

        printf("\nINFIX TO POSTFIX: ");

        infixToPostfix(stack, queue, tokenized, tokenizer(input, tokenized));
        // printf("**********%s**********\n", tokenized);

        for (i = 0; i < tokenizer(input, tokenized); i++)
        {
            printf("%s ", queue->S[i]);
        }

        printf("\nEVALUATE POSTFIX: ");

        evaluatePostfix(queue->S, tokenizer(input, tokenized));

        while (!stack_empty(stack))
        {
            c = pop_stack(stack);
        }
        while (!queue_empty(queue))
        {
            c = dequeue(queue);
        }
        printf("%s\n", stack->S[j]);
        stack = NULL;
        queue = NULL;
        stack = realloc(stack, sizeof(Stack));
        queue = realloc(queue, sizeof(Queue));
        create_stack(stack);
        create_queue(queue);
        x++;
        // if (scanf("%c", &c) == 'x')
        //     x = 50;
    }

    //    i = postFixEvaluation(queue, output);

    return 0;
}
