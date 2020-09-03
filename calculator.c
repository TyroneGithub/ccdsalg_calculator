#include <stdio.h>
#include <stdlib.h>
#include "stacks.c"
#include "queue.c"
#include "infixToPostfix.c"
#include "postfixEvaluation.c"

int main()
{
    /*
    Queue *queue = NULL;
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

    stack = malloc(sizeof(Stack));
    create_stack(stack);

    Queue *queue = NULL;
    queue = malloc(sizeof(Queue));
    create_queue(queue); 

 
    // push_stack(stack, 'A');
    // push_stack(stack, 'B');
    // push_stack(stack, 'C');
    // c = pop_stack(stack);
    // printf("%c", c);
    // printf("%c", top(stack));
    char input[256];
    char output[256];
    int i;
    fgets(input, 256, stdin);

    infixToPostfix(stack, input, output);
    printf("Answer: [%s]\n", output);

    i = postFixEvaluation(queue, output);


    return 0;
}
