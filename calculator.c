#include <stdio.h>
#include <stdlib.h>
#include "stacks.c"




int main(){

    Stack *stack = NULL;
    char c;
    stack = malloc(sizeof(Stack));
    create_stack(stack);
    push_stack(stack, 'A');
    push_stack(stack, 'B');
    push_stack(stack, 'C');
    c = pop_stack(stack);
    printf("%c", c);
    printf("%c", top(stack));
    return 0;
}



