#include "stacks.h"
void create_stack(Stack *stack){
    stack->cap = 256;
    stack->S = malloc(sizeof(char) * stack->cap);
    stack->top = 0;

}

void push_stack(Stack *stack, char item){
    
    stack->S[stack->top] = item;
    stack->top++;    
}

char top(Stack *stack){
    return stack->S[stack->top-1];
} 

char pop_stack(Stack *stack){
    char top1 = top(stack);
    stack->top--;    
    return top1;    
}


int stack_full(Stack *stack){
    return stack->top == stack->cap - 1;
}

int stack_empty(Stack *stack){
    return stack->top == 0;
}


