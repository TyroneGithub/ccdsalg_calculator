typedef char String[11];

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stacks.c"
#include "queue.c"
#include "tokenizer.c"
#include "infixToPostfix.c"

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

    stack = malloc(sizeof(Stack));
    queue = malloc(sizeof(Queue));
    create_stack(stack);
    create_queue(queue);

    char input[256];
    String tokenized[256];
    // char output[256];

    fgets(input, 256, stdin);

    int i;

    printf("TOKENIZED VALUE OF INPUT: ");
    for (i = 0; i < tokenizer(input, tokenized); i++)
    {
        printf("[%s]", tokenized[i]);
    }

    printf("\nINFIX TO POSTFIX: ");

    infixToPostfix(stack, queue, tokenized, tokenizer(input, tokenized));

    for (i = 0; i < tokenizer(input, tokenized); i++)
    {
        printf("%s ", queue->S[i]);
    }

    //    i = postFixEvaluation(queue, output);

    return 0;
}
